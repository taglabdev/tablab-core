{ stdenv, fetchFromGitHub }:
stdenv.mkDerivation {
  name = "cmake-scripts";
  src = fetchFromGitHub {
    owner = "StableCoder";
    repo = "cmake-scripts";
    rev = "24.04.1";
    hash = "sha256-Aq9rxOHyX5gQaiXdUtKa3TKWweWzzg3MWZXAfJYUhJg=";
  };

  dontConfigure = true;
  dontBuild = true;

  installPhase = ''
    runHook preInstall
    install -Dm644 -t $out/cmake/cmake-scripts \
      afl-fuzzing.cmake \
      c++-standards.cmake \
      c-standards.cmake \
      code-coverage.cmake \
      compiler-options.cmake \
      dependency-graph.cmake \
      doxygen.cmake \
      formatting.cmake \
      glsl-shaders.cmake \
      link-time-optimization.cmake \
      prepare-catch.cmake \
      sanitizers.cmake \
      tools.cmake
    runHook postInstall
  '';
}
