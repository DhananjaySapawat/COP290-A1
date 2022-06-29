#!/usr/bin/env python
import sys
matrix_shape = int(sys.argv[1])

import numpy as np
matrix = np.random.randn(matrix_shape, matrix_shape)
# matrix = np.arange(matrix_shape**2).reshape(matrix_shape, matrix_shape)

print(matrix_shape)
print(matrix_shape)
for col in range(0, matrix_shape):
    for row in range(0, matrix_shape):
        print(matrix[row][col])
