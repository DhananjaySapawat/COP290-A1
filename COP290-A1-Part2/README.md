# COP290: A1-Subtask-2

## TEAM
Dhananjay Sapawat: 2019cs10345 <br>
Burouj Armgaan: 2021vsn9003

### NOTE
MKL implementation needs to be run using `yourcode_Mkl.out`, not `yourcode.out`

### LIST OF FILES
- `Makefile` : compiles files and links them to produce `yourcode.out` and `yourcode_Mkl.out` executables. Requires openblas and mkl to be installed in the system.

- `A1_Part2_Openblas.cpp` : Has the main() function for the simple, pthread, and openblas implementation in it.

- `A1_Part2_Mkl.cpp` : Has the main() function for mkl implementation in it.

- `helper.h` : Contains the functions required for the "simple" implementation.

- `Pthread_Helper.h` : Contains the functions required for the "Pthread", "Openblas", and "mkl" implementation.

- `gen-matrices.py` : Creates square matrices filled with random data. Requires numpy to be installed on the system.

- `runtime.sh` : Runs `yourcode.out` and `yourcode_Mkl.out` 20 times for each type of implementation and writes the execution time of each run onto the console. Filepaths are hardcoded in to the script. If required, change the paths to suit your own needs. The script is very simple.

- `time.cpp` : Restructures the output of `runtime.sh` for use by `plot.gp`.

- `plot.gp` : Plots boxplots for the execution times of various implementations which are generated as the output of `runtime.sh`. The output of `runtime.sh` needs to be reshaped into tab-spaced data before being used by `plot.gp` Filepaths are hardcoded in to the script. If required, change the paths to suit your own needs. The script is very simple.

### USAGE OF INDIVIDUAL FILES
- `Makefile`

- `./yourcode.out fullyconnected [INPUT] [WEIGHT] [BIAS] [TYPE] [OUTPUT]` : Requires `Makefile` to be run beforehand.

- `./yourcode_Mkl.out fullyconnected [INPUT] [WEIGHT] [BIAS] mkl [OUTPUT]` : Requires `Makefile` to be run beforehand.

- `./gen-matrices.py [SQUARE_MATRIX_SIZE] > [OUTPUTFILE_PATH]`

- `./runtime.sh`

- `./time [SQUARE_MATRIX_SIZE]` : Requires `Makefile` to be run beforehand.

- `./plot.gp`

### OPTIONS

- `[BIAS]` : path to file containing bias matrix

- `[INPUT]` : path to file containing input matrix

- `[OUTPUT]` : path to file where output matrix should be written

- `[OUTPUTFILE_PATH]` : path to file where the random matrix will be written

- `[SQUARE_MATRIX_SIZE]` : Size of the square matrix to be generated.

- `[WEIGHT]` : path to file containing weight matrix

### FOLDER CONTENTS

- `A1_Subtask2/code/` : Contains the source code and executibles.

- `A1_Subtask2/data/` : Contains matrix files used by executibles and scripts.

- `A1_Subtask2/Output/` : Contains matrices output by `yourcode.out` & `yourcode_Mkl.out`.

- `A1_Subtask2/Plots/` : Contains box plots of different implementations of matrix multiplication over varying matrix sizes.

- `A1_Subtask2/Time/` : Files present in `A1_Subtask2/Time_Output/` are restructured to be used by `plot.gp` and stored in this folder.

- `A1_Subtask2/Time_Output/` : Contains subfolders, each of which contains files which are output by `runtime.sh`. These files store the execution times for different implementations.
