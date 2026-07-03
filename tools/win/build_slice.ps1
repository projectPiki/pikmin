<#
.SYNOPSIS
    Build the sysCore "thin slice" (ayuStack.cpp) with the VC6 toolchain and, optionally, run reccmp
    against the shipped GPIE01_01 sysCore.dll.

.DESCRIPTION
    This is the reproducible recipe that proved the VC6 -> PDB -> reccmp matching loop end-to-end.
    It compiles a *minimal* DLL (ayuStack.cpp + slice link stubs), producing a PDB, then compares its
    functions to the original.  It deliberately does NOT build the full sysCore.dll yet.

    Driven from PowerShell rather than an MSYS/bash shell because MSYS path-mangles `cl`/`link` flags
    (turning `/nologo` into `C:/Program Files/Git/nologo`).  VC6 predates CMake's supported compilers
    and modern CMake refuses MSVC 6.0, so the thin slice uses direct compiler invocation; a CMake/NMake
    driver for the full module is a later step.

    Confirmed-from-the-binary flags (see the win-decomp-facts memory): /MDd /Od /GX /GR- /GZ /ZI,
    linked /dll /debug /incremental:yes /subsystem:windows.  `/GZ` (VC6 debug stack checks: 0xCC frame
    fill + __chkesp) and `/ZI` (Edit & Continue: padded frame + push ebx/esi/edi) are both verified
    present via reccmp diffs.

.PARAMETER Develop
    Also define DEVELOP (PRINT/ERROR become real _Print/_Error calls).  The original debug build was
    almost certainly DEVELOP (it embeds assert strings), though for the AyuStack functions the diff is
    currently insensitive to it.

.PARAMETER Compare
    After building, run reccmp-reccmp against orig/GPIE01_01/files/sysCore.dll and print the summary.
#>
[CmdletBinding()]
param(
    [switch]$Develop,
    [switch]$Compare,
    [switch]$PlainPdb
)

$ErrorActionPreference = "Stop"

# Repo root = two levels up from this script (tools/win/).
$Root = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
$VC6  = Join-Path $Root "tools\vc6"
if (-not (Test-Path (Join-Path $VC6 "bin\cl.exe"))) {
    throw "VC6 toolchain not found at $VC6 (see the win-decomp-vc6-setup memory to assemble it)."
}

$env:INCLUDE = Join-Path $VC6 "include"
$env:LIB     = Join-Path $VC6 "lib"
$env:PATH    = (Join-Path $VC6 "bin") + ";" + $env:PATH

$Inc    = Join-Path $Root "include"
$Ayu    = Join-Path $Root "src\sysCommon\ayuStack.cpp"
$Stub   = Join-Path $Root "tools\win\slice\slice_stubs.cpp"
$OutDir = Join-Path $Root "build\win\slice"
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null

# /ZI = program database for Edit & Continue (the VC6 IDE "Debug" default, and CONFIRMED for the
# originals: padded fixed frame + unconditional push ebx/esi/edi so code can be hot-patched -- it
# took AyuStack::{create,reset,pop} to exact matches and the slice 54.6%->86%).  -PlainPdb swaps
# back to /Zi for A/B comparison.
$dbg = if ($PlainPdb) { "/Zi" } else { "/ZI" }
$cflags = @("/nologo", "/c", "/MDd", "/Od", "/GX", "/GR-", "/GZ", $dbg, "/W3",
            "/D", "WIN32", "/D", "_DEBUG", "/D", "_WINDOWS", "/D", "_USRDLL", "/D", "_MBCS",
            "/D", "VERSION_GPIE01_01")
if ($Develop) { $cflags += @("/D", "DEVELOP") }

Push-Location $OutDir
try {
    Write-Host "==> compiling ayuStack.cpp" -ForegroundColor Cyan
    & cl.exe @cflags "/Fdayu_c.pdb" "/FoayuStack.obj" "/I" $Inc $Ayu
    if ($LASTEXITCODE) { throw "cl failed on ayuStack.cpp ($LASTEXITCODE)" }

    Write-Host "==> compiling slice_stubs.cpp" -ForegroundColor Cyan
    & cl.exe @cflags "/Fdstub_c.pdb" "/Foslice_stubs.obj" "/I" $Inc $Stub
    if ($LASTEXITCODE) { throw "cl failed on slice_stubs.cpp ($LASTEXITCODE)" }

    Write-Host "==> linking sysCoreSlice.dll" -ForegroundColor Cyan
    & link.exe /nologo /dll /debug /incremental:yes /subsystem:windows `
        /out:sysCoreSlice.dll ayuStack.obj slice_stubs.obj msvcrtd.lib kernel32.lib
    if ($LASTEXITCODE) { throw "link failed ($LASTEXITCODE)" }

    Write-Host "built: $OutDir\sysCoreSlice.dll (+ .pdb)" -ForegroundColor Green
}
finally { Pop-Location }

if ($Compare) {
    $orig = Join-Path $Root "orig\GPIE01_01\files\sysCore.dll"
    if (-not (Test-Path $orig)) { throw "original not found: $orig" }
    Write-Host "==> reccmp" -ForegroundColor Cyan
    # reccmp writes progress to stderr; don't let that trip $ErrorActionPreference = Stop.
    $ErrorActionPreference = "Continue"
    # reccmp prints a U+2728 sparkle on a 100% match; force UTF-8 so it doesn't crash the cp1252 console.
    $env:PYTHONIOENCODING = "utf-8"
    # Source root = whole src/ so reccmp finds annotations at each symbol's real home (e.g. the
    # gsys GLOBAL marker in src/sysDolphin/system.cpp), not just the compiled slice's TU.
    & reccmp-reccmp --paths $orig `
        (Join-Path $OutDir "sysCoreSlice.dll") `
        (Join-Path $OutDir "sysCoreSlice.pdb") `
        (Join-Path $Root "src")
}
