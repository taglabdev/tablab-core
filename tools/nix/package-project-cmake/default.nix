{ stdenv, fetchFromGitHub }:
stdenv.mkDerivation {
  name = "package-project-cmake";
  src = fetchFromGitHub {
    owner = "TheLartians";
    repo = "PackageProject.cmake";
    rev = "v1.8.0";
    hash = "sha256-4rSp+HFZXBeU2hZZgD0ySq0CXHhWRQM2029HD00UzV4=";
  };

  dontConfigure = true;
  dontBuild = true;

  installPhase = ''
    runHook preInstall
    install -Dm644 CMakeLists.txt $out/cmake/PackageProject.cmake
    install -Dm644 Config.cmake.in $out/cmake/Config.cmake.in
    install -Dm644 version.h.in $out/cmake/version.h.in
    runHook postInstall
  '';
}
