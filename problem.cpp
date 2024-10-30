#include "problem.h"
#include <iostream>
#include <cmath>

int misplacedTileHeuristic(int state[N][N])
{
    int count = 0;
    int goalValue = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (state[i][j] != 0)
            {
                if (state[i][j] != goalValue)
                {
                    count++;
                }
            }
            goalValue = (goalValue + 1) % (N * N);
        }
    }
    return count;
}

int euclideanDistanceHeuristic(int state[N][N])
{
    int totalDistance = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (state[i][j] != 0)
            {
                int value = state[i][j] - 1;
                int goalI = value / N;
                int goalJ = value % N;

                int dx = i - goalI;
                int dy = j - goalJ;
                totalDistance += (int)sqrt(dx * dx + dy * dy);
            }
        }
    }
    return totalDistance;
}

int uniformCost(int state[N][N])
{
    return 0;
}

bool isGoal(int state[N][N])
{
    int expectedValue = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == N - 1 && j == N - 1)
            {
                if (state[i][j] != 0)
                {
                    return false;
                }
            }
            else if (state[i][j] != expectedValue)
            {
                return false;
            }
            expectedValue++;
        }
    }
    return true;
}

void expand(int state[N][N], int nextStates[4][N][N], int *nextCount)
{
    int blankX;
    int blankY;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (state[i][j] == 0)
            {
                blankX = i;
                blankY = j;
            }
        }
    }

    *nextCount = 0;

    if (blankX > 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                nextStates[*nextCount][i][j] = state[i][j];
            }
        }

        nextStates[*nextCount][blankX][blankY] = state[blankX - 1][blankY];
        nextStates[*nextCount][blankX - 1][blankY] = 0;
        *nextCount = *nextCount + 1;
    }

    if (blankX < N - 1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                nextStates[*nextCount][i][j] = state[i][j];
            }
        }

        nextStates[*nextCount][blankX][blankY] = state[blankX + 1][blankY];
        nextStates[*nextCount][blankX + 1][blankY] = 0;
        *nextCount = *nextCount + 1;
    }

    if (blankY > 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                nextStates[*nextCount][i][j] = state[i][j];
            }
        }

        nextStates[*nextCount][blankX][blankY] = state[blankX][blankY - 1];
        nextStates[*nextCount][blankX][blankY - 1] = 0;
        *nextCount = *nextCount + 1;
    }

    if (blankY < N - 1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                nextStates[*nextCount][i][j] = state[i][j];
            }
        }

        nextStates[*nextCount][blankX][blankY] = state[blankX][blankY + 1];
        nextStates[*nextCount][blankX][blankY + 1] = 0;
        *nextCount = *nextCount + 1;
    }
}