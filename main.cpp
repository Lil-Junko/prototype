#include "proto.h"

int main()
{
    //initialize game from file
    //initialize game from file
    string line;
    ifstream myfile("test.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            //do perform each action
            if (typecheck(line) == 1) //action
            {
                int act = action(line);
                if (act == 1)
                {
                    cout << "a door opened" << endl;
                }
                else if (act == 2)
                {
                    cout << "a chest unlocked" << endl;
                }
                else if (act == 3)
                {
                    cout << "a stranger approaches" << endl;
                }
            }
            else if (typecheck(line) == 2) //dialogue
            {
                //read out full dialogue
                getline(myfile, line); //skip the dialogue line
                do
                {
                    cout << "dialogue: " << line << endl;
                    getline(myfile, line);
                } while (line[0] != '/');
            }
            else
            {
                cout << "error: " << line << endl;
            }

        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    //start game loop
    
    char grid[100][100][4];
    int pos[2] = {-1, -1};
    int DSKpos[2] = {-1, -1};
    initialize(grid);
    initializelevel(grid);
    initializePlayer(grid, pos);
    // initializeDSK(grid, DSKpos);
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