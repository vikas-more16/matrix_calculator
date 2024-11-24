#ifndef MYHEADER3_H
#define MYHEADER3_H

#include <stdio.h>

// Function declarations
void readMatrix(int row, int col, float Matrix[row][col]);
void printMatrix(int row, int col, float Matrix[row][col]);
void addmat(int SIZE, float firstMatrix[SIZE][SIZE], float secondMatrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]);
void submat(int SIZE, float firstMatrix[SIZE][SIZE], float secondMatrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]);
void multiplyMatrices(int row1, int col1, int row2, int col2, float firstMatrix[row1][col1], float secondMatrix[row2][col2], float resultMatrix[row1][col2]);
void mulMat(int SIZE, float firstMatrix[SIZE][SIZE], float secondMatrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]);
void scalerMul(int row, int col, float scaler, float Matrix[row][col], float resultMatrix[row][col]);
void squareMatrice(int SIZE, float Matrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]);
void cubeMatrix(int SIZE, float Matrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]);
void transposeMatrix(int row, int col, float Matrix[row][col], float resultMatrix[col][row]);
float detMatrix(int SIZE, float Matrix[SIZE][SIZE]);
void cofactorMatrix(int SIZE, float Matrix[SIZE][SIZE], float Cofactor[SIZE][SIZE]);
void adjoint(int SIZE, float matrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]);
void inverseMatrix(int SIZE, float Matrix[SIZE][SIZE], float Inverse[SIZE][SIZE]);

// Function to read a matrix of any order
void readMatrix(int row, int col, float Matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter a%d%d : ", i + 1, j + 1);
            scanf("%f", &Matrix[i][j]);
        }
    }
}

// Function to print a matrix of any order
void printMatrix(int row, int col, float Matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.2f ", Matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the addition of matrices

void addmat(int SIZE, float firstMatrix[SIZE][SIZE], float secondMatrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

// Function to calculate the subtraction of matrices

void submat(int SIZE, float firstMatrix[SIZE][SIZE], float secondMatrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }
}

// Function to calculate the multiplication of matrices
void multiplyMatrices(int row1, int col1, int row2, int col2, float firstMatrix[row1][col1], float secondMatrix[row2][col2], float resultMatrix[row1][col2]) {
    if (col1 == row2) {
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col2; j++) {
                resultMatrix[i][j] = 0;
                for (int k = 0; k < col1; k++) {
                    resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                }
            }
        }
    } else {
        printf("Multiplication is not possible\n");
    }
}

// Function to multiply two matrices of the same order

void mulMat(int SIZE, float firstMatrix[SIZE][SIZE], float secondMatrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]) {
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            resultMatrix[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// Function to perform scalar multiplication on a matrix

void scalerMul(int row, int col, float scaler, float Matrix[row][col], float resultMatrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            resultMatrix[i][j] = scaler * Matrix[i][j];
        }
    }
}

// Function to calculate the square of a matrix

void squareMatrice(int SIZE, float Matrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                resultMatrix[i][j] += Matrix[i][k] * Matrix[k][j];
            }
        }
    }
}

// Function to calculate the cube of a matrix

void cubeMatrix(int SIZE, float Matrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]) {
    float temMatrix[SIZE][SIZE];

    // First, compute the square of the matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temMatrix[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                temMatrix[i][j] += Matrix[i][k] * Matrix[k][j];
            }
        }
    }

    // Then, multiply the result with the original matrix to compute the cube
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                resultMatrix[i][j] += temMatrix[i][k] * Matrix[k][j];
            }
        }
    }
}


// Function to calculate the transpose of a matrix
void transposeMatrix(int row, int col, float Matrix[row][col], float resultMatrix[col][row]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            resultMatrix[j][i] = Matrix[i][j];
        }
    }
}

// Function to calculate the determinant of a square matrix
float detMatrix(int SIZE, float Matrix[SIZE][SIZE]) {
    float det = 0;
    float subMatrix[SIZE - 1][SIZE - 1];
    if (SIZE == 1) {
        return Matrix[0][0];
    }
    if (SIZE == 2) {
        return (Matrix[0][0] * Matrix[1][1]) - (Matrix[0][1] * Matrix[1][0]);
    }
    for (int x = 0; x < SIZE; x++) {
        int subRow = 0;
        for (int i = 1; i < SIZE; i++) {
            int subCol = 0;
            for (int j = 0; j < SIZE; j++) {
                if (j == x) continue;
                subMatrix[subRow][subCol] = Matrix[i][j];
                subCol++;
            }
            subRow++;
        }
        float subDet = detMatrix(SIZE - 1, subMatrix);
        det += (x % 2 == 0 ? 1 : -1) * Matrix[0][x] * subDet;
    }
    return det;
}

