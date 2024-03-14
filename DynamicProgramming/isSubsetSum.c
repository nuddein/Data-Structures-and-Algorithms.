#include <stdio.h>

// Function to check if there is a subset with a given sum
int isSubsetSum(int set[], int n, int sum) {
    // Create a 2D array to store the results of subproblems
    int dp[n + 1][sum + 1];

    // Base case: If the sum is 0, then there is an empty subset that satisfies it
    int i,j;
    for (i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill the dp array using a bottom-up approach
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            // If the current element is greater than the target sum, exclude it
            if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else {
                // Otherwise, include it or exclude it to get the result
                if (dp[i - 1][j] || dp[i - 1][j - set[i - 1]])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
    }

    // Print the dynamic programming matrix
    printf("Dynamic Programming Matrix:\n");
    for (i = 0; i <= n; i++) {
        for ( j = 0; j <= sum; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    // The final result is stored in the bottom-right cell of the dp array
    return dp[n][sum];
}

// Driver program to test the function
int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 9;

    if (isSubsetSum(set, n, sum))
        printf("Subset with the given sum exists.\n");
    else
        printf("Subset with the given sum does not exist.\n");

    return 0;
}

