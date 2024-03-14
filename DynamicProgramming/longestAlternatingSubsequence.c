#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int longestAlternatingSubsequence(int *arr, int n) {
    int inc [n];
   int dec [n];
   int i,j;
   for (i=0;i<n;i++){
       inc[i] = 1;
       dec [i] = 1;
   }
   
   for (i=1; i<n; i++){
       for (j=0; j<i;j++){
           if (arr[i]>arr[j]){
               inc[i] = max (inc[i], dec[j]+1);
           }
           else if (arr[i]<arr[j]) {
               dec[i] = max (dec[i], inc[j]+1);
           }
       }
   }
   return max (inc[n-1], dec[n-1]);
}

int main() {
    int arr[] = {0, 4, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestAlternatingSubsequence(arr, n);
    printf("En uzun alternatif alt dizinin uzunlugu: %d\n", result);

    return 0;
}

