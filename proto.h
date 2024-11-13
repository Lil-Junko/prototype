#ifndef PROTO_H
#define PROTO_H

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void initialize(char grid[100][100][3]);
void initializePlayer(char grid[100][100][3], int pos[]);
void initializeDSK(char grid[100][100][3], int DSKpos[]);
void print(char grid[100][100][3], int pos[]);
void playerTurn(char grid[100][100][3], int pos[]); //player
void DSKTurn(char grid[100][100][3], int DSKpos[], int pos[]); //deep sea knight


#endif // PROTO_H