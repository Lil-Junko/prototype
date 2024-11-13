#include "proto.h"

/*
 * Create a new game
 * 100 by 100 by 3 grid
 * for grid[][][0]:
 * place player in a random side on the right
 * place deep sea knight on the left
 * add obstacles around the map
 * make sure player can move around and reach enemy
 * when deep sea knight is defeated, move to next level
 * display "stage complete" message
 * for grid[][][1]:
 * place player in a random side on the right
 * place deep sea knight on the left
 * modify deep sea knight, at half health switch to stage 2 of boss
 * when deep sea knight is defeated, move to next level
 * display "stage complete" message
 * for grid[][][2]:
 * place player in a random side on the right
 * place deep sea knight on the left
 * modify deep sea knight, starts boss at stage 2
 * after defeating boss, game is won
 * display "Foe slain" message
 */

/*
 * display:
 * a 19 by 19 grid with player in the middle
 * player can move up(w), down(s), left(a), right(d) twice on their turn or attack(e) once
 * attack brings up a menu of attack options
 * player uses SP for certain attacks
 * player can use items(i) to heal or buff
 * player can place traps(t) to damage enemies
 */

/*
 * deep sea knight:
 * takes up a 2x2 space
 * enemy can move up, down, left, right, or attack
 * enemy can attack player if player is in range
 * enemy can move towards player if player is out of range
 * attacks:
 *  - anchor tap: no cooldown or SP cost pushes player back 1 space, if pushed into a hole, player dies
 *  - crushing anchor swing: uses 10 SP and cooldown 5 turns, standard hit size. Instant kills player if hits
 *  - anchor thrust: uses 5 SP hits 3 spaces in front of deep sea knight, 2 diganally, pushes player back 1 space, if pushed into a hole, player dies
 *  second phase attacks:
 *  - Carpenter's song: uses 15 SP and cooldown 3 turns, hits player 10 spaces away inflicts stun
 *    ~ stun: player cannot move or attack for 1 turn
 *  - walrus's blessing: uses 20 SP and cooldown 5 turns, gives deep sea knigh
 *    ~ attack up: increases damage by 10% for 3 turns
 *    ~ defense up: decreases damage taken by 10% for 3 turns
 *    ~ speed up: decreased time for a turn by half for 3 turns
 */

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