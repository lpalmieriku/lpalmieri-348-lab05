/*
Author: Lena Palmieri
KUID: 3115099
Date: 10/9/24
Lab: lab05
Last Modified: 
Purpose: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSales(float nums[12], char months[12][10]) {
    int i = 0;
    printf("Monthly Sales Report for 2024\n\nMonth    \tSales\n");
    while (i < 12) {
        printf("%s\t%.2f\n", months[i], nums[i]);
        i++;
    }
}

void printSalesReport(float nums[12], char months[12][10]) {
    int i = 0, minpos, maxpos;
    float min = nums[0], max = nums[0], average = 0;
    while (i < 12) {
        if (min > nums[i]) {
            min = nums[i];
            minpos = i;
        }
        if (max < nums[i]) {
            max = nums[i];
            maxpos = i;
        }
        average += nums[i];
        i++;
    }
    average /= 12;
    printf("\nSales summary report:\n\nMinimum Sales: %.2f (%s)", min, months[minpos]);
}

int main() {
    char line[20];
    float nums[12];
    char months[12][10] = {"January  ", "February", "March    ", "April    ", "May     ", "June    ", "July    ", "August   ", "September", "October ", "November ", "December "};
    FILE* fptr;
    fptr = fopen("file.txt", "r");

    int i = 0;
    while(fgets(line, 12, fptr) != NULL) {
        nums[i] = strtof(line, NULL);
        i++;
    }
    fclose(fptr);

    printSales(nums, months);
    printSalesReport(nums, months);

    return 0;

}