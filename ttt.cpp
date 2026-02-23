#include <iostream>
#include <ctime> //cuz we will be working with random numbers
using namespace std;

void drawBoard(char *spaces);
void selectcharac(char &player, char &computer);
void playerMove(char *spaces, char player);
void compMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {

    srand(time(0));

    char spaces[9] = {' ', ' ',' ',' ',' ',' ',' ',' ',' '}; //creating an array

    char player = 'X';
    char computer = 'O';

    selectcharac(player, computer);

    bool running = true;

    drawBoard(spaces);

    while(running)
    {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }

        compMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }
    cout << "Thanks for playing\n";

    return 0;
}

void selectcharac(char &player, char &computer)
{
    cout << "----------SElECT YOUR CHARACTER----------" << endl;
    cin >> player;
    cout << "----------SElECT OPP CHARACTER----------" << endl;
    cin >> computer;

    //Displaying respective characters
    cout << "--------------------------------------------------\n";
    cout << "Your character is: " << player << '\n';
    cout << "Opponent character is: " << computer << '\n';
    cout << "--------------------------------------------------\n";
}

void drawBoard(char *spaces)
{
    cout << "LET THE GAME BEGIN!\n";
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____"<< '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____"<< '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}

void playerMove(char *spaces, char player)
{
    int number;
    do {
        cout << "Enter a spot to place the marker (0-9): ";
        cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    }while (number < 0 || number > 8 || spaces[number] != ' ');
}

void compMove(char *spaces, char computer) {
    int number;

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;//Gives a random number between 0 and 9
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{
    //FIRST ROW
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        cout << (spaces[0] == player ? "YOU WIN!" : "YOU LOSE :(");
    }

    //SECOND ROW
    else if ((spaces[3] != ' ') && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        cout << (spaces[3] == player ? "YOU WIN!\n" : "YOU LOSE :(\n");
    }

    //THIRD ROW
    else if ((spaces[6] != ' ') && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        cout << (spaces[6] == player ? "YOU WIN!" : "YOU LOSE :(");
    }

    //FIRST ROW
    else if ((spaces[0] != ' ') && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        cout << (spaces[0] == player ? "YOU WIN!" : "YOU LOSE :(");
    }

    //SECOND COLUMN
    else if ((spaces[1] != ' ') && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        cout << (spaces[1] == player ? "YOU WIN!" : "YOU LOSE :(");
    }

    //THIRD ROW
    else if ((spaces[2] != ' ') && spaces[2] == spaces[5] && spaces[5  ] == spaces[8])
    {
        cout << (spaces[2] == player ? "YOU WIN!" : "YOU LOSE :(");
    }

    //LEFT DIAGONAL
    else if ((spaces[0] != ' ') && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        cout << (spaces[0] == player ? "YOU WIN!" : "YOU LOSE :(");
    }

    //RIGHT DIAGONAL
    else if ((spaces[2] != ' ') && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        cout << (spaces[2] == player ? "YOU WIN!" : "YOU LOSE :(");
    }
    else
    {
        return false;
    }
    return true;
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    cout << "Its a tie!\n";

    return true;
}