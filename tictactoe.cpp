#include <iostream>
#include <string>
using namespace std;

class game{

private:
    char grid[3][3];

public: 
    void check_for_win(){
        const char* winning_moves[8]={
            "123","456","789","147","258","369","159","753"
        };
        for (int i=0; i<8;i++){
            bool winner = true;
            char previous_grid = '0';
            const char* winning_move = winning_moves[i];

            for(int index =0; index<3; index++){
                char character = winning_move[index];
                int entered_number = character-'0';
                int grid_space = entered_number-1;
                int row = grid_space / 3;
                int col = grid_space % 3;
                char grid_char = grid[row][col];
                if(previous_grid == '0'){
                    previous_grid=grid_char;
                }
                else if (previous_grid == grid_char){
                    continue;
                }else{
                    winner = false;
                    break;
                }
            }
            if( winner){
                puts("***We have a winner! ***");
                printf("Looks like %c won, congratulation!\n", previous_grid);
                exit(0);
                break;
            }
        }
    }
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
            check_for_win();
            show_grid();
            ask_turn();
        }
        
    }
};

int main( int argc, char *argv[] )
{
    game game1;
    return 0;
}