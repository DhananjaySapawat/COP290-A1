#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "dnn_weights.h"
#include "/opt/intel/compilers_and_libraries/linux/mkl/include/mkl.h"

using namespace std;

typedef struct{
   int label;
   float prob;
}pred_t;

double * GiveAudioMatrix(string AudioSampleFile);
double relu(double x);
void ReluArray(double * m ,int n);
void SoftmaxArray(double * m ,int n);
pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred);
void Print_Csv_File(char* Audio,char* output , pred_t* pred);
