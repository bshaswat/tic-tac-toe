#include <iostream>
#include <string>
using namespace std;

class game{

private:
    char grid[3][3];

public: 

    void ask_turn(){
        string input;
        while(true){
            puts("Where would you like to play?");
            getline(cin,input);

            if(input != ""){
                char entered = input.c_str()[0];

                if(entered >= '1' && entered <= '9'){
                    int entered_number = entered - '0';
                    int index = entered_number -1;

                    int row= index/3;
                    int col= index % 3;

                    char grid_position = grid[row][col];
                    
                    if (grid_position == 'X' || grid_position == 'O'){
                        puts("That grid position is already taken!");
                    }else{
                        grid[row][col]='X';
                        break;
                    }
                    
                }else{
                    puts("You have to play in range 1-9! ");
                }
            }else{
                puts("You must enter something!");
            }
        }
    }

    void generate_grid(){
        int number=1;
        for ( int i=0; i<3; i++ ){
            for ( int j=0; j<3; j++ ){
                grid[i][j] = to_string(number).c_str()[0];
                number +=1;
            }
        }
    }
    
    void show_grid(){
        printf("\n-----------\n");
        for ( int i=0; i<3; i++ ){
            for ( int j=0; j<3; j++ ){
                printf(" %c |", grid[i][j]);
            }
            printf("\n-----------\n");
        }
    }

    game(){
        generate_grid();

        while (true){
            show_grid();
            ask_turn();
        }
        
    }
};

int main( int argc, char *argv[] )
{
    game game;

    return 0;
}