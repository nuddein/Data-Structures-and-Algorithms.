#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int minimum(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

void printEditOperations(char *str1, char *str2, int m, int n, int dp[MAX_LENGTH][MAX_LENGTH]) {
    int i = m, j = n;

    printf("\nEdit Operations:\n");

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]) {
            printf("Copy '%c' from both strings\n", str1[i - 1]);
            i--;
            j--;
        } else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            printf("change '%c' in the first string with '%c' from the second string\n", str1[i - 1], str2[j - 1]);
            i--;
            j--;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            printf("Delete '%c' from the first string\n", str1[i - 1]);
            i--;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            printf("Insert '%c' from the second string into the first string\n", str2[j - 1]);
            j--;
        }
    }
}

int editDistance(char *str1, char *str2, int m, int n) {
    int dp[MAX_LENGTH][MAX_LENGTH];
	int i,j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + minimum(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    // Print the edit distance matrix
    printf("Edit Distance Matrix:\n");
    for ( i = 0; i <= m; i++) {
        for ( j = 0; j <= n; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    printEditOperations(str1, str2, m, n, dp);

    return dp[m][n];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    int distance = editDistance(str1, str2, m, n);

    printf("\nEdit Distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    return 0;
}

