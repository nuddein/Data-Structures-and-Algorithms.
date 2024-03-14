#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max (int a, int b){
	if (a>b){
		return a;
	}
	else {
		return b;
	}
}

int longestIncreasingSubsequence (int arr[], int n){
	
	int dinamik [n];
	int i,j;
	for (i=0;i<n;i++){
		dinamik[i] = 1;
	}
	int maxLenght = 1;
	for (i=1; i<n; i++){
		for (j=0;j<i;j++){
			if (arr[i]>arr[j] && dinamik[i]<dinamik[j]+1){
				dinamik[i] = dinamik[j]+1;
			}
		}
		maxLenght = max (maxLenght, dinamik[i]);
	}
	
	return maxLenght;
}

int main (){
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("En Uzun artan Alt Dizinin Uzunlugu: %d\n", longestIncreasingSubsequence( arr, n ) );
}
