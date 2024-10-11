/*
Author: Lena Palmieri
KUID: 3115099
Date: 10/11/24
Lab: lab05
Last Modified: 
Purpose: 
*/

#include <stdio.h>
#define SIZE 5

addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    int* sum[SIZE][SIZE];

    int i = 0;
    while (i < 5) {
        int j = 0;
        while (j < 5) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            j++;
        }
        i++;
    }
    //printMatrix
}

int* multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int* product[SIZE][SIZE];

    int i = 0;
    while(i < 5) {
        int j = 0, sum = 0;
        while(j < 5) {
            j++;
        }
        i++;
    }
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

    if(sizeof(m1)/sizeof(m1[0]) == sizeof(m2)/sizeof(m2[0]) && sizeof(m1[0])/sizeof(m1[0][0]) == sizeof(m2[0])/sizeof(m2[0][0])) {
        addMatrices(m1,m2);
    }
    else {
        printf("Invalid operation! The matrices are not the same size!");
    }

    if(sizeof(m1)/sizeof(m1[0]) == sizeof(m2[0])/sizeof(m2[0][0])) {
        int* totalProduct = multiplyMatrices(m1,m2);
    }
    else {
        printf("Invalid operation! The 1st matrix number of rows does not equal to the 2nd matrix number of columns.");
    }

}