# COP290: A1-Subtask-1
## Header File
1. Functions:  
    - Is_Int = check that dimension whether string is integer or not.
    - GiveMatrix = return Matrix from txt file.
    - GiveVector = return Vector from txt file.
    - GiveOutputMatrix = return Matrix which multiply of first and second matrix.
    - MakeMatrix = Write Matrix and its dimensions in txt file .
    - relu = return relu value of float.
    - tan2h = return tanh value of float.
    - Make_relu = take matrix and write its elements relu value and its dimensions in txt file.  
    - Make_tanh = take matrix and write its elements tanh value and its dimensions in txt file.
    - maxpooling = return max pooling value from matrix.
    - averagepooling = return average pooling value from matrix.
    - Make_maxpooling = take matrix and write its elements max pooling value and its dimensions in txt file. 
    - Make_averagepooling = take matrix and write its elements average pooling value and its dimensions in txt file. 
    - Make_softmax = take vector and write its elements softmax probablity value and its dimensions in txt file. 
    - Make_sigmoid = take vector and write its elements sigmoid probablity value and its dimensions in txt file. 
## How to run Code
1. Clone this repository using git clone https://github.com/DhananjaySapawat/COP290-A1 or download as Zip and extract.
2. Run following Command:  
  - cd COP290-A1-Part1
  - ./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt
  - ./yourcode.out activation relu inputmatrix.txt outputmatrix.txt
  - ./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt
  - ./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt
  - ./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt
  - ./yourcode.out probability softmax inputvector.txt outputvector.txt
  - ./yourcode.out probability sigmoid inputvector.txt outputvector.txt
