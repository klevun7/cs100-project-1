#include "node.h"
#include <iostream>

using namespace std;

Node::Node(int initState[N][N], Node* parentNode, int c, int h) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            state[i][j] = initState[i][j];
        }
    }
    
    parent = parentNode;
    cost = c;
    heuristic = h;
}

void Node::printSolution() const {
    if (parent != nullptr) {
        parent->printSolution();
    }
    
    cout << "Step:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << state[i][j] << " ";
        }
        cout << endl;
        
    }
    cout << "g(n) = " << cost << ", h(n) = " << heuristic << endl;
    cout << endl;


}