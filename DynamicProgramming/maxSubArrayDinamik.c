#include <stdio.h>
#include <stdlib.h>

// Max fonksiyonu
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubArraySum(int arr[], int n) {
  int i, dp [n];
  dp[0] = arr[0];
  
  int max_lenght = dp[0];
  for (i=1; i<n;i++){
      dp[i] = max (dp[i-1]+arr[i], arr[i]);
      max_lenght = max (max_lenght, dp[i]);
  }
  return max_lenght;
}
int main() {
    int arr[] = {2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxSubArraySum(arr, n);
    printf("En uzun toplam alt dizisi toplami: %d\n", result);

    return 0;
}


