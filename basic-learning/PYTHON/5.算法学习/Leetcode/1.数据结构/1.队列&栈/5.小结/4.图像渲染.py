"""
733. 图像渲染

给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和
一个新的颜色值 newColor，让你重新上色这幅图像。

为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，
接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，
重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

最后返回经过上色渲染后的图像。

示例 1:

输入:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析:
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。

"""
from typing import List


# 深度优先搜索
class Solution1:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        color = image[sr][sc]
        if color == newColor:
            return image
        self.dfs(image, sr, sc, newColor, color)
        return image

    def dfs(self, image, r, c, newcolor, color):
        if r >= len(image) or r < 0 or c >= len(image[0]) or c < 0:
            return
        if image[r][c] != color:
            return
        image[r][c] = newcolor
        vx = [0, 0, 1, -1]
        vy = [1, -1, 0, 0]
        for i in range(4):
            newr = r + vy[i]
            newc = c + vx[i]
            self.dfs(image, newr, newc, newcolor, color)


# 广度优先搜索
class Solution2:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        color = image[sr][sc]
        if color == newColor:
            return image
        queue = [(sr, sc)]
        image[sr][sc] = newColor
        vx = [0, 0, 1, -1]
        vy = [1, -1, 0, 0]
        while queue:
            pos = queue.pop(0)
            for i in range(4):
                r = pos[0] + vy[i]
                c = pos[1] + vx[i]
                if r >= len(image) or r < 0 or c >= len(image[0]) or c < 0:
                    continue
                if image[r][c] == color:
                    image[r][c] = newColor
                    queue.append((r, c))
        return image

if __name__ == '__main__':
    a = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
    obj = Solution2().floodFill(a, 1, 1, 2)
