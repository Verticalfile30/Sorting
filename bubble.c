#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool IsSorted(int *array) {
    for(int i = 0; i < 9; i++) {
        if(array[i] > array[i + 1]) {
            return false;
        }
    }

    return true;
}

void BubbleSort(int *unsorted) {

    int comparison1;
    int comparison2;
    int accessor1 = 0;
    int accessor2 = 1;
    bool sorted = false;

    while (!sorted) {
        comparison1 = unsorted[accessor1];
        comparison2 = unsorted[accessor2];

        if(comparison1 > comparison2) {
            unsorted[accessor1] = comparison2;
            unsorted[accessor2] = comparison1;
        } else {
            unsorted[accessor1] = comparison1;
            unsorted[accessor2] = comparison2;
        }

        accessor1++;
        accessor2++;
        
        sorted = IsSorted(unsorted);

        if (accessor2 == 10) {
            accessor1 = 0;
            accessor2 = 1;
        }

    }
    
}

int main() {

    //a quick bubble sort
    
    printf("Welcome to the sorter, press any key to continue\n");
    getchar();

    int *dataset = malloc(sizeof(int) * 10);
    srand(time(NULL));

    //int dataset[10] = { 2, 6, 9, 3, 4, 7, 1, 10, 5, 8 };

    for (int i = 0; i < 10; i++) {
        dataset[i] = rand() % 50;
        printf("Unsorted element %d: %d\n", i, dataset[i]);
    }

    printf("\n");

    BubbleSort(dataset);
    
    for (int i = 0; i < 10; i++) {
        printf("Sorted element %d: %d\n", i, dataset[i]);
    }
}