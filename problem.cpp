#include "problem.h"

int misplacedTileHeuristic(int state[N][N]) {}

int euclideanDistanceHeuristic(int state[N][N]) {}

int uniformCostHeuristic(int state[N][N]) {}

bool isGoal(int state[N][N]) {}

void expand(int state[N][N], int nextStates[4][N][N], int* nextCount) {
    int blankX;
    int blankY;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (state[i][j] == 0) {
                blankX = i;
                blankY = j;
            }
        }
    }

    *nextCount = 0;

    if (blankX > 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                nextStates[*nextCount][i][j] = state[i][j];
            }
        }

        nextStates[*nextCount][blankX][blankY] = state[blankX - 1][blankY];
        nextStates[*nextCount][blankX - 1][blankY] = 0;
        *nextCount = *nextCount + 1;
    }

    if (blankX < N - 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                nextStates[*nextCount][i][j] = state[i][j];
            }
        }

        nextStates[*nextCount][blankX][blankY] = state[blankX + 1][blankY];
        nextStates[*nextCount][blankX + 1][blankY] = 0;
        *nextCount = *nextCount + 1;
    }

    if (blankY > 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                nextStates[*nextCount][i][j] = state[i][j];
            }
        }

        nextStates[*nextCount][blankX][blankY] = state[blankX][blankY - 1];
        nextStates[*nextCount][blankX][blankY - 1] = 0;
        *nextCount = *nextCount + 1;
    }

    if (blankY < N - 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                nextStates[*nextCount][i][j] = state[i][j];
            }
        }
                
        nextStates[*nextCount][blankX][blankY] = state[blankX][blankY + 1];
        nextStates[*nextCount][blankX][blankY + 1] = 0;
        *nextCount = *nextCount + 1;
    }
}