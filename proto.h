#ifndef PROTO_H
#define PROTO_H

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

void initialize(char grid[100][100][4]);
void initializelevel(char grid[100][100][4]);
void initializePlayer(char grid[100][100][4], int pos[]);
void initializeDSK(char grid[100][100][4], int DSKpos[]);
void print(char grid[100][100][4], int pos[]);
void playerTurn(char grid[100][100][4], int pos[]); //player
void DSKTurn(char grid[100][100][4], int DSKpos[], int pos[]); //deep sea knight
int typecheck(string line);
int action(string line);


#endif // PROTO_H