// Function to calculate the cofactor matrix of a square matrix

void cofactorMatrix(int SIZE, float Matrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]) {
    float subMatrix[SIZE - 1][SIZE - 1];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int subRow = 0;
            for (int x = 0; x < SIZE; x++) {
                if (x == i) continue;
                int subCol = 0;
                for (int y = 0; y < SIZE; y++) {
                    if (y == j) continue;
                    subMatrix[subRow][subCol] = Matrix[x][y];
                    subCol++;
                }
                subRow++;
            }
            resultMatrix[i][j] = detMatrix(SIZE - 1, subMatrix); // Calling determinant function to compute cofactor value
            if ((i + j) % 2 != 0) { 
                resultMatrix[i][j] = -resultMatrix[i][j];  // Alternate signs for cofactors
            }
        }
    }
}


// Function to calculate the adjoint of a matrix
void adjoint(int SIZE, float matrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]) {
    float temp[SIZE - 1][SIZE - 1];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int subRow = 0;
            for (int x = 0; x < SIZE; x++) {
                if (x == i) continue;
                int subCol = 0;
                for (int y = 0; y < SIZE; y++) {
                    if (y == j) continue;
                    temp[subRow][subCol] = matrix[x][y];
                    subCol++;
                }
                subRow++;
            }
            resultMatrix[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * detMatrix(SIZE - 1, temp);
        }
    }
}


// Function to calculate the inverse of a square matrix
void inverseMatrix(int SIZE, float Matrix[SIZE][SIZE], float resultMatrix[SIZE][SIZE]) {
    float det = detMatrix(SIZE, Matrix);
    if (det == 0) {
        printf("Matrix is singular, inverse cannot be calculated.\n");
        return;
    }

    float adj[SIZE][SIZE];
    adjoint(SIZE, Matrix, adj);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            resultMatrix[i][j] = adj[i][j] * (1.0 / det);
        }
    }
}





