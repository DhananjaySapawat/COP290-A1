#include<iostream>
#include"API.h"
using namespace std;
bool error = false;
int main(int argc, char** argv){
   if(argc!=3){
      cout<<"Error : Give Two Inputs <audiosamplefile> <outputfile> " << endl;
      return -1;
   }
   string audiofeatures = argv[1];
   string OutputFile =  argv[2];
   pred_t* pred = new pred_t[3];
   pred = libaudioAPI(argv[1], pred);
   Print_Csv_File(argv[1],argv[2], pred);
   return 0;
}
