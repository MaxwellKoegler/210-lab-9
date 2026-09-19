#include <fstream>
#include <array>
#include <iostream>
 
using namespace std;

const int SIZE = 6;

int main() {
    ifstream file("matrix.txt");

    array<array<int, SIZE>, SIZE> matrix;
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            file >> matrix[row][col];
        }
    }

    array<array<int, SIZE>, SIZE> transpose;
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            transpose[col][row] = matrix[row][col];
        }
    }

    cout << "original matrix read from the file: " << endl;

    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    cout << "matrix transpose: " << endl;

    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            cout << transpose[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Therefore the matrix in question is";
    if(matrix != transpose) {
        cout << " not";
    }
    cout << " a symmetrical matrix" << endl;
    cout << "The maximum value contained in this matrix is " << *max_element(matrix.begin(), matrix.end());
}
