#include <fstream>
#include <array>
#include <iostream>
#include <algorithm>
 
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
            cout << matrix[row].at(col) << " "; //.at used for variety
        }
        cout << endl;
    }

    cout << "matrix transpose: " << endl;

    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            cout << transpose[row].at(col) << " ";
        }
        cout << endl;
    }

    //uses vector comparison and the definition of matrix symmetry to identify symetry
    cout << "Therefore the matrix in question is";
    if(matrix != transpose) {
        cout << " not";
    }
    cout << " a symmetrical matrix" << endl;

    cout << "Here is a constant double matrix filled with the average of our initial matrix";

    int total = 0;
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            total += transpose[row][col];
        }
        
    }

    double average = total / (SIZE*SIZE); //because the matrix is square
    array<array<double, SIZE>, SIZE> constMatrix;

    for(array<double, SIZE> row : constMatrix) {
        fill(row.begin(), row.end(),average);
    }

}
