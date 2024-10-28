#ifndef PROBLEM_H
#define PROBLEM_H

#include "node.h"

int misplacedTileHeuristic(int state[N][N]);
int euclideanDistanceHeuristic(int state[N][N]);
int uniformCost(int state[N][N]);
bool isGoal(int state[N][N]);
void expand(int state[N][N], int nextStates[4][N][N], int* nextCount);

#endif