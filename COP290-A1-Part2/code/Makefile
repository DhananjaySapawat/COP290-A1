COMPILER_FLAGS = -fopenmp -lmkl_intel_lp64 -lmkl_core -lmkl_gnu_thread -lpthread -lm -ldl

# On linux
MKL_LIB_DIR = /opt/intel/compilers_and_libraries/linux/mkl/lib/intel64
MKL_INCLUDE_DIR = /opt/intel/compilers_and_libraries/linux/mkl/include
# On WSL
# MKL_LIB_DIR = "/opt/intel/oneapi/mkl/2022.0.2/lib/intel64"
# MKL_INCLUDE_DIR = "/opt/intel/oneapi/mkl/2022.0.2/include"

OPENBLAS_LIB_DIR = /opt/OpenBLAS/lib
OPENBLAS_INCLUDE_DIR = /opt/OpenBLAS/include/ 

all:
	g++ -o yourcode.out A1_Part2_Openblas.cpp -I$(OPENBLAS_INCLUDE_DIR) -L$(OPENBLAS_LIB_DIR) -lopenblas -lpthread -lgfortran
	g++ -o yourcode_Mkl.out A1_Part2_Mkl.cpp -I$(MKL_INCLUDE_DIR) -L$(MKL_LIB_DIR) $(COMPILER_FLAGS) 
t:
	g++	-o	time	time.cpp
	