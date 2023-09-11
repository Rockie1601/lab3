#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** readStr(int m) {
    char** y = (char**)malloc(m * sizeof(char*));
    if (y == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
int p=0;
        do{
        printf("Enter str %d: ", p + 1);
        char e[100]; //
        scanf("%s", e);
        y[p] = (char*)malloc((strlen(e) + 1) * sizeof(char));
        if (y[p] == NULL) {
            perror("Memory alloc failed");
            exit(1);
        }
        strcpy(y[p], e);
         p++;
    }
    while(p<m);

    return y;
}

void insSort(char **uu, int n2) {
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

void displayStr(char** str, int n2) {
    printf("Sorted :\n");
    int e=0;
    while(e<n2){
    printf("%s\n", str[e]);
    e++;
    }
}

void freeStr(char** strs, int f) {
    for (int t = 0; t < f; t++) {
        free(strs[t]);
    }
    free(strs);
}

int main() {
    int n;

    printf("Enter the number of str: ");
    scanf("%d", &n);

    char** strings = readStr(n);

    insSort(strings, n);

    displayStr(strings, n);

    freeStr(strings, n);

    return 0;
}

