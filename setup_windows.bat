mkdir build
cd zlib-ng
mkdir build
cd build
cmake ..
make -j$(nproc)
mv libz-ng.a ../../build
cd ..
cd .. 
cmake . 
make 
mv libspng_lib.a build/