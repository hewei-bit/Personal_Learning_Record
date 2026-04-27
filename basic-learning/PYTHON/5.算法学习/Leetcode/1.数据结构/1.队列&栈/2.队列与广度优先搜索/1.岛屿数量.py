from collections import deque
from typing import List


# DFS非递归
class Solution1:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        if not grid:
            return 0
        m = len(grid)
        n = len(grid[0])
        marked = [[False for _ in range(n)] for _ in range(m)]
        count = 0
        stack = []
        for i in range(m):
            for j in range(n):
                if not marked[i][j] and grid[i][j] == '1':
                    count += 1
                    stack.append((i, j))
                    marked[i][j] = True
                    while stack:
                        cur_x, cur_y = stack.pop()
                        for direction in directions:
                            new_x = cur_x + direction[0]
                            new_y = cur_y + direction[1]
                            if 0 <= new_x < m and 0 <= new_y < n and not marked[new_x][new_y] and grid[new_x][
                                new_y] == '1':
                                stack.append((new_x, new_y))
                                marked[new_x][new_y] = True
        return count


# DFS递归
class Solution2:
    def numIslands(self, grid: List[List[str]]) -> int:

        if not grid:
            return 0
        m = len(grid)
        n = len(grid[0])
        marked = [[False for _ in range(n)] for _ in range(m)]
        count = 0

        for i in range(m):
            for j in range(n):
                if not marked[i][j] and grid[i][j] == '1':
                    count += 1
                    self.dfs(grid, i, j, m, n, marked)
        return count

    def dfs(self, grid, i, j, m, n, marked):
        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        marked[i][j] = True
        for direction in directions:
            new_x = i + direction[0]
            new_y = j + direction[1]
            if 0 <= new_x < m and 0 <= new_y < n and not marked[new_x][new_y] and grid[new_x][new_y] == '1':
                marked[new_x][new_y] = True
                self.dfs(grid, new_x, new_y, m, n, marked)


# BFS
class Solution3:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        m = len(grid)
        # 特判
        if m == 0:
            return 0
        n = len(grid[0])
        marked = [[False for _ in range(n)] for _ in range(m)]
        count = 0
        # 从第 1 行、第 1 格开始，对每一格尝试进行一次 DFS 操作
        for i in range(m):
            for j in range(n):
                # 只要是陆地，且没有被访问过的，就可以使用 BFS 发现与之相连的陆地，并进行标记
                if not marked[i][j] and grid[i][j] == '1':
                    # count 可以理解为连通分量，你可以在广度优先遍历完成以后，再计数，
                    # 即这行代码放在【位置 1】也是可以的
                    count += 1
                    queue = deque()
                    queue.append((i, j))
                    # 注意：这里要标记上已经访问过
                    marked[i][j] = True
                    while queue:
                        cur_x, cur_y = queue.popleft()
                        # 得到 4 个方向的坐标
                        for direction in directions:
                            new_i = cur_x + direction[0]
                            new_j = cur_y + direction[1]
                            # 如果不越界、没有被访问过、并且还要是陆地，我就继续放入队列，放入队列的同时，要记得标记已经访问过
                            if 0 <= new_i < m and 0 <= new_j < n and not marked[new_i][new_j] and grid[new_i][
                                new_j] == '1':
                                queue.append((new_i, new_j))
                                # 【特别注意】在放入队列以后，要马上标记成已经访问过，语义也是十分清楚的：反正只要进入了队列，你迟早都会遍历到它
                                # 而不是在出队列的时候再标记
                                # 【特别注意】如果是出队列的时候再标记，会造成很多重复的结点进入队列，造成重复的操作，这句话如果你没有写对地方，代码会严重超时的
                                marked[new_i][new_j] = True
                    # 【位置 1】
        return count
