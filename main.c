#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "sorting.h"

int main() {
    int choice;
    do {
        printf("\n====== DSA PROJECT MENU ======\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Linked List Operations\n");
        printf("4. Sorting Algorithms\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: stack_menu(); break;
            case 2: queue_menu(); break;
            case 3: linkedlist_menu(); break;
            case 4: sorting_menu(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}
