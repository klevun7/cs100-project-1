#include "search.h"
#include "problem.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "Welcome to dchau029/klevun7 8 puzzle solver." << endl;
    
    int choice;
    int initialState[N][N]; 
    
    while(true) {
        cout << "Type “1” to use a default puzzle, or “2” to enter your own puzzle." << endl;
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            int defaultPuzzle[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    initialState[i][j] = defaultPuzzle[i][j];
                }
            }
            break;
        }
        else if (choice == 2) {
            cout << "Enter your puzzle, use a zero to represent the blank" << endl;

            for (int i = 0; i < N; i++) {
                cout << "Enter row " << (i + 1) << ", separate numbers with spaces or tabs: ";
                bool validRow = true;

                for (int j = 0; j < N; j++) {
                    cin >> initialState[i][j];
                    if (cin.fail() || initialState[i][j] < 0 || initialState[i][j] > 8) {
                        validRow = false;
                        cout << "Invalid input. Please enter three integers between 0 and 8." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                }

                if (!validRow) {
                    i = i - 1;
                }
            }
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int (*heuristicFunc)(int[N][N]) = nullptr;

    while (true) {
        cout << "Enter your choice of algorithm:" << endl;
        cout << "1. Uniform Cost Search" << endl;
        cout << "2. A* with the Misplaced Tile heuristic." << endl;
        cout << "3. A* with the Euclidean distance heuristic." << endl;
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            heuristicFunc = uniformCost;
            break;
        } 
        else if (choice == 2) {
            heuristicFunc = misplacedTileHeuristic;
            break;
        } 
        else if (choice == 3) {
            heuristicFunc = euclideanDistanceHeuristic;
            break;
        } 
        else {
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node* result = generalSearch(initialState, heuristicFunc);

    if (result != nullptr) {
        result->printSolution();
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}