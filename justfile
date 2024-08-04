# show commands
help:
    just -l

# enter nu dev shell
nu-develop:
    nix develop -c nu
alias dev := nu-develop

# generate debug project files
configure *ARGS:
    cmake -Bbuild -GNinja {{ ARGS }}
alias cfg := configure

# build debug project
build:
    cmake --build build
alias bld := build

# test debug project
test *ARGS:
    build/tests/taglab-core-tests {{ ARGS }}

# build and test the project
build-test *ARGS:
    just build test {{ ARGS }}
alias bt := build-test

# clean project
clean:
    cmake --build build --target clean

# remove all build artifacts
reset:
    rm -rf build

# show format diff
diff-format:
    cmake --build build --target format

# return error exit code if unformatted
check-format:
    cmake --build build --target check-format

# fix formatting
fix-format:
    cmake --build build --target fix-format
