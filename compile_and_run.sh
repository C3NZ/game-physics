export CC=gcc CXX=g++

if [ "$1" = "Release" ] || [ "$1" = "Debug" ]; then
    echo "Compiling a $1 build."
    CXX=g++ cmake \
        -DCMAKE_BUILD_TYPE="$1" \
        -DCMAKE_CXX_COMPILER=/usr/bin/g++ \
        -DDISTRIBUTION_BUILD=False \
            .
elif [ "$1" = "Dist" ]; then
    echo "Compiling a Distribution build."
    cmake 
        -DCMAKE_BUILD_TYPE="Release" \ 
        -DDISTRIBUTION_BUILD=True \
        -DCMAKE_CXX_COMPILER=/usr/bin/g++ \
            .
else
    echo "Incorrect build type passed."
    exit
fi

make -j 8
./"$1"/bin/sandbox
