#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player);
bool checkTie(char *spaces);

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player)){
            cout << "Player wins!" << endl;
            break;
        }
        if(checkTie(spaces)){
            cout << "It's a tie!" << endl;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, computer)){
            cout << "Computer wins!" << endl;
            break;
        }
        if(checkTie(spaces)){
            cout << "It's a tie!" << endl;
            break;
        }
    }
    cout<<"THANKS FOR PLAYING !!"<<endl;

    return 0;
}

void drawBoard(char *spaces){
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

void playerMove(char *spaces, char player){
    int number;
    do{
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--;
        if(number < 0 || number > 8){
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
        }
        else if(spaces[number] != ' '){
            cout << "Spot already taken. Please choose another spot." << endl;
        }
        else {
            spaces[number] = player;
            break;
        }
    } while(true);
}

void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;  // Break the loop once a valid move is made
        }
    }
}

bool checkWinner(char *spaces, char player){
    // Check rows
    for(int i = 0; i < 9; i += 3){
        if(spaces[i] == player && spaces[i+1] == player && spaces[i+2] == player){
            return true;
        }
    }
    // Check columns
    for(int i = 0; i < 3; i++){
        if(spaces[i] == player && spaces[i+3] == player && spaces[i+6] == player){
            return true;
        }
    }
    // Check diagonals
    if((spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
       (spaces[2] == player && spaces[4] == player && spaces[6] == player)){
        return true;
    }

    return false;
}

bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    return true;
}
