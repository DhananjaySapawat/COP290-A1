#include<iostream>
#include<fstream>
using namespace std;
string space(string in){
     int n = 13 - in.size();
     for(int i = 0;i<n;i++){
          in =  in + " ";
     }
     return in;
}
int main(int argc, char** argv){
	if(argc!=2){
      cout<<"Error : Give one Inputs <dimension> "<<endl;
      return -1;
   }
   string in1,in2,in3,in4;
   int a = stoi(argv[1]);
   string time = "../Time/time"+to_string(a)+".txt";
   ofstream MyFile(time); 
   MyFile<<"#SIMPLE:     "<<"#PTHREAD:      "<<"#OPENBLAS:      "<<"#MKL:       "<<endl;
   fstream myfile1,myfile2,myfile3,myfile4;
   string outmat1 = "../Time_Output/simple/simple"+to_string(a)+".txt";
   string outmat2 = "../Time_Output/pthread/pthread"+to_string(a)+".txt";
   string outmat3 = "../Time_Output/openblas/openblas"+to_string(a)+".txt";
   string outmat4 = "../Time_Output/mkl/mkl"+to_string(a)+".txt";
   myfile1.open(outmat1,ios::in);
   myfile2.open(outmat2,ios::in);
   myfile3.open(outmat3,ios::in);
   myfile4.open(outmat4,ios::in);
   for(int i = 0;i<10;i++){
        getline(myfile1,in1);
        getline(myfile2,in2);
        getline(myfile3,in3);
        getline(myfile4,in4);
        MyFile<<space(in1)<<space(in2)<<space(in3)<<space(in4)<<endl;
   }
   MyFile.close();
   myfile1.close();
   myfile2.close();
   myfile3.close();
   myfile4.close();
}