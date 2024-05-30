#include <stdio.h>
#include <stdlib.h>
#include "bookdistribution.h"

void generateTestData();
void generateRandomTestData();

int main() {
    int employee_count, book_count;

    FILE *file_pointer = fopen("input.txt", "r");
    if (file_pointer == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fscanf(file_pointer, "%d", &employee_count);
    fscanf(file_pointer, "%d", &book_count);

    int *book_list = (int *)malloc(book_count * sizeof(int));
    for (int i = 0; i < book_count; i++) {
        fscanf(file_pointer, "%d", &book_list[i]);
    }
    fclose(file_pointer);

    DistributeBooksToEmployees(book_list, book_count, employee_count);

    free(book_list);

    // Uncomment these lines to generate data for testing
    //generateTestData();
    //generateRandomTestData();

    return 0;
}
