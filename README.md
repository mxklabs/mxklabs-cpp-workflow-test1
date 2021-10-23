# mxklabs-example-cpp-lib

A simple shared c++ library to demonstrate `mxklabs-pkgs`.

**NOTE**: This repository is set up for educational purposes and serves no useful purpose.

## Build with nix

1. Install nix (see instructions: [here](https://nixos.org/download.html#nix-quick-install))
2. Add the mxklabs-pkgs nix channel: (see instructions: [here](https://github.com/mxklabs/mxklabs-pkgs))
3. Install with the following command:
   ```
   nix-build '<mxklabs>' -A mxklabs-example-cpp-lib1
   ```

## Build outside of nix

This project can be configured, built and installed using a standard cmake workflow but, in terms of installing and managing dependencies outside of nix, you're on your own.
