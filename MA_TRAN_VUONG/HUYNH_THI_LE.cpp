#include <iostream>
#include <vector>
using namespace std;

// Hàm tính định thức của ma trận vuông
double determinant(vector<vector<double>>& matrix) {
    int size = matrix.size();

    if (size == 1) {
        return matrix[0][0];
    }

    double det = 0;

    for (int col = 0; col < size; col++) {
        vector<vector<double>> submatrix(size - 1, vector<double>(size - 1, 0.0));

        for (int i = 1; i < size; i++) {
            int subrow = 0;
            for (int j = 0; j < size; j++) {
                if (j != col) {
                    submatrix[i - 1][subrow++] = matrix[i][j];
                }
            }
        }

        double subdet = determinant(submatrix);
        det += matrix[0][col] * subdet * (col % 2 == 0 ? 1 : -1);
    }

    return det;
}

int main() {
    int size;

    cout << "Nhap kich thuoc cua ma tran vuong: ";
    cin >> size;

    vector<vector<double>> matrix(size, vector<double>(size, 0.0));

    cout << "Nhap cac phan tu cua ma tran:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    double det = determinant(matrix);

    cout << "Dinh thuc cua ma tran la: " << det << endl;

    return 0;
}
