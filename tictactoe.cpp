#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Code to Play with AI
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

    void computer_player_turn(){
        while( true ){

        
            int computer_choice = ( rand() % 9 ) + 1;
            int row = (computer_choice -1) / 3;
            int col = (computer_choice -1) % 3;
            char grid_position = grid[row][col];
            if (grid_position == 'X' || grid_position == 'O'){
                continue;
            }else{
                printf("The computer will play at %d.\n", computer_choice);
                grid[row][col]= 'O';
                break;
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
        printf("\n-------------\n");
        for ( int i=0; i<3; i++ ){
            printf("|");
            for ( int j=0; j<3; j++ ){
                printf(" %c |", grid[i][j]);
            }
            printf("\n-------------\n");
        }
    }

    game(){
        generate_grid();
        show_grid();
        check_for_win();
        while (true){
            ask_turn();
            check_for_win();
            
            computer_player_turn();
            show_grid();
            check_for_win();
        }
        
    }
};


// Code to play with another player
char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'X';
int n;
void Draw()
{
    system("cls");
    cout << "Tic Tac Toe v1.0" << endl;
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            printf(" %c |", matrix[i][j]);
        }
        
        printf("\n-------------\n");
    }
}
void Input()
{
    int a;
    cout << "It's " << player << " turn. " <<"Press the number of the field: ";
    cin >> a;
 
    if (a == 1)
    {
        if (matrix[0][0] == '1')
            matrix[0][0] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
    else if (a == 2)
    {
        if (matrix[0][1] == '2')
            matrix[0][1] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
    else if (a == 3)
    {
        if (matrix[0][2] == '3')
            matrix[0][2] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
    else if (a == 4)
    {
        if (matrix[1][0] == '4')
            matrix[1][0] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
    else if (a == 5)
    {
        if (matrix[1][1] == '5')
            matrix[1][1] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
    else if (a == 6)
    {
        if (matrix[1][2] == '6')
            matrix[1][2] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
    else if (a == 7)
    {
        if (matrix[2][0] == '7')
            matrix[2][0] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
    else if (a == 8)
    {
        if (matrix[2][1] == '8')
            matrix[2][1] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
    else if (a == 9)
    {
        if (matrix[2][2] == '9')
            matrix[2][2] = player;
        else
        {
            cout << "Field is already in use try again!" << endl;
            Input();
        }
    }
     
}
void TogglePlayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}
char Win()
{
    //first player
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
 
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';
 
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
 
    //second player
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
 
    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';
 
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
 
    return '/';
}


int main( int argc, char* argv[] )
{
    string choise;
    cout << "Do you want to play with ai or another player? AI = AI, Another Player = B \n";
    getline (cin, choise);
    
    if (choise == "AI" ){
        printf("You are playing with AI.\n ");
        srand(time(0));
        game game1;
    }else if (choise == "B"){
        n = 0;
        Draw();
        while (1)
        {
            n++;
            Input();
            Draw();
            if (Win() == 'X')
            {
                cout << "X wins!" << endl;
                break;
            }
            else if (Win() == 'O')
            {
                cout << "O wins!" << endl;
                break;
            }
            else if (Win() == '/' && n == 9)
            {
                cout << "It's a draw!" << endl;
                break;
            }
            TogglePlayer();
        }
        system("pause");
    }else{
        printf("Choose a valid response.\n");
    }
    return 0;
}
