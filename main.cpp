#include "proto.h"

int main()
{

    char grid[100][100][3];
    int pos[2] = {-1, -1};
    int DSKpos[2] = {-1, -1};
    initialize(grid);
    initializePlayer(grid, pos);
    initializeDSK(grid, DSKpos);
    bool game = true;
    bool Pturn = true;
    while (game)
    {
        // system("clear");
        print(grid, pos);
        // Pturn = true; // testing purposes
        if (Pturn)
        {
            for (int i = 0; i < 2; i++)
            {
                playerTurn(grid, pos);
                Pturn = false;
            }
            
        }
        else
        {
            DSKTurn(grid, DSKpos, pos);
            Pturn = true;
        }
    }

    return 0;
}