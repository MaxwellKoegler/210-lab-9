#include <fstream>
#include <array>
#include <string>

using namespace std;

const int SIZE = 4;

int main() {
    ifstream file("matrix.txt");

    array<array<int, SIZE>, SIZE> matrix;
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            file >> matrix[row][col];
        }
    }

    


}
