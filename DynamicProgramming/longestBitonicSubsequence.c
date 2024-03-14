#include<stdio.h>
#include<stdlib.h>
int max (int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int lbs (int* arr, int n){
    int i,j;
    int* dinamikLis;
    int* dinamikLds;
    
    dinamikLis = (int*)malloc(n*sizeof(int));
    dinamikLds = (int*)malloc(n*sizeof(int));
    for (i=0; i<n;i++){
        dinamikLds[i] = 1;
        dinamikLis[i] = 1;
    }
    //lis
    for (i=1;i<n;i++){
        for (j=0;j<i;j++){
            if (arr[i]>arr[j] && dinamikLis[i]<dinamikLis[j]+1){
                dinamikLis[i] = dinamikLis[j]+1;
            }
        }
    }
    //lds
    for (i=n-2;i>0;i--){
        for (j=n-1; j>i;j--){
            if (arr[i]>arr[j] && dinamikLds[i]<dinamikLds[j]+1){
                dinamikLds[i] = dinamikLds[j]+1;
            }
        }
    }
      int maxLenght = 1;
    for (i = 1; i < n; i++)
     maxLenght =max (dinamikLis[i] + dinamikLds[i] - 1, maxLenght);
   
    free(dinamikLis);
    free(dinamikLds);

    return maxLenght;
}
int main()
{
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("En Uzun Bitonik Alt Dizinin Uzunlugu: %d\n", lbs( arr, n ) );
    return 0;
}
