#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bookdistribution.h"

// Function to generate random book pages and save to file

void CreateAndStoreRandomBookData(int book_list[], int book_count) {
    srand(time(NULL));
    for (int i = 0; i < book_count; i++) {
        book_list[i] = rand() % 100000000 + 1; // Pages between 1 and 100,000,000
    }

    FILE *file_pointer = fopen("randomdata.txt", "w");
    for (int i = 0; i < book_count; i++) {
        fprintf(file_pointer, "%d ", book_list[i]);
    }
    fclose(file_pointer);
}

void GenerateRandomTestData() {
    int book_count;
    int book_list[MAX_BOOKS];

    printf("Number of books for random data generation: ");
    scanf("%d", &book_count);

    CreateAndStoreRandomBookData(book_list, book_count);

    printf("Random book data has been generated and saved to randomdata.txt\n");
}
