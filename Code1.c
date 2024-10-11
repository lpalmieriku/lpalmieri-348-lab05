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
        printf("%s\t$%.2f\n", months[i], nums[i]);
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
    printf("\nSales summary report:\n\nMinimum Sales: $%.2f in %s\nMaximum Sales: $%.2f in %s\nAverage Sales: $%.2f\n", min, months[minpos], max, months[maxpos], average);
}

void printSixMonths(float nums[12]) {
    printf("\nSix-month moving average report:\n\n");
    for(int i = 0; i <= 6; i++) {
        float average = 0;
        for(int n = i; n <= i + 6; n++) {
            average += nums[n];
        }

        if (i == 0) {
            printf("January-June\t%.2f\n", average/6);
        }
        else if (i == 1) {
            printf("February-July\t%.2f\n", average/6);
        }
        else if (i == 2) {
            printf("March-August\t%.2f\n", average/6);
        }
        else if (i == 3) {
            printf("April-September\t%.2f\n", average/6);
        }
        else if (i == 4) {
            printf("May-October\t%.2f\n", average/6);
        }
        else if (i == 5) {
            printf("June-November\t%.2f\n", average/6);
        }
        else if (i == 6) {
            printf("July-December\t%.2f\n", average/6);
        }
    }
}

void printHighLow(float nums[12], char months[12][10]) {
    printf("Sales report (highest to lowest)\n\nMonth    \tSales\n");
    int count = 0;
    while (count < 11) {
        float max = nums[0];
        int maxpos = 0;
        for (int x = 0; x < 12; x++) {
            if (max < nums[x]) {
                max = nums[x];
                maxpos = x;
            }
        }
        nums[maxpos] = -1;
        count++;
        printf("%s\t$%.2f\n", months[maxpos], max);
    }
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

    //printSales(nums, months);
    //printSalesReport(nums, months);
    //printSixMonths(nums);
    printHighLow(nums, months);

    return 0;

}