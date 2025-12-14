#include<iostream>
using namespace std;
char board[3][3];
char CurrentPlayer;
void intializeBoard(){
    char ch='1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]= ch++;
        }
    }

}
void displayBoard(){
    cout<<endl;
    for(int i=0;i<3;i++){
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<board[i][j];
            if(j<2)cout<<"|";
        }
        cout<<endl;
        if(i<2){
            cout<<"---|---|---"<<endl;
        }
    }
    cout<<endl;
}
void switchPlayer(){
    CurrentPlayer= (CurrentPlayer=='X')?'O':'X';
    
}
bool makeMove(int choice){
  int row= (choice-1)/3;
  int col=(choice-1)%3;
  if(board[row][col]!='X' && board[row][col]!='O'){
    board[row][col]= CurrentPlayer;
    return true;
  }
  return false;
}
bool checkWin(){
    for(int i=0;i<3;i++){
        if(board[i][0]==CurrentPlayer &&
           board[i][1]==CurrentPlayer &&
           board[i][2]==CurrentPlayer){
            return true;
           }
        if(board[0][i]==CurrentPlayer &&
           board[1][i]==CurrentPlayer &&
           board[2][i]==CurrentPlayer){
            return true;
        }
        
    }
    if(board[0][0]==CurrentPlayer &&
       board[1][1]==CurrentPlayer &&
        board[2][2]==CurrentPlayer){
            return true;
        }
    if(board[0][2]==CurrentPlayer &&
           board[1][1]==CurrentPlayer &&
           board[2][0]==CurrentPlayer){
            return true;
        }
    return false;

}
bool checkDraw() {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
} 
 int main() {
    char playAgain;

    do {
        intializeBoard();
        CurrentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            int choice;
            cout << "Player " << CurrentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9 || !makeMove(choice)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Player " << CurrentPlayer << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}

    

        
