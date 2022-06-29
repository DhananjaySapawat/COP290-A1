#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"helper.h"
using namespace std;
bool error = false;
int main(int argc, char** argv)
{  if(argc<2){
         cout<<"Error : Give Atleast One Input <part>"<<endl;
         return -1;
   }
   string part = argv[1];
   if(part == "fullyconnected"){
      if(argc!=6){
         cout<<"Error : Give Five Inputs <part> <inputmatrix> <weightmatrix> <biasmatrix> <outputmatrix>"<<endl;
         return -1;
      }
      string inputmatrix =  argv[2];
      string weightmatrix = argv[3];
      string biasmatrix = argv[4];
      string outputmatrix = argv[5];
      vector<vector<float>> m1 = GiveMatrix(inputmatrix) ;
      float a = m1[0].size();
      float b1 = m1.size();
      vector<vector<float>> m2 = GiveMatrix(weightmatrix) ;
      float b2 = m2[0].size();
      float c = m2.size();
      vector<vector<float>> m3 = GiveMatrix(biasmatrix) ;
      float x = m3[0].size();
      float y = m3.size();
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
      float b = b1;
      vector<vector<float>> out = GiveOutputMatrix(m1,m2,m3,a,b,c);
      MakeMatrix(out,a,c,outputmatrix);
   }
   else if(part == "activation"){
      if(argc!=5){
         cout<<"Error : Give Four Inputs"<<endl;
         return -1;
      }
      string type = argv[2];
      string inputmatrix =  argv[3];
      string outputmatrix = argv[4];
      vector<vector<float>> m = GiveMatrix(inputmatrix) ;
      float a = m[0].size();
      float b = m.size();
      if(error){
         return -1;
      }
      if(type == "relu"){
         Make_relu(m,a,b,outputmatrix);
      }
      else if(type == "tanh"){
         Make_tanh(m,a,b,outputmatrix);
      }
      else{
         cout<<"Error : type can either be tanh or relu"<<endl;
         return -1;
      }
   }
   else if(part == "pooling"){
      if(argc!=6){
      cout<<"Error : Give Four Inputs"<<endl;
      return -1;
      }
      string type = argv[2];
      string inputmatrix = argv[3];
      string stride = argv[4];
      string outputmatrix = argv[5];
      if(!Is_Int(&stride[0],stride.size())){
         cout<<"Error: stride has to be integer"<<endl;
         return -1;
      }
      float s = stoi(stride);
      vector<vector<float>> m = GiveMatrix(inputmatrix) ;
      float a = m[0].size();
      float b = m.size();
      if(error){
         return -1;
       }
      if(a!=b){
         cout<<"Error : Matrix is not a square matrix"<<endl;
         return -1;
      }
      if((int)a%(int)s!=0){
         cout<<"Error : Matrix Dimension is not multiple of stride"<<endl;
         return -1;
      }
      if(type == "max"){
         Make_maxpooling(m,a,s,outputmatrix);
      }
      else if(type == "average"){
         Make_averagepooling(m,a,s,outputmatrix);
      }
      else{
         cout<<"Error : type can either be max or average"<<endl;
         return -1;
      }
   }
   else if(part == "probability"){
      if(argc!= 5){
         cout<<"Error : Give Four Inputs"<<endl;
         return -1;
      }
      string type = argv[2];
      string inputvector =  argv[3];
      string outputvector = argv[4];
      vector<float> v = GiveVector(inputvector) ;
      float a = v.size();
      if(error){
         return -1;
      }
      if(type == "softmax"){
         Make_softmax(v,a,outputvector);
      }
      else if(type == "sigmoid"){
         Make_sigmoid(v,a,outputvector);
      }
      else{
         cout<<"Error : type can either be softmax or sigmoid"<<endl;
         return -1;
      }
   }
   else{
      cout<<"Error : part can only be fullyconnect , activation, pooling and probability"<<endl;
      return -1;
   }
   return  0;
}