#include <stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initializeCanvas() 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas() 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    initializeCanvas();
    
   canvas[5][10] = '*';
    canvas[5][11] = '*';
    canvas[5][12] = '*';

    printf("Cnvas stored in 2D array:\n");
    displayCanvas();
    
    return 0;
}