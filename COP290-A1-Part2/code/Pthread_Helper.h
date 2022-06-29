#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip> 
#include<time.h>
#include<unistd.h>
using namespace std;
extern bool error;
extern vector<vector<float>> Pthread_m1;
extern vector<vector<float>> Pthread_m2;
extern vector<vector<float>> Pthread_m3;
extern vector<vector<float>> Pthread_out;
int count = 0;
bool pthr = true;
int Pthread_a,Pthread_b,Pthread_c;
void *Calculate_Pthread(void * arg){
   int i = count++;
   if(i>=Pthread_c){
      pthr = false;
      return NULL;
   }
   float sum = 0;
   for(int j = 0; j < Pthread_a; j++) {
      sum = Pthread_m3[i][j];
      for (int k = 0; k < Pthread_b; k++) {
         sum += Pthread_m1[k][j] * Pthread_m2[i][k];
      }
      Pthread_out[i][j] = sum ;
   }
   return NULL;
}
void Pthread_GiveOutputMatrix(int a,int b,int c){ 
   Pthread_a = a;
   Pthread_b = b;
   Pthread_c = c;
   int MAX_THREAD = c;
   pthread_t threads[MAX_THREAD];
   int n = MAX_THREAD;
   int m = n-1;
   while(pthr){
      for(int i = 0; i < n; i++) {
         pthread_create(&threads[i], NULL, Calculate_Pthread ,NULL);
         if(!pthr){
            m = i ;
            break ;
         }
      }
      for(int i = 0; i <=m; i++){
         pthread_join(threads[i], NULL);
      }
   }
   return ;
}
double* GiveBlasMatrix(vector<vector<float>> m,int a,int b){
   double *d = new double[a*b]; 
   for(int i = 0; i < b; i++){
      for(int j = 0; j < a; j++){

         d[i+j*b] = m[i][j];
      }
   }
   return d;
}
void MakeBlasMatrix(double* d,int a,int b,string outputmatrix){
   ofstream MyFile(outputmatrix);
   MyFile<<b<<endl;
   MyFile<<a<<endl;
   for(int i = 0;i<b;i++){
      for(int j = 0;j<a;j++){
         MyFile<<d[i+j*b]<<endl;
      }
   }
   MyFile.close();
   return ;
}
