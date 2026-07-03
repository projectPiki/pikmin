<#
.SYNOPSIS
    Per-function reccmp diff for the sysCore thin slice, driven by symbol NAME (or address).

.DESCRIPTION
    Rebuilds the slice (via build_slice.ps1) and runs reccmp against the shipped GPIE01_01
    sysCore.dll.  Unlike calling reccmp-reccmp by hand, you name the function you care about
    with -Func and this resolves it to the correct annotation address for you: the thunk-
    resolved `real_va` column of config/GPIE01_01/win/sysCore_symbols.csv (the raw export `va`
    is an incremental-link jmp thunk and diffs to ~0%).

    -Func accepts either:
      * a case-insensitive substring matched against the mangled OR demangled name
        (e.g. "AyuStack::push", "push@AyuStack", "?pop@AyuStack"); or
      * a raw address (e.g. 0x1004a200) used as-is.
    If a name substring is ambiguous, the candidates are listed so you can narrow it.

    With no -Func, prints the whole-slice reccmp summary (like build_slice.ps1 -Compare).

.PARAMETER Func
    Symbol-name substring or hex address to diff.  Omit for the module summary.

.PARAMETER Develop
    Pass -Develop through to build_slice.ps1 (defines DEVELOP).

.PARAMETER Html
    Also write a searchable HTML report of the whole slice to build/win/slice/report.html.

.PARAMETER NoBuild
    Skip the rebuild; diff the DLL/PDB already in build/win/slice.

.EXAMPLE
    pwsh tools/win/diff_func.ps1 -Func AyuStack::push
.EXAMPLE
    pwsh tools/win/diff_func.ps1 -Func 0x1004a3a0 -NoBuild
.EXAMPLE
    pwsh tools/win/diff_func.ps1 -Html          # module summary + HTML report
#>
[CmdletBinding()]
param(
    [string]$Func,
    [switch]$Develop,
    [switch]$Html,
    [switch]$NoBuild
)

$ErrorActionPreference = "Stop"

$Root   = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
$OutDir = Join-Path $Root "build\win\slice"
$Dll    = Join-Path $OutDir "sysCoreSlice.dll"
$Pdb    = Join-Path $OutDir "sysCoreSlice.pdb"
$Orig   = Join-Path $Root "orig\GPIE01_01\files\sysCore.dll"
# Whole src/ tree so reccmp finds annotations at each symbol's real home (e.g. the gsys GLOBAL
# marker in src/sysDolphin/system.cpp), not just the compiled slice's TU. Scan-only; harmless.
$Src    = Join-Path $Root "src"
$Csv    = Join-Path $Root "config\GPIE01_01\win\sysCore_symbols.csv"

if (-not (Test-Path $Orig)) { throw "original not found: $Orig" }

# --- Resolve -Func to an annotation address (real_va) -------------------------------------
$Addr = $null
if ($Func) {
    if ($Func -match '^(0x)?[0-9a-fA-F]{6,}$') {
        $Addr = if ($Func.StartsWith("0x")) { $Func } else { "0x$Func" }
    }
    else {
        if (-not (Test-Path $Csv)) { throw "symbol CSV not found: $Csv (run pe_symbols.py)" }
        $needle = $Func.ToLower()
        $hits = Import-Csv $Csv | Where-Object {
            $_.mangled.ToLower().Contains($needle) -or $_.demangled.ToLower().Contains($needle)
        }
        if (-not $hits) {
            Write-Host "no symbol in sysCore matches '$Func'. Try a mangled fragment like 'push@AyuStack'." -ForegroundColor Yellow
            exit 1
        }
        # Collapse to unique real_va (a symbol can appear once; guard anyway).
        $hits = $hits | Sort-Object real_va -Unique
        if (@($hits).Count -gt 1) {
            Write-Host "'$Func' is ambiguous - $(@($hits).Count) matches:" -ForegroundColor Yellow
            $hits | ForEach-Object {
                Write-Host ("  {0}  {1}" -f $_.real_va, $_.demangled)
            }
            Write-Host "Narrow -Func (or pass one of the real_va addresses above)." -ForegroundColor Yellow
            exit 1
        }
        $Addr = $hits[0].real_va
        Write-Host ("==> {0}  ({1})" -f $hits[0].demangled, $Addr) -ForegroundColor Cyan
    }
}

# --- Build --------------------------------------------------------------------------------
if (-not $NoBuild) {
    $buildArgs = @()
    if ($Develop) { $buildArgs += "-Develop" }
    & (Join-Path $PSScriptRoot "build_slice.ps1") @buildArgs
    if ($LASTEXITCODE) { throw "build_slice.ps1 failed ($LASTEXITCODE)" }
}
if (-not (Test-Path $Dll)) { throw "slice DLL not built: $Dll (drop -NoBuild)" }

# --- Diff ---------------------------------------------------------------------------------
# reccmp writes progress to stderr; don't let that trip ErrorActionPreference = Stop.
$ErrorActionPreference = "Continue"
# reccmp prints a U+2728 sparkle on a 100% match; force UTF-8 so it doesn't crash the cp1252 console.
$env:PYTHONIOENCODING = "utf-8"

$reccmpArgs = @("--paths", $Orig, $Dll, $Pdb, $Src, "--no-color")
if ($Addr) { $reccmpArgs += @("--verbose", $Addr) }
if ($Html) { $reccmpArgs += @("--html", (Join-Path $OutDir "report.html")) }

& reccmp-reccmp @reccmpArgs

if ($Html) {
    Write-Host ("report: {0}" -f (Join-Path $OutDir "report.html")) -ForegroundColor Green
}
