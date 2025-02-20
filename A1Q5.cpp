//Rotate Matrix 90 Degrees

#include <iostream>
using namespace std;

void rotateMatrix(int n, int matrix[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

void printMatrix(int n, int matrix[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    int matrix[100][100];
    
    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    rotateMatrix(n, matrix);
    cout << "Rotated Matrix (90 degrees clockwise): " << endl;
    printMatrix(n, matrix);
    
    return 0;
}
