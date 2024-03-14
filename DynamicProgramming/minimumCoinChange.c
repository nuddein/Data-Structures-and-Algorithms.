#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Minimum fonksiyonu
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Minimum Coin Change algoritmasi
int minCoinChange(int *coins, int n, int amount) {
    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    dp[0] = 0; // Toplam 0'a ulasmak için hiç madeni para kullanmamiz gerekmez.
	int i,j;
    for (i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    int result = dp[amount];
    free(dp);

    if (result == INT_MAX) {
        printf("There is no possible way to make change for %d.\n", amount);
    } else {
        printf("Minimum number of coins needed: %d\n", result);
    }

    return (result == INT_MAX) ? -1 : result;
}

int main() {
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    minCoinChange(coins, n, amount);

    return 0;
}

