class Solution:
    def numSquares(self, n: int) -> int:
        if n == 0:
            return 0
        queue = [(n, 0)]
        visited = set()
        while queue:
            number, step = queue.pop(0)
            targets = [number - i * i for i in range(1, int(number ** 0.5) + 1)]
            for target in targets:
                if target == 0:
                    return step + 1
                if target not in visited:
                    queue.append((target, step + 1))
                    visited.add(target)
        return 0


if __name__ == '__main__':
    obj = Solution().numSquares(12)
    print(obj)
