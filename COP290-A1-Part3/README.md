# COP290: A1-Subtask-3

## TEAM
Dhananjay Sapawat: 2019cs10345 <br>
Burouj Armgaan: 2021vsn9003

### NOTE
- Change the following in the `Makefile` according to the location of mkl installation in your system:
   - `MKL_LIB_DIR = /opt/intel/compilers_and_libraries/linux/mkl/lib/intel64`
   - `MKL_INCLUDE_DIR = /opt/intel/compilers_and_libraries/linux/mkl/include`

- In `API.h` please change `#include "/opt/intel/compilers_and_libraries/linux/mkl/include/mkl.h"` with `#include "<paht_to_mkl_include_dir>/mkl.h"`

### LIST OF FILES
- `Makefile` : compiles files and links them to produce `libAPI.so` and `yourcode.out`.

- `main.cpp` : Has the main() function for in it. Uses `libAPI.so` to generate output.

- `API.cpp` : Source code for `libAPI.so`. Contains functions of `libAPI.so`.

- `API.h` : Header file of `API.cpp`.

- `dnn_weights.h` : Contains the weights and biases of the neural net layers.

### USAGE OF INDIVIDUAL FILES
- `Makefile`

- `./yourcode.out [INPUT] [OUTPUT]` : Requires `Makefile` to be run beforehand.

### OPTIONS
- `[INPUT]` : path to file containing input audio feature vector.

- `[OUTPUT]` : path to file where output of the neural net should be written.
