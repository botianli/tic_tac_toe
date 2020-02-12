//
//  main.cpp
//  excercise
//
//  Created by libotian on 2020-01-17.
//  Copyright © 2020 libotian. All rights reserved.
//
#include "function.cpp"
int main(int argc, const char * argv[]){

    greetAndInstruct();


                                                //still have move in the board&&nowinner
  while(has_move(table)&&!checkWinner(table)){ //loop until one of the condition met

    cout<<"Player move, please enter input:"<<endl;
     flush(cout);
      string mystr;
      int input;
      cin>>mystr;
      stringstream(mystr)>>input;   //process user input, this will guarantie user input wont cause crash


    if(checkIfLegal(input, table)){   //if it is legal, put user input
        put_input(input, 0);

     cout<<"Player move:"<<endl;    //print out user input
        displayBoard(table);
        cout<<endl;
        playermove=input;           //global var to record previoud user input
        computerMove(table);        //computer move now
      cout<<"computer move:"<<endl;
        displayBoard(table);        //print the board again
    }else{
        cout<<"Wrong input."<<endl; //If input is wrong, ask for input again
         flush(cout);
    }
    }

    //-----after game end--------
    if(result1==1||result2==1||result0==1){//if computer win, print out
       cout<<"computer win!"<<endl;

    }else if(result1==-1||result2==-1||result0==-1){ //if player win return true
        cout<<"player win!"<<endl;

    }else{
        cout<<"It is tie"<<endl;
    }

    return 0;
}
