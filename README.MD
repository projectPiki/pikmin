Pikmin  
[![Build Status]][actions] ![Code Progress] ![Data Progress] [![Discord Badge]][discord]
=============

[Build Status]: https://github.com/projectPiki/pikmin/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/projectPiki/pikmin/actions/workflows/build.yml
[Code Progress]: https://img.shields.io/endpoint?label=Code&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fpikmin%2FGPVE01%2Fdol%2F%3Fmode%3Dshield%26measure%3Dcode
[Data Progress]: https://img.shields.io/endpoint?label=Data&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fpikmin%2FGPVE01%2Fdol%2F%3Fmode%3Dshield%26measure%3Ddata
[Discord Badge]: https://img.shields.io/discord/933849697485983765?color=%237289DA&logo=discord&logoColor=%23FFFFFF
[discord]: https://discord.gg/CWKqYMePX8

A work-in-progress decompilation of Pikmin.

Supported versions:

- `DPIJ01`: PikiDemo / Jitsuen-you Sample
- `GPIJ01_01`: Japan (Rev 1)
- `GPIJ01_02`: Japan (Rev 2)
- `GPIE01_00`: USA (Rev 0)
- `GPIE01_01`: USA (Rev 1)
- `GPIP01_00`: Europe (Rev 0)

Index
-----

- [Dependencies](#dependencies)
  - [Windows](#windows)
  - [macOS](#macos)
  - [Linux](#linux)
- [Building](#building)
- [Diffing](#diffing)

Dependencies
------------

### Windows

On Windows, it's **highly recommended** to use native tooling. WSL or msys2 are **not** required.  
When running under WSL, [objdiff](#diffing) is unable to get filesystem notifications for automatic rebuilds.

- Install [Python](https://www.python.org/downloads/) and add it to `%PATH%`.
  - Also available from the [Windows Store](https://apps.microsoft.com/store/detail/python-311/9NRWMJP3717K).
- Download [ninja](https://github.com/ninja-build/ninja/releases) and add it to `%PATH%`.
  - Quick install via pip: `pip install ninja`

### macOS

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages):

  ```sh
  brew install ninja
  ```

- Install [wine-crossover](https://github.com/Gcenx/homebrew-wine):

  ```sh
  brew install --cask --no-quarantine gcenx/wine/wine-crossover
  ```

After OS upgrades, if macOS complains about `Wine Crossover.app` being unverified, you can unquarantine it using:

```sh
sudo xattr -rd com.apple.quarantine '/Applications/Wine Crossover.app'
```

### Linux

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages).
- For non-x86(_64) platforms: Install wine from your package manager.
  - For x86(_64), [wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

Building
--------

- Clone the repository:

  ```sh
  git clone https://github.com/projectPiki/pikmin.git
  ```

- Using [Dolphin Emulator](https://dolphin-emu.org/), extract your game's system data to `orig/GPIE01_01`. (Or the appropriate version folder.)
  - Right-click the game in Dolphin's game list and select `Properties`.
  - Go to the `Filesystem` tab and right-click `Disc` -> `Extract System Data`.
![Dolphin filesystem extract](assets/dolphin-extract.png)
  - After extraction, the following file should exist: `orig/GPIE01_01/sys/main.dol`.
- Configure:

  ```sh
  python configure.py
  ```

  To use version other than `GPIE01_01`, add `--version`. Add `--help` to see all available options.
- Build:

  ```sh
  ninja
  ```

Diffing
-------

Once the initial build succeeds, an `objdiff.json` should exist in the project root.

Download the latest release from [encounter/objdiff](https://github.com/encounter/objdiff). Under project settings, set `Project directory`. The configuration should be loaded automatically.

Select an object from the left sidebar to begin diffing. Changes to the project will rebuild automatically: changes to source files, headers, `configure.py`, `splits.txt` or `symbols.txt`.

![objdiff project configuration](assets/objdiff.png)
