#include <stdio.h>

// Function to check if there is a subset with the given sum
int isSubsetSum(int set[], int n, int sum) {
    // Base cases
    if (sum == 0) {
        return 1; // Subset with the given sum is found
    }
    if (n == 0 && sum != 0) {
        return 0; // No subset with the given sum is possible
    }

    // If the last element is greater than the sum, then it cannot be included
    if (set[n - 1] > sum) {
        return isSubsetSum(set, n - 1, sum);
    }

    // Check if the sum can be obtained by either including or excluding the last element
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum)) {
        printf("Subset with the given sum exists.\n");
    } else {
        printf("Subset with the given sum does not exist.\n");
    }

    return 0;
}

