with import <nixpkgs> { };

stdenv.mkDerivation rec {
  name = "pico-shell";


  buildInputs = [ clang python3 stdenv gcc-arm-embedded cmake gnumake];

  shellHook = ''
     # code ran when entering shell
     export PICO_SDK_PATH="/home/manank/data/C projects/pico-sdk"
     export SRC=$(pwd)
  '';
}

