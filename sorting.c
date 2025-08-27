#include <stdio.h>
#include "sorting.h"

void bubble_sort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void display_array(int arr[], int n) {
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void sorting_menu() {
    int choice, n, arr[50];
    do {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Bubble Sort\n2. Insertion Sort\n0. Back\n");
        scanf("%d", &choice);
        if(choice == 1 || choice == 2) {
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter elements: ");
            for(int i=0; i<n; i++)
                scanf("%d", &arr[i]);
            
            if(choice == 1) bubble_sort(arr, n);
            else if(choice == 2) insertion_sort(arr, n);
            
            printf("Sorted Array: ");
            display_array(arr, n);
        }
    } while(choice != 0);
}
