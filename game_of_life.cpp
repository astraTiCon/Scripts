#include <iostream>
#include <stdlib.h>
#include <ctime>
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
    //double for loop {
    //  int neighbours = 0;
    //  if grid[i +- 1][j +- 1] {
    //      neigbours += 1;  
    //  }
    //}
    // in between loops: record array indeces to operate on them later
    // after both loops: operate on recorded indeces
}

void display() {
    
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            cout << grid[row][col];
        }

        cout << endl;
        
    }
    
}

int main() {
    initializeGrid();
    
    for(int i = 0; i < 1; i++)
    {
        update();
        display();
        cout << endl;
    }
    
    return 0;
}
