#include "bookdistribution.h"
#include <stdio.h>
#include <limits.h>

int IsWorkloadFeasible(int book_list[], int book_count, int employee_count, int max_workload) {
    int required_employees = 1, current_load = 0;

    for (int i = 0; i < book_count; i++) {
        if (book_list[i] > max_workload) {
            return 0;
        }
        if (current_load + book_list[i] > max_workload) {
            required_employees++;
            current_load = book_list[i];
            if (required_employees > employee_count) {
                return 0;
            }
        } else {
            current_load += book_list[i];
        }
    }
    return 1;
}

int CalculateOptimalWorkload(int book_list[], int book_count, int employee_count) {
    int total_pages = 0;
    for (int i = 0; i < book_count; i++) {
        total_pages += book_list[i];
    }

    int left = 0;
    int right = total_pages;
    int optimal_workload = INT_MAX;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (IsWorkloadFeasible(book_list, book_count, employee_count, mid)) {
            optimal_workload = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return optimal_workload;
}

void DistributeBooksToEmployees(int book_list[], int book_count, int employee_count) {
    int optimal_workload = CalculateOptimalWorkload(book_list, book_count, employee_count);
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return;
    }
    fprintf(output_file, "The best way to divide books in order to reduce the maximum workload is:\n");

    int current_load = 0;
    int current_employee = 1;
    int start_index = 0;

    for (int i = 0; i < book_count; i++) {
        if (current_load + book_list[i] > optimal_workload) {
            fprintf(output_file, "Employee %d: %d pages (", current_employee, current_load);
            for (int j = start_index; j < i; j++) {
                fprintf(output_file, "%d ", book_list[j]);
            }
            fprintf(output_file, ")\n");

            current_load = book_list[i];
            current_employee++;
            start_index = i;
        } else {
            current_load += book_list[i];
        }

        if (i == book_count - 1) {
            fprintf(output_file, "Employee %d: %d pages (", current_employee, current_load);
            for (int j = start_index; j <= i; j++) {
                fprintf(output_file, "%d ", book_list[j]);
            }
            fprintf(output_file, ")\n");
        }
    }

    fprintf(output_file, "The best way to divide books in order to reduce the maximum workload is: %d pages\n", optimal_workload);
    fclose(output_file);
}