// Function to display the menu and handle user choices
void menu() {
    int choice;
    int SIZE;
    int row1, col1, row2, col2;
    printf("Matrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("4. Multiply Square Matrices\n");
    printf("5. Scalar Multiplication\n");
    printf("6. Square of a Matrix\n");
    printf("7. Cube of a Matrix\n");
    printf("8. Transpose of a Matrix\n");
    printf("9. Determinant of a Matrix\n");
    printf("10. Cofactor Matrix\n");
    printf("11. Adjoint of a Matrix\n");
    printf("12. Inverse of a Matrix\n");
    printf("13. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float firstMatrix[SIZE][SIZE], secondMatrix[SIZE][SIZE], resultMatrix[SIZE][SIZE];
            printf("Enter first matrix:\n");
            readMatrix(SIZE, SIZE, firstMatrix);
            printf("Enter second matrix:\n");
            readMatrix(SIZE, SIZE, secondMatrix);
            addmat(SIZE, firstMatrix, secondMatrix, resultMatrix);
            printf("Result of matrix addition:\n");
            printMatrix(SIZE, SIZE, resultMatrix);
            break;
        }
        case 2: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float firstMatrix[SIZE][SIZE], secondMatrix[SIZE][SIZE], resultMatrix[SIZE][SIZE];
            printf("Enter first matrix:\n");
            readMatrix(SIZE, SIZE, firstMatrix);
            printf("Enter second matrix:\n");
            readMatrix(SIZE, SIZE, secondMatrix);
            submat(SIZE, firstMatrix, secondMatrix, resultMatrix);
            printf("Result of matrix subtraction:\n");
            printMatrix(SIZE, SIZE, resultMatrix);
            break;
        }
        case 3: {
            printf("Enter number of rows and columns for first matrix: ");
            scanf("%d%d", &row1, &col1);
            printf("Enter number of rows and columns for second matrix: ");
            scanf("%d%d", &row2, &col2);
            if (col1 != row2) {
                printf("Multiplication not possible. Number of columns in first matrix must equal number of rows in second matrix.\n");
                break;
            }
            float firstMatrix[row1][col1], secondMatrix[row2][col2], resultMatrix[row1][col2];
            printf("Enter first matrix:\n");
            readMatrix(row1, col1, firstMatrix);
            printf("Enter second matrix:\n");
            readMatrix(row2, col2, secondMatrix);
            multiplyMatrices(row1, col1, row2, col2, firstMatrix, secondMatrix, resultMatrix);
            printf("Result of matrix multiplication:\n");
            printMatrix(row1, col2, resultMatrix);
            break;
        }
        case 4: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float firstMatrix[SIZE][SIZE], secondMatrix[SIZE][SIZE], resultMatrix[SIZE][SIZE];
            printf("Enter first matrix:\n");
            readMatrix(SIZE, SIZE, firstMatrix);
            printf("Enter second matrix:\n");
            readMatrix(SIZE, SIZE, secondMatrix);
            mulMat(SIZE, firstMatrix, secondMatrix, resultMatrix);
            printf("Result of matrix multiplication:\n");
            printMatrix(SIZE, SIZE, resultMatrix);
            break;
        }
        case 5: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float matrix[SIZE][SIZE], resultMatrix[SIZE][SIZE];
            float scalar;
            printf("Enter scalar value: ");
            scanf("%f", &scalar);
            printf("Enter matrix:\n");
            readMatrix(SIZE, SIZE, matrix);
            scalerMul(SIZE, SIZE, scalar, matrix, resultMatrix);
            printf("Result of scalar multiplication:\n");
            printMatrix(SIZE, SIZE, resultMatrix);
            break;
        }
        case 6: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float matrix[SIZE][SIZE], resultMatrix[SIZE][SIZE];
            printf("Enter matrix:\n");
            readMatrix(SIZE, SIZE, matrix);
            squareMatrice(SIZE, matrix, resultMatrix);
            printf("Square of the matrix:\n");
            printMatrix(SIZE, SIZE, resultMatrix);
            break;
        }
        case 7: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float matrix[SIZE][SIZE], resultMatrix[SIZE][SIZE];
            printf("Enter matrix:\n");
            readMatrix(SIZE, SIZE, matrix);
            cubeMatrix(SIZE, matrix, resultMatrix);
            printf("Cube of the matrix:\n");
            printMatrix(SIZE, SIZE, resultMatrix);
            break;
        }
        case 8: {
            printf("Enter matrix size (rows and columns): ");
            scanf("%d%d", &row1, &col1);
            float matrix[row1][col1], resultMatrix[col1][row1];
            printf("Enter matrix:\n");
            readMatrix(row1, col1, matrix);
            transposeMatrix(row1, col1, matrix, resultMatrix);
            printf("Transpose of the matrix:\n");
            printMatrix(col1, row1, resultMatrix);
            break;
        }
        case 9: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float matrix[SIZE][SIZE];
            printf("Enter matrix:\n");
            readMatrix(SIZE, SIZE, matrix);
            printf("Determinant: %.2f\n", detMatrix(SIZE, matrix));
            break;
        }
        case 10: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float matrix[SIZE][SIZE], cofactor[SIZE][SIZE];
            printf("Enter matrix:\n");
            readMatrix(SIZE, SIZE, matrix);
            cofactorMatrix(SIZE, matrix, cofactor);
            printf("Cofactor matrix:\n");
            printMatrix(SIZE, SIZE, cofactor);
            break;
        }
        case 11: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float matrix[SIZE][SIZE], adj[SIZE][SIZE];
            printf("Enter matrix:\n");
            readMatrix(SIZE, SIZE, matrix);
            adjoint(SIZE, matrix, adj);
            printf("Adjoint matrix:\n");
            printMatrix(SIZE, SIZE, adj);
            break;
        }
        case 12: {
            printf("Enter matrix size: ");
            scanf("%d", &SIZE);
            float matrix[SIZE][SIZE], inverse[SIZE][SIZE];
            printf("Enter matrix:\n");
            readMatrix(SIZE, SIZE, matrix);
            inverseMatrix(SIZE, matrix, inverse);
            printf("Inverse matrix:\n");
            printMatrix(SIZE, SIZE, inverse);
            break;
        }
        case 13:
            printf("Exiting program.\n");
            return;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

void runMenu() {
    char runAgain;
    do {
        menu();
        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &runAgain);

        // Clear the input buffer to handle any leftover characters
        while (getchar() != '\n');  

    } while (runAgain == 'y' || runAgain == 'Y');

    printf("Thank you for using the program. Goodbye!\n");
}


#endif
