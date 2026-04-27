class Solution:
    def surfaceArea(self, grid):
        res= 0
        row = len(grid)
        column = len(grid[0])
        for i in range(row):
            for j in range(column):
                if grid[i][j] == 0:
                    continue
                res += grid[i][j] * 4 + 2
                if i - 1 >= 0 and grid[i - 1][j] != 0:
                    res -= min(grid[i][j], grid[i - 1][j]) * 2
                if j - 1 >= 0 and grid[i][j - 1] != 0:
                    res -= min(grid[i][j - 1], grid[i][j]) * 2
        return res


grid = [[1, 2], [3, 4]]
a = Solution()
print(a.surfaceArea(grid))
