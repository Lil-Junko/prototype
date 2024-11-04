#include "proto.h"

void initialize(char grid[100][100][3])
{
    // set whole grid to . for empty space
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                grid[i][j][k] = '.';
            }
        }
    }
    // // place player in a random side on the right between 100 and 60
    // srand(time(NULL));
    // int playerX = rand() % 40 + 60;
    // int playerY = rand() % 100;
    // grid[playerX][playerY][0] = 'P';
    // // place deep sea knight on the left between 0 and 40
    // int knightX = rand() % 40;
    // int knightY = rand() % 100;
    // grid[knightX][knightY][0] = 'K';
}

void initializePlayer(char grid[100][100][3], int pos[])
{
    // place player in a random side on the right between 100 and 60
    srand(time(NULL));
    int playerX = rand() % 40 + 60;
    int playerY = rand() % 100;
    grid[playerX][playerY][0] = 'P';
    pos[0] = playerX;
    pos[1] = playerY;
    // save player position in pos[]
}

void initializeDSK(char grid[100][100][3], int DSKpos[])
{
    // place deep sea knight on the left between 0 and 40
    int knightX = rand() % 40;
    int knightY = rand() % 100;
    grid[knightX][knightY][0] = 'K';
    grid[knightX + 1][knightY][0] = 'K';
    grid[knightX][knightY + 1][0] = 'K';
    grid[knightX + 1][knightY + 1][0] = 'K';
    DSKpos[0] = knightX;
    DSKpos[1] = knightY;
    // save DSK position in DSKpos[]
}

void print(char grid[100][100][3], int pos[])
{
    // print a 19 by 19 grid with player in the middle
    // check if player is near the border of the array
    // only print what is in the array and " " for empty spaces
    if(pos[0] < 9 || pos[0] > 90 || pos[1] < 9 || pos[1] > 90)
    {
        for (int i = 0; i < 19; i++)
        {
            for (int j = 0; j < 19; j++)
            {
                cout << grid[i][j][0] << ' ';
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = pos[0] - 9; i < pos[0] + 10; i++)
        {
            for (int j = pos[1] - 9; j < pos[1] + 10; j++)
            {
                cout << grid[i][j][0] << ' ';
            }
            cout << endl;
        }
    }
    cout << "Player position: " << pos[0] << ", " << pos[1] << endl;
}