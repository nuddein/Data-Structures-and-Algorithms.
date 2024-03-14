#include <stdio.h>
#include <stdlib.h>

int max (int a, int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}
void knapsack(int value[], int wt[],int w, int n ){
    int i,j;
    int dinamik [n+1][w+1];
    
    for (i=0; i<=n; i++){
        for (j=0; j<=w;j++){
            if (i==0 || j== 0){
                dinamik [i][j] = 0;
            }
            else if (j>=wt[i-1]){
                dinamik[i][j] = max (value[i-1] + dinamik[i-1][j-wt[i-1]], dinamik[i-1][j]);
            }
            else {
                dinamik[i][j] = dinamik[i-1][j];
            }
        }
    }
    printf ("max value: %d\n", dinamik[n][w]);
    
    i=n, j=w;
    
    
    printf ("selected values: \n");
     while (i>0 && j>0){
        if (dinamik[i][j]!=dinamik[i-1][j]){
            printf ("%d\n", i);
            j = j-wt[i-1];
        }
        i--;
    }
    
   

}

int main (){
    int value [] = {1,4,2,6,5,10};
    int wt [] =    {5,4,10,2,11,3};
    int w = 10;
    
    int n = sizeof (value)/sizeof(value[0]);
     knapsack (value,wt,w,n);
    
}

