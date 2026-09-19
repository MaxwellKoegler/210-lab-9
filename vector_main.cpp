// COMSC-210 | Lab 9 | Maxwell Koegler
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;

const int SIZE = 6;

//this program takes a square matrix of size SIZE, transposes it, identifies if its
//symetrical and then makes a constant matrix consisting of the element average
//this program is the vector implementation, the array implementation is in
//array_main.cpp
int main() {
    ifstream file("matrix.txt"); //SIZE X SIZE square int matrix

    vector<vector<int>> matrix(SIZE, vector<int>(SIZE)); //2d int vector 
    for(int row = 0; row < SIZE; row++) { //population
        for(int col = 0; col < SIZE; col++) {
            file >> matrix[row][col];
        }
    }

    vector<vector<int>> transpose(SIZE, vector<int>(SIZE)); //2d int transposed vector
    for(int row = 0; row < SIZE; row++) { //transposing
        for(int col = 0; col < SIZE; col++) {
            transpose[col][row] = matrix[row][col];
        }
    }

    //matrix printing
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
    cout << " a symmetrical matrix" << endl << endl;
    cout << "Here is a constant double matrix filled with the average of our initial matrix: " << endl;

    //average calculation
    int total = 0;
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            total += transpose[row][col];
        }
    }

    double average = static_cast<double>(total) / (SIZE*SIZE); //because the matrix is square
    vector<vector<double>> constMatrix(SIZE, vector<double>(SIZE));

    //matrix population
    for(int row = 0; row < SIZE; row++) {
        fill(constMatrix.at(row).begin(), constMatrix.at(row).end(), average);

    }

    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            cout << constMatrix[row].at(col) << " ";
        }
        cout << endl;
    }
}