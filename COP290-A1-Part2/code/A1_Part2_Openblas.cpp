#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include<pthread.h>
#include<cblas.h>
#include"helper.h"
#include"Pthread_Helper.h"
using namespace std;
using namespace std::chrono;
bool error = false;
vector<vector<float>> Pthread_m1;
vector<vector<float>> Pthread_m2;
vector<vector<float>> Pthread_m3;
vector<vector<float>> Pthread_out;
int main(int argc, char** argv)
{  if(argc!=7){
      cout<<"Error : Give Six Inputs <part> <inputmatrix> <weightmatrix> <biasmatrix> <implemenation> <outputmatrix>"<<endl;
      return -1;
   }
   string part = argv[1];
   if(part != "fullyconnected"){
      cout<<"Error : Part has to be fullyconnect"<<endl;
      return -1;
   }
   string inputmatrix =  argv[2];
   string weightmatrix = argv[3];
   string biasmatrix = argv[4];
   string implemenation = argv[5];
   string outputmatrix = argv[6];
   auto start = high_resolution_clock::now();
   vector<vector<float>> m1 = GiveMatrix(inputmatrix) ;
   int a = m1[0].size();
   int b1 = m1.size();
   vector<vector<float>> m2 = GiveMatrix(weightmatrix) ;
   int b2 = m2[0].size();
   int c = m2.size();
   vector<vector<float>> m3 = GiveMatrix(biasmatrix) ;
   int x = m3[0].size();
   int y = m3.size();
   if(error){
      return -1;
   }
   if(b1!=b2){
      cout<<"No of Columns inputmatrix is not equal to No of Rows weightmatrix"<<endl;
      return -1;
   }
   if(x!=a or y!=c){
      cout<<"No of Columns And Rows outputmatrix is not equal to No of Columns And Rows biasmatrix"<<endl;
      return -1;
   }
   int b = b1;
   if(implemenation == "simple"){
      vector<vector<float>> out = GiveOutputMatrix(m1,m2,m3,a,b,c);
      MakeMatrix(out,a,c,outputmatrix);
   }
   else if(implemenation == "openblas"){
      double *d1 = GiveBlasMatrix(m1,a,b);
      double *d2 = GiveBlasMatrix(m2,b,c);
      double *d3 = GiveBlasMatrix(m3,a,c);
      cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, a, c, b, 1.0, d1, b, d2, c, 1.0, d3, c);
      MakeBlasMatrix(d3,a,c,outputmatrix);
    
   }
   else if(implemenation ==  "mkl"){
      cout<<"Error : for mkl implemenation use yourcode_Mkl.out"<<endl;
      return -1;
   }
   else if(implemenation == "pthread"){
      Pthread_m1 = m1;
      Pthread_m2 = m2;
      Pthread_m3 = m3 ;
      vector<vector<float>> out( c,vector<float> (a, 0)); 
      Pthread_out = out;
      Pthread_GiveOutputMatrix(a,b,c);
      MakeMatrix(Pthread_out,a,c,outputmatrix);
   }
   else{
      cout<<"Error : implemenation  can only be openblas, mkl and pthread"<<endl;
      return -1;
   }
   auto stop = high_resolution_clock::now();

   auto duration = duration_cast<microseconds>(stop - start);
   float time = duration.count()/1000.00;
   cout << "Time taken by function: "
         << time <<  " milliseconds" << endl;
   string outmat = "../Time_Output/"+implemenation+"/"+implemenation+to_string(a)+".txt";
   ofstream MyFile(outmat, std::ios_base::app); 
   MyFile<<time<<endl;
   return  0;
}
