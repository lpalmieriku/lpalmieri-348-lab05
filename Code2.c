/*
Author: Lena Palmieri
KUID: 3115099
Date: 10/11/24
Lab: lab05
Last Modified: 
Purpose: 
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int **addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    int **sum;

    sum = malloc(sizeof(int *) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        sum[i] = malloc(sizeof(int) * SIZE);
    }


    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            sum[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }

    return sum;
}

int **multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int **product;

    product = malloc(sizeof(int *) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        product[i] = malloc(sizeof(int) * SIZE);
    }

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            int sum = 0;
            for (int x = 0; x < SIZE; x++) {
                sum += (m1[row][x] * m2[x][col]);
            }
            product[row][col] = sum;
        }
    }

    return product;

}

int **transposeMatrix(int mat[SIZE][SIZE]) {
    int **transpose;

    transpose = malloc(sizeof(int *) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        transpose[i] = malloc(sizeof(int) * SIZE);
    }

    for  (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {

            transpose[row][col] = mat[col][row];
        }
    }

    return transpose;
}

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
    int **totalSum, **totalProduct, **mattranspose;

    
    if(sizeof(m1)/sizeof(m1[0]) == sizeof(m2)/sizeof(m2[0]) && sizeof(m1[0])/sizeof(m1[0][0]) == sizeof(m2[0])/sizeof(m2[0][0])) {
        totalSum = addMatrices(m1,m2);
        printMatrix(totalSum);
    }
    else {
        printf("Invalid operation! The matrices are not the same size!");
    }

    if(sizeof(m1)/sizeof(m1[0]) == sizeof(m2[0])/sizeof(m2[0][0])) {
        totalProduct = multiplyMatrices(m1,m2);
        printMatrix(totalProduct);

    }
    else {
        printf("Invalid operation! The 1st matrix number of rows does not equal to the 2nd matrix number of columns.");
    }

    if(sizeof(m1)/sizeof(m1[0]) == sizeof(m2[0])/sizeof(m2[0][0])) {
        mattranspose = transposeMatrix(m1);
        printMatrix(mattranspose);

    }
    else {
        printf("Invalid operation! The 1st matrix number of rows does not equal to the 2nd matrix number of columns.");
    }

}