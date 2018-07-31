#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <list>

using namespace std;


const int COLUMNS = 5;
const int ROWS    = 3;
int grid[ROWS][COLUMNS];

void initializeGrid() {
    int p; //likelihood of any one cell coming to life

    srand(time(NULL)); // generate random seed
    for (int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            p = (rand() % 100) < 20; // 20% of cells shall be alive
            grid[row][col] = p;
        }
    }

}

void update() {

    vector<vector<int>> dead;
    vector<vector<int>> resurrect;
    
    for (int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {

            int left = col == 0 ? COLUMNS - 1 : (col - 1) % COLUMNS;
            int right = (col + 1) % COLUMNS;
            int top = row == 0 ? ROWS - 1 : (row - 1) % ROWS;
            int bot = (row + 1) % ROWS;

            int cellCount = 
                grid[top][col] + 
                grid[bot][col] +
                grid[row][left] +
                grid[row][right] +
                grid[top][left] +
                grid[top][right] +
                grid[bot][left] +
                grid[bot][right];
            
            if (cellCount < 2 || cellCount > 3) { // cell dies of under / overpopulation
                if (grid[row][col] != 0) { // ignore cell that are already dead
                    vector<int> d = {row, col};
                    dead.push_back(d);
                }
            } else if (cellCount == 3) { // call cell to life
                if (grid[row][col] != 1) {
                    vector<int> d = {row, col};
                    resurrect.push_back(d);
                }
            }
        }
    }


    for (vector<int> l : dead) {
        grid[l[0]][l[1]] = 0;
    }

    for (vector<int> l : resurrect) {
        grid[l[0]][l[1]] = 1;
    }
}

void display() {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            cout << grid[row][col];
        }
        cout << endl;
    }

    cout << endl;
}

int main() {
    initializeGrid();
    
    for(int i = 0; i < 1; i++) {
        display();
        update();
        display();
        cout << endl;
    }
    
    return 0;
}
