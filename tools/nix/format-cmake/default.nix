{ stdenv, fetchFromGitHub }:
stdenv.mkDerivation {
  name = "format-cmake";
  src = fetchFromGitHub {
    owner = "TheLartians";
    repo = "Format.cmake";
    rev = "v1.7.3";
    hash = "sha256-fymComFJfZCSAKI4vKjY2yeT7n7S3RGZpOkBiP/IKOI=";
  };

  dontConfigure = true;
  dontBuild = true;

  installPhase = ''
    runHook preInstall
    install -Dm644 CMakeLists.txt $out/cmake/Format.cmake
    install -Dm644 cmake-format.cmake $out/cmake/cmake-format.cmake
    install -Dm644 git-clang-format.py $out/cmake/git-clang-format.py
    runHook postInstall
  '';
}
