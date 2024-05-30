#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bookdistribution.h"

void GenerateAndStoreBookData(int book_list[], int book_count) {
    srand(time(NULL));
    int page_count = 100;
    for (int i = 0; i < book_count; i++) {
        book_list[i] = page_count;
        page_count += 100;
    }

    FILE *file_pointer = fopen("bookdata.txt", "w");
    for (int i = 0; i < book_count; i++) {
        fprintf(file_pointer, "%d ", book_list[i]);
    }
    fclose(file_pointer);
}

void ProduceTestData() {
    int book_count;
    int book_list[MAX_BOOKS];

    printf("The number of books for data generation: ");
    scanf("%d", &book_count);

    GenerateAndStoreBookData(book_list, book_count);

    printf("Book data has been generated and saved to bookdata.txt\n");
}
