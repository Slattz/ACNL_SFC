# ACNL Spotpass File Creator

ACNL Spotpass File Creator is a Proof of Concept application for creating Custom Spotpass Content for ACNL.

It currently supports creating Spotpass Content for Post Office Presents and Campground RVs.

## Requirements

1) CFW is required for using the files.
    * Spotpass files are generally signed by Nintendo, but CFW patches this.

2) A dump of the ARM9 Bootrom (`boot9.bin`) is also required in order to encrypt and decrypt these files.
    * This can be obtained either through GodMode9 or by holding `Start + Select + X` upon booting your 3DS. (The latter is only applicable to boot9strap users, though this is the majority anyways.)

    * The `boot9.bin` must be placed in the same folder as the application, or in `%appdata%\3ds\` on Windows or `$HOME/.3ds/` on macOS/Linux.

## Compiling

This app should be compiled using [Qt](https://www.qt.io/).

The releases are compiled using Qt 5.12.0 MinGW 64-bit. Milage may vary with other versions.

## How To Use

As this app is only a Proof of Concept, a full "How To Use" will not be provided.

* To use the outputted files with ACNL, I recommended using [Fiddler](https://www.telerik.com/download/fiddler) along with [SciresM's SSL Patch](https://github.com/SciresM/3DS-SSL-Patch) setup on your 3DS and also installing the `ClCertA.p12` on your PC. Then export it to a .cer and place it as `%userprofile%\Documents\Fiddler2\ClientCertificate.cer`.

* Then setup Fiddler as necessary and connect your 3DS to it's proxy. Then redirect file requests from ACNL to the local file on your PC.