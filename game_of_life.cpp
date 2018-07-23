#include <iostream>
#include <stdlib.h>
using namespace std;


const int COLUMNS = 5;
const int ROWS    = 3;
int grid[ROWS][COLUMNS];

void initializeGrid() {
    int p; //likelihood of any one cell coming to life

    for (int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            p = rand();
            grid[row][col] = 0; //TODO: randomly insert either 0 or 1
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
