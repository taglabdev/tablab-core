{
  description = "taglab project core library";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        version = "0.1.0";

        pkgs = import nixpkgs { inherit system; };
      in
      {
        packages.default = pkgs.stdenv.mkDerivation {
          pname = "taglab-core";
          inherit version;
          src = self;

          VERSION = version;
          CMAKE_MODULE_PATH = pkgs.lib.strings.concatStringsSep ";" [
            "${pkgs.callPackage ./tools/nix/package-project-cmake { }}/cmake"
            "${pkgs.callPackage ./tools/nix/format-cmake { }}/cmake"
            "${pkgs.callPackage ./tools/nix/cmake-scripts { }}/cmake"
          ];

          nativeBuildInputs = with pkgs; [
            cmake
            ninja
            just

            clang-tools
            cmake-format
          ];

          checkInputs = with pkgs; [ doctest ];

          configurePhase = ''
            runHook preConfigure
            just configure -DCMAKE_BUILD_TYPE=Release
            runHook postConfigure
          '';

          buildPhase = ''
            runHook preBuild
            just build
            runHook postBuild
          '';

          doCheck = true;
          checkPhase = ''
            runHook preCheck
            just test
            runHook postCheck
          '';
        };
      }
    );
}
