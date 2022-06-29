1. extarcted folder from the zip
2. Launch the terminal in the extarcted folder from the zip
3. Run the following commands in the terminal from the directory of the project folder.
4. ./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt
   ./yourcode.out activation relu inputmatrix.txt outputmatrix.txt
   ./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt
   ./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt
   ./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt
   ./yourcode.out probability softmax inputvector.txt outputvector.txt
   ./yourcode.out probability sigmoid inputvector.txt outputvector.txt
5. Functions in Header File:
    1) Is_Int = check that dimension whether string is integer or not.
    2) GiveMatrix = return Matrix from txt file.
    3) GiveVector = return Vector from txt file.
    4) GiveOutputMatrix = return Matrix which multiply of first and second matrix.
    5) MakeMatrix = Write Matrix and its dimensions in txt file .
    6) relu = return relu value of float.
    7) tan2h = return tanh value of float.
    8) Make_relu = take matrix and write its elements relu value and its dimensions in txt file.  
    9) Make_tanh = take matrix and write its elements tanh value and its dimensions in txt file.
   10) maxpooling = return max pooling value from matrix.
   11) averagepooling = return average pooling value from matrix.
   12) Make_maxpooling = take matrix and write its elements max pooling value and its dimensions in txt file. 
   13) Make_averagepooling = take matrix and write its elements average pooling value and its dimensions in txt file. 
   14) Make_softmax = take vector and write its elements softmax probablity value and its dimensions in txt file. 
   15) Make_sigmoid = take vector and write its elements sigmoid probablity value and its dimensions in txt file. 