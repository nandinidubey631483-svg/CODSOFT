#include<iostream>
#include<stdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    int Lower,Upper;
    cout<<"Enter Lower Range:"; cin>>Lower;
     cout<<"Enter Upper Range:"; cin>>Upper;
     int number= rand() % (Upper-Lower+1) + Lower;
     int Guess;
     cout<<"Guess the number bw"<<Lower<<"and"<<Upper<<endl;
     do{
        cout<<"Enter your guess:";    cin>>Guess;
        if(Guess>number){
            cout<<"Too High!"<<endl;
        }
        else if(Guess<number){
            cout<<"Too Low!"<<endl;
        }
        else{
            cout<<"Correct Guess!"<<endl;
        }

     }while(Guess!=number);
     return 0;
}
