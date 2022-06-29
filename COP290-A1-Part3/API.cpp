#include "API.h"

/*
take input string file and return array of size 250

args audiofeatures: input audio txt file path

output : double array of input from audio txt file
*/
double * GiveAudioMatrix(string audiofeatures){
   fstream myfile;
   myfile.open(audiofeatures,ios::in);
   double*m = new double[250];
   vector<string> s; 
   string input ;
   if(!getline(myfile,input)){
      cout<<"Error : Cannot get input in "+ audiofeatures<<endl;
      exit(1);
   }
   myfile.close();
   input = input + " ";
   int n = input.size();
   int i,j,k = 0;
   while(k<250 and  j<n){
      if(input[j] == ' '){
         m[k] = stod(input.substr(i,j));
         i = j+1;
         k++;
      }
      j++;
   }
   if(k!=250){
      cout<<"Error : file not have 250 input values"<<endl;
      exit(1);
   }
   return m;
}
/* take double value and return its relu value */
double relu(double x){
   if(x>0){
      return x;
   }
   return 0.0;
}
/* take double array and change its elements value to their relu value */
void ReluArray(double * m ,int n){
   for(int i = 0;i<n;i++){
      m[i] = relu(m[i]);
   }
   return ;
}
/* take double array and change its elements value to their softmax probability */
void SoftmaxArray(double * m ,int n){
   double sum = 0;
   for(int i = 0;i<n;i++){
      sum += exp(m[i]);
   }
   for(int i = 0;i<n;i++){
      m[i] = exp(m[i])/sum ;     
   }
   return ;
}
/*
take input string file and return pred_t array 

args audiofeatures: input audio txt file path

output : top 3 keywords index and their respective probablity 
*/
pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred){
   string audiofeaturesfile = audiofeatures;
   double *input = GiveAudioMatrix(audiofeaturesfile);
   /*if(error){
      return -1;
   }*/
   cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 250, 1.0, input, 250, IP1_WT, 144, 1.0, IP1_BIAS, 144);

   ReluArray(IP1_BIAS,144);
   
   cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 144, 1.0, IP1_BIAS, 144, IP2_WT, 144, 1.0, IP2_BIAS, 144);

   ReluArray(IP2_BIAS,144);
 
   cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 144, 144, 1.0, IP2_BIAS, 144, IP3_WT, 144, 1.0, IP3_BIAS, 144);
 
   ReluArray(IP3_BIAS,144);
 
   cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 12, 144, 1.0, IP3_BIAS, 144, IP4_WT, 12 , 1.0, IP4_BIAS, 12 );
   SoftmaxArray(IP4_BIAS,12);
   
   int index[3];
   double probality[12];
   for(int i = 0;i<12;i++){
      probality[i] = IP4_BIAS[i];
   }
   sort(IP4_BIAS,IP4_BIAS+12, greater<double>());
   
   for(int i = 0;i<12;i++){
      if(probality[i] == IP4_BIAS[0]){
         index[0] = i ;
      }
      if(probality[i] == IP4_BIAS[1]){
         index[1] = i ;
      }
      if(probality[i] == IP4_BIAS[2]){
         index[2] = i ;
      }
   }   
   for(int i=0; i<3; i++){
      pred[i].label = index[i];
      pred[i].prob = probality[index[i]];
   }
   return pred;
}
/*
take input string file ,pred_t array and print them in output file .  

args Audio: input audio txt file path , output: output txt file path and pred_t array

*/
void Print_Csv_File(char* Audio,char* output , pred_t* pred){
   vector<string> keyword = {"_silence_", "_unknown_", "yes", "no", "up", "down", "left", "right", "on", "off", "stop", "go"};
   string audiofeatures = Audio;
   string OutputFile = output;
   fstream out;
   out.open(OutputFile, ios::out | ios::app);
   out<<audiofeatures;
   for(int i = 0;i<3;i++){
      out<<","<<keyword[pred[i].label];
   }
   for(int i = 0;i<3;i++){
      out<<","<<pred[i].prob;
   }
   out<<endl;
   return ;
}


