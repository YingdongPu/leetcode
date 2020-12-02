#include <stdio.h>
int maxValue(int** grid, int gridSize, int* gridColSize)
{
    int** dp = malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        dp[i] = calloc(gridColSize[0], sizeof(int));
    }

    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridColSize[0]; i++) {
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < gridSize; i++) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < gridColSize[0]; j++) {
            dp[i][j] = grid[i][j] + fmax(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int ans = dp[gridSize - 1][gridColSize[0] - 1];
    for (int i = 0; i < gridSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return ans;
}