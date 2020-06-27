#include <iostream>
#include <string>
using namespace std;

int main( int argc, char *argv[] )
{
    char grid[3][3];
    int number=1;
    for ( int i=0; i<3; i++ ){
        for ( int j=0; j<3; j++ ){
            grid[i][j] = to_string(number).c_str()[0];
            number +=1;
            
        }
    }

    printf("\n-----------\n");
    for ( int i=0; i<3; i++ ){
        for ( int j=0; j<3; j++ ){
            printf(" %c |", grid[i][j]);
        }
        printf("\n-----------\n");
    }  

    return 0;
}