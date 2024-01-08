#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *arr[1000];
int index1 = 0;

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r) {
   int i;
   if (l == r) {
     arr[index1] = (char*)malloc(sizeof(char)*(r+2));
     strcpy(arr[index1], a);
     index1++;
   }
   else {
       for (i = l; i <= r; i++) {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); // backtrack
       }
   }
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    char str[] = "4567";
    int n = strlen(str);
    permute(str, 0, n-1);
    qsort(arr, index1, sizeof(const char*), compare);
    for(int i = 0; i < index1; i++) {
        printf("%s\n", arr[i]);
    }
    return 0;
}