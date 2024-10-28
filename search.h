#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"

Node* generalSearch(int initialState[N][N], int (*heuristicFunc)(int state[N][N]));

#endif