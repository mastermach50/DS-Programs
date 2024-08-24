# shell.nix for C/C++ Environment
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "C";
  packages = with pkgs; [

    libgcc
    clang-tools

  ];
}
