//
//  function.cpp
//  excercise
//
//  Created by libotian on 2020-02-11.
//  Copyright © 2020 libotian. All rights reserved.
//


#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int result0; //checking who is the winner , 0 is tie, 1 is computer -1 is player
int result1;
int result2;
int playermove;
int element[27]; //global array, have {1,2,3,....,27}
char table[27]; //1d 27 array
char table1[9];
char table2[9];
char table3[9];
void print_element();
bool has_win_move(int type,char board[]);
//gretAndInstruct will wait user input only only process when user put right input,(y/n)
//
void  greetAndInstruct(){
    cout<<"Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer.\n";
    cout<<"The board is  numbered from 1 to 27 as  per the following:\n";
     cout<<endl;
    for(int i=0;i<27;i++){ //this is to print all 27 with the right format
        element[i]=i+1;
    }
    int printnum=1;
    for( int i=1;i<4;i++){
        for(int j=1;j<10;j++){
           if(int a=j%3==0){

           cout<<printnum<<"      ";  //this part will print out all the numbers with the right format
           printnum=printnum+7;
           flush(cout);
           }else{
            cout<<printnum<<"|";
            printnum++;
           }
        }
        cout<<endl;
         cout<<"------     --------      --------"<<endl;
        if(i==1){
            printnum=4;
        }
        if(i==2){
            printnum=7;
        }
    }
    cout <<endl;
    cout<<"Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O.\n";
    cout<< "Start?(y/n)\n";
      flush(cout);
    bool right_answer=true;

    while(right_answer){
    char anwser;
    cin>>anwser;
    //if user type in yes, initial the game with an char array of 27
    //together with 3  3x3 helper tables to check winning condition
    if(anwser=='y'){
        right_answer=false;
        cout<<"start the game!\n";
        for(int i=0;i<27;i++){
              table[i]=' ';
          }
        for(int i=0;i<9;i++){
            table1[i]=' ';
            table2[i]=' ';
            table3[i]=' ';
        }
    }
        //if the answer is no, the program at exit immediatley
    else if(anwser=='n'){
        right_answer=false;
        cout<< "bye\n";
        exit(0);
    }else{
        //else user typed wrong input, ask to type again
        cout<<"wrong input,try again! \n";

        }
    }
}

//method to display the 3 3*3 board, this method is only able to print out the fixed 3 3x3 board, single board will not work
void displayBoard(char board[]){

    int printnum=0;
     for(int i=0;i<3;i++){
         if(i==1){
                printnum=3;
            }
         if(i==2){
                printnum=6;
            }
         for(int j=1;j<10;j++){
              if(int a=j%3==0){

           cout<<board[printnum]<<"      ";
                //  cout<<printnum<<" ";
               printnum=printnum+7;

              }else{
             cout<<board[printnum]<<"|";
                 // cout<<printnum<<" ";
               printnum++;
              }

           }
         cout<<endl;
         if(i<=1){
         cout<<"------    -------    -------"<<endl;
         }

      }
}
//method to check if the input is legal
bool checkIfLegal(int cellNbre,char board[]){
    if(cellNbre<=0||cellNbre>27){ //if out of range return false
        return false;
    }
    int index=cellNbre-1;
    if(board[index]!=' '){ //check if the slot is occupied already
        return false;   //if it is occupied return false
    }else{
        return true;
    }
}

