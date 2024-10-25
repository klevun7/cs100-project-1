#ifndef NODE_H
#define NODE_H

const int N = 3;        // Change to dimension of desired puzzle size

struct Node {
    int state[N][N];
    Node* parent;
    int cost;           // g(x)
    int heuristic;      // h(x)

    Node(int initState[N][N], Node* parentNode, int c, int h);
    void printSolution() const;
};

#endif