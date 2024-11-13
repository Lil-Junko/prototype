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
    playerX = 9;
    playerY = 9;
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
    knightX = 0;
    knightY = 1;
    grid[knightX][knightY][0] = 'K';
    grid[knightX + 1][knightY][0] = 'K';
    grid[knightX][knightY + 1][0] = 'K';
    grid[knightX + 1][knightY + 1][0] = 'K';
    DSKpos[0] = knightX;
    DSKpos[1] = knightY;
    // save DSK position in DSKpos[]
    cout << "DSK position: " << DSKpos[0] << ", " << DSKpos[1] << endl;
}

void print(char grid[100][100][3], int pos[])
{
    // print a 19 by 19 grid with player in the middle
    // check if player is near the border of the array
    // only print what is in the array and " " for empty spaces
    int temp[2] = {pos[0], pos[1]};
    if (pos[0] < 9)
    {
        temp[0] = 9;
    }
    if (pos[0] > 90)
    {
        temp[0] = 90;
    }
    if (pos[1] < 9)
    {
        temp[1] = 9;
    }
    if (pos[1] > 90)
    {
        temp[1] = 90;
    }

    for (int i = temp[0] - 9; i < temp[0] + 10; i++)
    {
        for (int j = temp[1] - 9; j < temp[1] + 10; j++)
        {
            cout << grid[i][j][0] << ' ';
        }
        cout << endl;
    }
    cout << "Player position: " << pos[0] << ", " << pos[1] << endl;
}

void playerTurn(char grid[100][100][3], int pos[])
{
    // check if player moves up(w), down(s), left(a), right(d)
    char move = ' ';
    cin >> move;
    if (move == 'w') // up
    {
        if (grid[pos[0] - 1][pos[1]][0] == '.')
        {
            grid[pos[0] - 1][pos[1]][0] = 'P';
            grid[pos[0]][pos[1]][0] = '.';
            pos[0] -= 1;
        }
    }
    else if (move == 's') // down
    {
        if (grid[pos[0] + 1][pos[1]][0] == '.')
        {
            grid[pos[0] + 1][pos[1]][0] = 'P';
            grid[pos[0]][pos[1]][0] = '.';
            pos[0] += 1;
        }
    }
    else if (move == 'a') // left
    {
        if (grid[pos[0]][pos[1] - 1][0] == '.')
        {
            grid[pos[0]][pos[1] - 1][0] = 'P';
            grid[pos[0]][pos[1]][0] = '.';
            pos[1] -= 1;
        }
    }
    else if (move == 'd') // right
    {
        if (grid[pos[0]][pos[1] + 1][0] == '.')
        {
            grid[pos[0]][pos[1] + 1][0] = 'P';
            grid[pos[0]][pos[1]][0] = '.';
            pos[1] += 1;
        }
    }
    else if (move == 'q') // attack
    {
        // print attack menu
        cout << "pass" << endl;
    }
}

void DSKTurn(char grid[100][100][3], int DSKpos[], int pos[])
{
    // check if player is in range
    // if player is in range, attack

    // find direction to move
    // if player is above DSK
    if (DSKpos[0] - pos[0] > 0)
    {
        if (grid[DSKpos[0] - 1][DSKpos[1]][0] == '.')
        {
            // move up, DSKpos includes the space bellows it to the right, and bellow to the right
            // DSKpos[0] is the top left corner of the DSK
            // grid
            DSKpos[0] -= 1;
            grid[DSKpos[0]][DSKpos[1]][0] = 'K';
            grid[DSKpos[0] + 2][DSKpos[1]][0] = '.';
            grid[DSKpos[0]][DSKpos[1] + 1][0] = 'K';
            grid[DSKpos[0] + 2][DSKpos[1] + 1][0] = '.';
        }
    }
    // if player is below DSK
    else if (DSKpos[0] - pos[0] < 0)
    {
        if (grid[DSKpos[0] + 2][DSKpos[1]][0] == '.')
        {
            grid[DSKpos[0] + 2][DSKpos[1]][0] = 'K';
            grid[DSKpos[0]][DSKpos[1]][0] = '.';
            grid[DSKpos[0] + 2][DSKpos[1] + 1][0] = 'K';
            grid[DSKpos[0]][DSKpos[1] + 1][0] = '.';
            DSKpos[0] += 1;
        }
    }
    // if player is to the right of DSK
    else if (DSKpos[1] - pos[1] > 0)
    {
        if (grid[DSKpos[0]][DSKpos[1] - 1][0] == '.')
        {
            grid[DSKpos[0]][DSKpos[1] - 1][0] = 'K';
            grid[DSKpos[0]][DSKpos[1] + 1][0] = '.';
            grid[DSKpos[0] + 1][DSKpos[1] - 1][0] = 'K';
            grid[DSKpos[0] + 1][DSKpos[1] + 1][0] = '.';
            DSKpos[1] -= 1;
        }
    }
    // if player is to the left of DSK
    else if (DSKpos[1] - pos[1] < 0)
    {
        if (grid[DSKpos[0]][DSKpos[1] + 2][0] == '.')
        {
            grid[DSKpos[0]][DSKpos[1] + 2][0] = 'K';
            grid[DSKpos[0]][DSKpos[1]][0] = '.';
            grid[DSKpos[0] + 1][DSKpos[1] + 2][0] = 'K';
            grid[DSKpos[0] + 1][DSKpos[1]][0] = '.';
            DSKpos[1] += 1;
        }
    }
}