// helper function to check winning condition
//if return 0 meaning it is tie, -1 meaning player win, 1 meaning computer win
int check_same_table(char board[]){
    int result=0;
    //check condition for 3x3 board
    char
    first=board[0],second=board[1],third=board[2],fourth=board[3],fifth=board[4],sixth=board[5],seventh=board[6],eigth=board[7],ningth=board[8];

    //--------checking hotizontal---------

    //check each 3 consecutive horizontal slots
    if((first==second&&second==third&&first!=' ')||(fourth==fifth&&fifth==sixth&&sixth!=' ')||(seventh==eigth&&eigth==ningth&&ningth!=' ')){
        // cout<<"checking Horizontal"<<endl;
        if(first==second&&second==third&&first!=' '){
            if(first=='x'){
                 result=-1;
            }else{
                result=1;
            }
        }
        if(fourth==fifth&&fifth==sixth&&sixth!=' '){
            if(fourth=='x'){
                 result=-1;
                       }else{
                  result=1;
                       }
        }
        if(seventh==eigth&&eigth==ningth&&ningth!=' '){
            if(seventh=='x'){
            result=-1;
                  }
            else{
             result=1;
                  }
        }


    }
  //--------checking vertical---------
    else if((first==fourth&&fourth==seventh&&seventh!=' ')||(second==fifth&&fifth==eigth&&eigth!=' ')||(third==sixth&&sixth==ningth&&ningth!=' ')){

        if((first==fourth&&fourth==seventh&&seventh!=' ')){
            if(first=='x'){
                result=-1;
            }else{
                result=1;
            }
        }
        if(second==fifth&&fifth==eigth&&eigth!=' '){
            if(second=='x'){
                    result=-1;
                }else{
                    result=1;
                }
            }
        if(third==sixth&&sixth==ningth&&ningth!=' '){
            if(third=='x'){
                    result=-1;
              }else{
               result=1;
          }
        }
        }
    //  --------checking diagonal---------
    else if((first==fifth&&fifth==ningth&&ningth!=' ')||(third==fifth&&fifth==seventh&&seventh!=' ')){
        if((first==fifth&&fifth==ningth&&ningth!=' ')){
        if(first=='x'){
            result=-1;

        }else{
            result=1;

        }

        }else{
            if(third=='x'){
                result=-1;
            }else{
                result=1;
            }
        }
           }
    //if above condtion all didnt met, meaning no winning condition for computer or payer, rentun tie
   return result;
  }
//helper function for computer move, remove an input if necessary
void remove_input(int input){
    element[input-1]=input;
    table[(input-1)]=' ';
     if(input<=9){
           table1[(input-1)]=' ';
     }
     if(input>=10&&input<=18){
          table2[input-10]=' ';
     }
     if(input>=19&&input<=27){
          table3[input-19]=' ';
     }
}
//helper function to put input, if it is 0 put x if it is 1 put o
//it will at the same time put input in 3D game board and 3 3x3 tables
void put_input(int input,int type){//type 0,player, type 1 computer
        element[input-1]=0;
        if(input<=9){
            if(type==0){
            table1[(input-1)]='x';
            }else{
                table1[(input-1)]='o';
            }
        }
        if(input>=10&&input<=18){
            if(type==0){
            table2[input-10]='x';
            }else{
                table2[input-10]='o';
            }
        }
        if(input>=19&&input<=27){
            if(type==0){
            table3[input-19]='x';
            }else{
            table3[input-19]='o';
               }
        }
    if(type==0){
           table[(input-1)]='x';
    }else{
        table[(input-1)]='o';
    }
}

//helper function to check condition across 3 3x3 tables
//return value is  -1 player winner, 0 tie, 1 computer
int check_across_table(char table1[],char table2[],char table3[]){
    int result=0;
    if((table[0]==table[13]&&table[13]==table[26]&&table[26]!=' ')){ // checking for horizontal across table
        if(table[0]=='x'){
            result=-1;

        }else{
            result=1;

        }
    }else if((table[20]==table[13]&&table[13]==table[6]&&table[6]!=' ')){
            if(table[13]=='x'){
                       result=-1;

                   }else{
                       result=1;

                   }
        }
    else{
        //--------checking same slots across table-------
        for(int i=0;i<9;i++){
               if( table1[i]==table2[i]&&table2[i]==table3[i]&&table[i]!=' '){
                   if(table1[i]=='x'){
                       result=-1;
                       break;
                   }else{
                       result=1;
                       break;

                   }
               }
           }
    }
   return result;
}
//checkWiner function using helper function check_across_table and check_same_table to get accurate result

