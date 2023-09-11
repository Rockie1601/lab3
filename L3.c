#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read strings from the user
char** readStrings(int m) {
    char** y = (char**)malloc(m * sizeof(char*));
    if (y == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
int p=0;
        do{
        printf("Enter string %d: ", p + 1);
        char e[100]; //
        scanf("%s", e);
        y[p] = (char*)malloc((strlen(e) + 1) * sizeof(char));
        if (y[p] == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }
        strcpy(y[p], e);
         p++;
    }
    while(p<m);

    return y;
}

// Function to perform insertion sort on an array of strings
void insertionSort(char **uu, int n2) {
    for (int y = 1; y < n2; y++) {
        char *val = uu[y];
        int k = y - 1;
        while (k >= 0 && strcmp(uu[k], val) > 0) {
            uu[k + 1] = uu[k];
            k--;
        }
        uu[k + 1] = val;
    }
}

// Function to display sorted strings
void displayStrings(char** str, int n2) {
    printf("Sorted :\n");
    int e=0;
    while(e<n2){
    printf("%s\n", str[e]);
    e++;
    }
}

// Function to free memory
void freeStrings(char** strs, int f) {
    for (int t = 0; t < f; t++) {
        free(strs[t]);
    }
    free(strs);
}

int main() {
    int n;

    // Enter the number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Read the strings
    char** strings = readStrings(n);

    // Sort the strings
    insertionSort(strings, n);

    // Display the sorted strings
    displayStrings(strings, n);

    // Free memory
    freeStrings(strings, n);

    return 0;
}

