#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip> 
using namespace std;
extern bool error;
bool Is_Int(char *s,float n){
   n--;
   for(int i = 0;i<n;i++){
      if(!isdigit(s[i]) and s[i]!=' ' and s[i]!='.'){
           return false;
      }
   }
   if(stof(s) != stoi(s)){
      return false;
   }
   return true;
}
vector<vector<float>>GiveMatrix(string MatrixTxtFile){
   vector<vector<float>> z ={{0},{0}};
   fstream myfile;
   myfile.open(MatrixTxtFile,ios::in);
   if(!myfile.is_open()){
      cout<<"Error : "+MatrixTxtFile+" not opened"<<endl;
      error = true;
      return z;
   } 
   string in;
   if(!getline(myfile,in)){
      cout<<"Error : Cannot get input in "+MatrixTxtFile<<endl;
      error = true;
      return z;
   }
   string s1 = in ;
   if(!getline(myfile,in)){
      cout<<"Error : Cannot get input in "+MatrixTxtFile<<endl;
      error = true;
      return z;
   }
   string s2 = in;
   if(!Is_Int(&s1[0],s1.size()) or !Is_Int(&s2[0],s2.size())){
      cout<<"Error: "+MatrixTxtFile+" dimension has to be integer"<<endl;
      error = true;
      return z;
   }
   float b = stof(s1);
   float a = stof(s2);
   vector<vector<float>> m( b, vector<float> (a, 0));  
   for(int i = 0;i<b;i++){
      for(int j = 0;j<a;j++){
         if(!getline(myfile,in)){
            cout<<"Error : Cannot get input in "+ MatrixTxtFile<<endl;
            error = true;
            return z;
         }
         m[i][j] = stof(in);
      }
   }
   myfile.close();
   return m;
}
vector<float>GiveVector(string VectorTxtFile){
   vector<float> z ={0};
   fstream myfile;
   myfile.open(VectorTxtFile,ios::in);
   if(!myfile.is_open()){
      cout<<"Error : "+VectorTxtFile+" not opened"<<endl;
      error = true;
      return z;
   } 
   string in;
   if(!getline(myfile,in)){
      cout<<"Error : Cannot get input in "+VectorTxtFile<<endl;
      error = true;
      return z;
   }
   string s1 = in ;
   if(!Is_Int(&s1[0],s1.size())){
      cout<<"Error: "+VectorTxtFile+" dimension has to be integer"<<endl;
      error = true;
      return z;
   }
   float a = stof(s1);
   vector<float> v(a,0);  
   for(int i = 0;i<a;i++){
         if(!getline(myfile,in)){
            cout<<"Error : Cannot get input in "+ VectorTxtFile<<endl;
            error = true;
            return z;
         }
         v[i] = stof(in);
      }
   myfile.close();
   return v;
}

// 1st Part //

vector<vector<float>>GiveOutputMatrix(vector<vector<float>> m1,vector<vector<float>> m2,vector<vector<float>> m3,int a,int b,int c){
   vector<vector<float>> out( c,vector<float> (a, 0)); 
   for(int i = 0; i < c; i++) {
      for (int j = 0; j < a; j++) {
         out[i][j] = m3[i][j];
         for (int k = 0; k < b; k++) {
            out[i][j] += m1[k][j] * m2[i][k];
         }
      }
   }
   return out;
}
void MakeMatrix(vector<vector<float>> out,int a,int c,string outputmatrix){
   ofstream MyFile(outputmatrix);
   MyFile<<c<<endl;
   MyFile<<a<<endl;
      for(int i = 0; i < c; i++) {
         for(int j = 0; j < a; j++) {
            MyFile<<out[i][j]<<endl;
         }
      }
   MyFile.close();
   return ;
}

// 2nd Part //

float relu(float x){
   if(x>0){
      return x;
   }
   return 0.0;
}
float tan2h(float x){
   float t = 1;
   float e = exp(2);
   float h = 1/(1+pow(e,x));
   t = t - 2*h;
   return t;
}
void Make_relu(vector<vector<float>> m,int a,int b,string outputmatrix){
   ofstream MyFile(outputmatrix);
   MyFile<<b<<endl;
   MyFile<<a<<endl;
   for(int i = 0;i<b;i++){
      for(int j = 0;j<a;j++){
         MyFile<<relu(m[i][j])<<endl;
      }
   }
   MyFile.close();
   return ;
}
void Make_tanh(vector<vector<float>> m,int a,int b,string outputmatrix){
   ofstream MyFile(outputmatrix);
   MyFile<<b<<endl;
   MyFile<<a<<endl;
   for(int i = 0;i<b;i++){
      for(int j = 0;j<a;j++){
         MyFile<<tan2h(m[i][j])<<endl;
      }
   }
   MyFile.close();
   return ;
}

// 3rd Part //

float maxpooling(vector<vector<float>> m,int s,int i,int j){
   float a = m[i][j];
   for(int x = i;x<i+s;x++){
      for(int y=j;y<j+s;y++){
            if(m[x][y]>a){
              a = m[x][y];
            }
      }
   }
   return a;
}
float averagepooling(vector<vector<float>> m,int s,int i,int j){
   float a = 0.00000;
   for(int x = i;x<i+s;x++){
      for(int y=j;y<j+s;y++){
              a += m[x][y];
      }
   }
   float sq = s*s;
   return a/sq;
}

void Make_maxpooling(vector<vector<float>> m,int a,int s,string outputmatrix){
	ofstream MyFile(outputmatrix);
   MyFile<<a/s<<endl;
   MyFile<<a/s<<endl;
	for(int i = 0;i<a;i=i+s){
      for(int j = 0;j<a;j=j+s){
         MyFile<<maxpooling(m,s,i,j)<<endl;
      }
   }
   MyFile.close();
   return ;
}
void Make_averagepooling(vector<vector<float>> m,int a,int s,string outputmatrix){
	ofstream MyFile(outputmatrix);
   MyFile<<a/s<<endl;
   MyFile<<a/s<<endl;
	for(int i = 0;i<a;i=i+s){
      for(int j = 0;j<a;j=j+s){
         MyFile<<averagepooling(m,s,i,j)<<endl;
      }
   }
   MyFile.close();
   return ;
}

// 4th Part //

void Make_softmax(vector<float> v,int a,string outputvector){
   float sum = 0;
   for(int i = 0;i<a;i++){
      sum += exp(v[i]);
   }
   ofstream MyFile(outputvector);
   MyFile<<a<<endl;
   for(int i = 0;i<a;i++){
      MyFile<<exp(v[i])/sum<<endl;     
   }
   MyFile.close();
   return ;
}
void Make_sigmoid(vector<float> v,int a,string outputvector){
   float sum = 0;
   for(int i = 0;i<a;i++){
      sum += exp(v[i]);
   }
   ofstream MyFile(outputvector);
   MyFile<<a<<endl;
   for(int i = 0;i<a;i++){ 
      MyFile<<(1/(1+exp(-v[i])))<<endl;    
   }
   MyFile.close();
   return ;
}