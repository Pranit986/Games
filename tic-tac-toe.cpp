#include <iostream>
#include <string>
using namespace std;

// multidimensional array of size 3x3
char square[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

// class game to manage all the functions
class Game{
    public:
        void display(){
            cout << "       |       |       " << endl;
            cout << "    " << square[0][0] << "  |   " << square[0][1] << "   |   " << square[0][2] << "  " << endl;
            cout << "_______|_______|_______" << endl;
            cout << "       |       |       " << endl;
            cout << "    " << square[1][0] << "  |   " << square[1][1] << "   |   " << square[1][2] << "  " << endl;
            cout << "_______|_______|_______" << endl;
            cout << "       |       |       " << endl;
            cout << "    " << square[2][0] << "  |   " << square[2][1] << "   |   " << square[2][2] << "  " << endl;
            cout << "       |       |       " << endl;
        }

        int checkwinner(){
            
            // check for winner in the diagonals of the matrix
            if(square[0][0] == square[1][1] && square[1][1] == square[2][2]){
                return square[1][1];
            }
            if(square[0][2] == square[1][1] && square[1][1] == square[2][0]){
                return square[1][1];
            }

            // checking for winner in the rows and columns of the matrix
            for(int i=0; i<3; i++){
                if(square[i][0] == square[i][1] && square[i][1] == square[i][2]){
                    return square[i][1];
                }
                if(square[0][i] == square[1][i] && square[1][i] == square[2][i]){
                    return square[1][i];
                }
            }
            
            // if the game is still going on
            return -1;
        }

        void tutorial(){

            cout << "Enter 1 for X" << endl;
            cout << "Enter 2 for O" << endl;
            cout << endl;
        }

        void insert(int position,char player){
            if(position==1 && square[0][0] == '1'){
                square[0][0] = player;
            }
            else if(position==2 && square[0][1] == '2'){
                square[0][1] = player;
            }
            else if(position==3 && square[0][2] == '3'){
                square[0][2] = player;
            }
            else if(position == 4 && square[1][0] == '4'){
                square[1][0] = player;
            }
            else if(position == 5 && square[1][1] == '5'){
                square[1][1] = player;
            }
            else if(position == 6 && square[1][2] == '6'){
                square[1][2] = player;
            }
            else if(position == 7 && square[2][0] == '7'){
                square[2][0] = player;
            }
            else if(position == 8 && square[2][1] == '8'){
                square[2][1] = player;
            }
            else if(position == 9 && square[2][2] == '9'){
                square[2][2] = player;
            }
            else{
                cout << "Enter a correct position" << endl;
            }
            
        }
};

int main(){
    
    Game g;
    bool running = true;

    g.tutorial();

    while(running == true){
        
        g.display();
        int choice;
        
        cout << "Enter choice for player 1 (X or O) : " << endl;
        cin >> choice;
        
        char player1;
        char player2;

        if(choice == 1){
            player1 = 'X';
            player2 = 'O';
        }
        else if(choice == 2){
            player1 = 'O';
            player2 = 'X';
        }
        else{
            cout << "Enter a correct choice" << endl;
            continue; // restart the loop if choice is incorrect
        }

        int chance = 1;
        int position;

        while (g.checkwinner() == -1) {
            if(chance%2 != 0){
                cout << "enter position for " << player1 << " (1 to 9) : ";
                cin >> position;
                g.insert(position,player1);
            }
            else{
                cout << "Enter position for " << player2 << " (1 to 9) : ";
                cin >> position;
                g.insert(position,player2);
            }

            g.display();
            int winner = g.checkwinner();
            
            if(winner != -1){
                cout << winner << " has won the game" << endl;
                break; // exit the loop if there's a winner
            }
            
            chance++;
        }
    }

    return 0;

}

