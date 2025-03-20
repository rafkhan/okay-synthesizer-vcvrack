export ARCHFLAGS="-arch x86_64"
export MACOSX_DEPLOYMENT_TARGET=10.9
make clean
rm -r build
make install CROSS_COMPILE=x86_64-apple-darwin ARCH=x86_64 ARCHFLAGS="-arch x86_64"