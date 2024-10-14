/*
Author: Lena Palmieri
KUID: 3115099
Date: 10/11/24
Lab: lab05
Last Modified: 10/13/24
Purpose: Initializes 2 matrices and asks the user if they want to perform an operation on the matrices. 
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

//Function that creates a pointer for a matrix and allocates memory for that pointer
int **createPointer() {
    int **matrix;
    matrix = malloc(sizeof(int *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        matrix[i] = malloc(sizeof(int) * SIZE);
    }
    return matrix;
}

//Function that takes in 2 matrices and returns the sum of the 2 matrices
int **addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    int **sum = createPointer();
    //Iterates by row and column, adding the elements together from matrix 1 and 2 and assigning it the same position in sum
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            sum[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }

    return sum;
}

//Function that takes in 2 matrices and returns the product of the 2 matrices
int **multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int **product = createPointer();
    //Iterates by row and column to get to the correct position in the product matrix
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            int sum = 0;
            //Iterates over the entire row in the first matrix and column in the second matrix, multiplying the values together and then adding them to the total
            //This value is then assigned to the corresponding element in the matrix
            for (int x = 0; x < SIZE; x++) {
                sum += (m1[row][x] * m2[x][col]);
            }
            product[row][col] = sum;
        }
    }

    return product;

}

//Function that takes in a matrix and prints its transposition
int **transposeMatrix(int mat[SIZE][SIZE]) {
    int **transpose = createPointer();
    //Iterates by row and column and assigns the element in the transposition matrix to the opposite element in the given matrix
    for  (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {

            transpose[row][col] = mat[col][row];
        }
    }

    return transpose;
}

//Functions that takes in a matrix and prints out all the elements
void printMatrix(int **mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    //Initializes both matrices using size and creates the pointers for those matrices
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };
    int **mat1 = createPointer(), **mat2 = createPointer();

    //Assigns the values of the defined matrices to its pointers
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            mat1[row][col] = m1[row][col];
            mat2[row][col] = m2[row][col];
        }
    }
    int choice = 0, option = 0;
    //Prints out both matrices that will have operations performed on them
    printf("Matrix 1:\n");
    printMatrix(mat1);
    printf("Matrix 2:\n");
    printMatrix(mat2);
    //Asks the user to choose an operation to perform on the matrices
    printf("Choose the operation you would like to perform on the matrices (1)Add Matrices, (2)Multiply Matrices, (3)Transpose Matrix, (4)Print Matrix, (5)Exit: ");
    scanf("%d", &choice);
    //Starts a loop for the user to keep choosing operations until they want to stop
    while (choice != 5) {

        //Runs if the user chooses operation 1
        //Checks if the matrices are the same size, then adds them together and prints the result
        if (choice == 1) {
            int **totalSum;
            if(sizeof(m1)/sizeof(m1[0]) == sizeof(m2)/sizeof(m2[0]) && sizeof(m1[0])/sizeof(m1[0][0]) == sizeof(m2[0])/sizeof(m2[0][0])) {
                totalSum = addMatrices(m1,m2);
                printMatrix(totalSum);
            }
            else {
                printf("Invalid operation! The matrices are not the same size!\n");
            }
        }
        //Runs if the user chooses operation 2
        //Checks if matrix 1 has the same row size as matrix 2 has column size, then multiplies them together and prints the result
        else if (choice == 2) {
            int **totalProduct;
            if(sizeof(m1)/sizeof(m1[0]) == sizeof(m2[0])/sizeof(m2[0][0])) {
                totalProduct = multiplyMatrices(m1,m2);
                printMatrix(totalProduct);

            }
            else {
                printf("Invalid operation! The 1st matrix number of rows does not equal to the 2nd matrix number of columns.\n");
            }
        }
        //Runs if the user chooses operation 3
        //Asks the user which matrix they would like to transpose
        //Checks if the matrix has the same number of rows and columns, then flips the rows and columns and prints the result
        else if (choice == 3) {
            int **mattranspose;
            printf("Which matrix would you like to transpose? (1) or (2): ");
            scanf("%d", &option);
            if (option == 1) {
                if(sizeof(m1)/sizeof(m1[0]) == sizeof(m1[0])/sizeof(m1[0][0])) {
                    mattranspose = transposeMatrix(m1);
                    printMatrix(mattranspose);
                }
                else {
                    printf("Invalid operation! The 1st matrix number of rows does not equal the 2nd matrix number of columns.\n");
                }
            }
            else if (option == 2) {
                if(sizeof(m2)/sizeof(m2[0]) == sizeof(m2[0])/sizeof(m2[0][0])) {
                    mattranspose = transposeMatrix(m2);
                    printMatrix(mattranspose);
                }
                else {
                    printf("Invalid operation! The 1st matrix number of rows does not equal the 2nd matrix number of columns.\n");
                }
            }
            else {
                printf("No matrix is associated to that number!\n");
            }
        }
        //Runs if the user chooses operation 4
        //Asks the user which matrix they would like to print out then prints out the corresponding matrix
        else if (choice == 4) {
            printf("Which matrix would you like to print? (1) or (2): ");
            scanf("%d", &option);
            if (option == 1) {
                printMatrix(mat1);
            }
            else if (option == 2) {
                printMatrix(mat2);
            }
            else {
                printf("No matrix is associated to that number!\n");
            }
        }
        //Prints out an error message if the user inputs an invalid operation
        else {
            printf("Invalid choice! Please choose a different option.\n");
        }
        //Asks the user to input a new operation
        printf("Choose the operation you would like to perform on the matrices (1)Add Matrices, (2)Multiply Matrices, (3)Transpose Matrix, (4)Print Matrix, (5)Exit: ");
        scanf("%d", &choice);
    }

}