COMPILER_FLAGS=-fopenmp -lmkl_intel_lp64 -lmkl_core -lmkl_gnu_thread -lpthread -lm -ldl
# COMPILER_FLAGS=-fopenmp -lpthread -lm -ldl

# On linux
MKL_LIB_DIR = /opt/intel/compilers_and_libraries/linux/mkl/lib/intel64
MKL_INCLUDE_DIR = /opt/intel/compilers_and_libraries/linux/mkl/include

# On WSL
#DIR=/home/shade/code/github/COP290_A1_Part3
#MKL_LIB_DIR=/opt/intel/oneapi/mkl/2022.0.2/lib/intel64
#MKL_INCLUDE_DIR=/opt/intel/oneapi/mkl/2022.0.2/include

# Dynamic
# MKL_LIB_DIR=`pkg-config --libs mkl-dynamic-lp64-iomp`
# MKL_INCLUDE_DIR=`pkg-config --cflags mkl-dynamic-lp64-iomp`

all: yourcode.out

yourcode.out: main.cpp libAPI.so
	unset LD_LIBRARY_PATH
	g++ -L . -L $(MKL_LIB_DIR) -Wl,-rpath=. -Werror -o yourcode.out main.cpp -lAPI $(COMPILER_FLAGS)

libAPI.so: API.o
	g++ -shared -o libAPI.so API.o

API.o: API.cpp API.h dnn_weights.h
	g++ -I $(MKL_INCLUDE_DIR) -L $(MKL_LIB_DIR) -c -Werror -fpic API.cpp $(COMPILER_FLAGS)

clean:
	rm -f *.o *.so yourcode.out