bool checkWinner(char board[]){
     result2=check_same_table(table1)+check_same_table(table2)+check_same_table(table3); //result2 value can be either 1 or -1 or 0, since only one winning condition is possible
     result1=check_across_table(table1,table2,table3); //this retun result for across table return valus is 1 or -1 or 0
                                                       //since only one winning condition is possible
    int firstTwo=result2+result1;                       //this is eith 1,-1,or 0. since only one of the winning condition is                                                   // possible for a single game, the value can't be 2 or (1+(-1)=0 or
                                                        //-1+(-1)=-2
     result0=0;
    if(firstTwo==0){                                       //if no winning from above check, lets check cross table horizontal

    int index[3]={0,3,6};
    for(int i=0;i<3;i++){
        int table_index=index[i];
        if(board[table_index]==board[(table_index+10)]&&board[(table_index+10)]==board[(table_index+20)]&&board[(table_index+20)]!=' '){
            if(board[table_index]=='x'){
                result0=-1;

                break;
            }else{
                result0=1;
                break;
                }
            }

        }
    }
    // after all checking, if not 0 return true, else false
    if(result1!=0||result2!=0||result0!=0){//if computer win
       // cout<<"computer win!"<<endl;
        return true;

    }
    else{
    return false;
    }
}
//helper function to print 3x3 board
void small_table_print(char board[]){
     int printnum=0;
    for(int i=0;i<3;i++){
        if(i==1){
            printnum=3;
       }
        if(i==2){
            printnum=6;
        }
        for(int j=0;j<3;j++){
            cout<<board[printnum]<<"|";
            printnum++;
        }
        cout<<endl;
    }

}
//bool to check if still place to move
bool has_move(char board[]){
    for(int i=0;i<27;i++){
        if(board[i]==' '){
            return true;
        }
    }
    return false;
}
//helper function that  return the first available slot
int first_slot(){
    for(int i=0;i<27;i++){
        if(element[i]!=0){
            return element[i];
        }
    }
    return -1;
}
//computer move
void computerMove(char board[]){
    if( has_win_move(1,board)){ //check potential win
    }
    else if(has_win_move(0,board)){ // if no potential win, see if player has potential win

    }else{                          //If both doesnt have, put in the middle of the board, all put in first availabe  spot
        if(playermove>=1&&playermove<=9){
            if(table[4]==' '){
                put_input(5, 1);
            }else{
                int position=first_slot();
                       put_input(position, 1);
            }
        }else if(playermove>=10&&playermove<=18){
            if(table[13]==' '){
                put_input(14, 1);
            }else{
                int position=first_slot();
                       put_input(position, 1);
            }
        }else{
            if(table[22]==' '){
                put_input(23, 1);
            }else{
                int position=first_slot();
                put_input(position, 1);
                       }
        }
      }
}
//helper function int type:0 if it is checking player move,
//                    type:1:if it is  checking computer move
bool has_win_move(int type,char board[]){ //0 is player 1 is computer
    for(int i=0;i<27;i++){
        int position=element[i]; // element array of all 1-27 number
        if(position!=0){ // 0: the number is occupied. if find a non occupied slot

            if(type==1){ //if we are checking computer potential win
                put_input(position, 1); //put it in the board
                if(checkWinner(board)){ //if find such postion return true, this is a potential win
                                        //put it there then return true
                    return true;
                }
                remove_input(position);  //else it is not a potential win move, remove it from the board, check for next                            //available number
            }else{                         //if we are blocking player,

                put_input(position, 0);     //put it in the board
                if(checkWinner(board)){     //if this lead to potential player winning
                    remove_input(position); // remove it and put computer move instead
                    put_input(position, 1);
                    result2=0;              //renew global var for checking winning
                   result1=0;
                    result0=0;

                    return true;
                }else{
                    remove_input(position); //if didnt find, just remove and go to next iteration

                }
                 remove_input(position);
            }
        }

    }
   //if non of the above been returned, meaning algorithms didnt find potential winning position. return false
    return false;
}
