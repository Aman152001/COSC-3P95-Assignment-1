#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Name Aman Yadav
Student 6858054
Question 2
Cosc 3P95
*/

//random array function allocates the array values randomly (rannging from 0 to 99) to our array.
void randomArr(int array[], int size, int stopAt) {
    srand(time(NULL));
    for (int k = 0; k < size; k++) {
        array[k] = rand() % 1000; //Randomly generate values from the range 0 to 990.
        //Break condition if array value equal to stopAt value we exit through the loop
        if (array[k] == stopAt) {
            printf("Array allocation stopped due to stopAt value: %d\n", stopAt);
            break;
        }
    }
}

//using bubble sort algorithm in order to sort the integers. In bubble sort we take 
void bubbleSort(int array[], int size) {
    for (int a = 0; a < size - 1;a++) {
       int ifSwapped = 0;
        for (int b = 0; b < size - a - 1; b++) {
            if (array[b] > array[b + 1]) {
                int temporary = array[b]; //swapping the both the array here
                array[b] = array[b + 1]; //moving 
                array[b + 1] = temporary;
                ifSwapped = 1;
            }
        }
        
        if (ifSwapped == 0) { //If no elements are swapped this means the array is already sorted and we do not perform the bubble sort.
            break;
        }
    }
}
int main() {
    srand(time(NULL));
    int maxArraySize = 100, sizeOfArray = rand() % maxArraySize + 1, testingArray[sizeOfArray], stopAt = 42; // Example break value
    // stopAt = rand() % 100; //Can also assign a random value where it will stop the allocating values to array
    // Generate random array with break condition
    randomArr(testingArray, sizeOfArray, stopAt);
    printf("Input Array (Size %d): ", sizeOfArray);
    for (int u = 0;u < sizeOfArray;u++) { // Displays the input array
        printf("%d ", testingArray[u]);
    }
    printf("\n");
    bubbleSort(testingArray, sizeOfArray); //Sorts array with our stopping condition 
    printf("Sorted Array using Bubble Sort: "); //Displays the sorted array 
    for(int m = 0; m < sizeOfArray; m++){
        printf("%d ", testingArray[m]);
    }
    printf("\n");

    return 0;
}
