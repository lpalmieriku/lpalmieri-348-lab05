/*
Author: Lena Palmieri
KUID: 3115099
Date: 10/9/24
Lab: lab05
Last Modified: 10/12/24
Purpose: Program reads a file input for the sales of 12 months and prints the statistics of those sales. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function that prints all of the sales for each month
void printSales(float nums[12], char months[12][10]) {
    int i = 0;
    printf("Monthly Sales Report for 2024\n\nMonth    \tSales\n");
    //Loops through each index for every month and prints out the corresponding sales and month from each array
    while (i < 12) {
        printf("%s\t$%.2f\n", months[i], nums[i]);
        i++;
    }
}

//Function that prints out the minimum, maximum, and average sales for the year
void printSalesReport(float nums[12], char months[12][10]) {
    int i = 0, minpos = 0, maxpos = 0;
    float min = nums[0], max = nums[0], average = 0;
    //Loops through each index for every month and checks whether that value is the minimum or maximum for the year
    //If it is, it stores both the value and position of that month
    while (i < 12) {
        if (min > nums[i]) {
            min = nums[i];
            minpos = i;
        }
        if (max < nums[i]) {
            max = nums[i];
            maxpos = i;
        }
        //Adds each of the months sale's to the average and then divides it by 12 to get the average sales of the year
        average += nums[i];
        i++;
    }
    average /= 12;
    printf("\nSales summary report:\n\nMinimum Sales: $%.2f in %s\nMaximum Sales: $%.2f in %s\nAverage Sales: $%.2f\n", min, months[minpos], max, months[maxpos], average);
}


//Function that prints out the six-month average report for each six-month interval of the year
void printSixMonths(float nums[12]) {
    printf("\nSix-month moving average report:\n\n");
    //Loops through the 6 six-month intervals calculating the average throughout the six months
    for(int i = 0; i <= 6; i++) {
        float average = 0;
        for(int n = i; n < i + 6; n++) {
            average += nums[n];
        }

        //Checks which six-month interval it is and prints out the corresponding month range and average
        if (i == 0) {
            printf("January-June\t$%.2f\n", average/6);
        }
        else if (i == 1) {
            printf("February-July\t$%.2f\n", average/6);
        }
        else if (i == 2) {
            printf("March-August\t$%.2f\n", average/6);
        }
        else if (i == 3) {
            printf("April-September\t$%.2f\n", average/6);
        }
        else if (i == 4) {
            printf("May-October\t$%.2f\n", average/6);
        }
        else if (i == 5) {
            printf("June-November\t$%.2f\n", average/6);
        }
        else if (i == 6) {
            printf("July-December\t$%.2f\n\n", average/6);
        }
    }
}

//Function that prints out the month sales in order from highest to lowest
void printHighLow(float nums[12], char months[12][10]) {
    printf("Sales report (highest to lowest)\n\nMonth    \tSales\n");
    int count = 0;
    //Loops through each of the 12 months, checking for the maximum value in the list
    while (count < 12) {
        float max = nums[0];
        int maxpos = 0;
        for (int x = 0; x < 12; x++) {
            //Once max value is found, it and its position is stored 
            if (max < nums[x]) {
                max = nums[x];
                maxpos = x;
            }
        }
        //Once the next highest sale has been found, the value in that position of the array is set to -1 and the maximum sale and its corresponding month are printed
        nums[maxpos] = -1;
        count++;
        printf("%s\t$%.2f\n", months[maxpos], max);
    }
}

int main() {
    char line[20], filename[100];
    float nums[12];
    char months[12][10] = {"January  ", "February", "March    ", "April    ", "May     ", "June    ", "July    ", "August   ", "September", "October ", "November ", "December "};
    //Initializes the pointer value for the file, asks user for the file name, and opens the input file to read
    FILE* fptr;
    printf("What is the name of the input file would you like to read from: ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");

    int i = 0;
    //Loops through each line of the input file, storing the floats in an array
    while(fgets(line, 12, fptr) != NULL) {
        nums[i] = strtof(line, NULL);
        i++;
    }
    fclose(fptr);

    //Runs each statistics function, taking in the sales of each month and the month names as parameters
    printSales(nums, months);
    printSalesReport(nums, months);
    printSixMonths(nums);
    printHighLow(nums, months);

    return 0;

}