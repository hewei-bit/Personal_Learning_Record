from queue import Queue


class Node:
    def __init__(self, val=0, neighbours=[]):
        self.val = val
        self.neighbours = neighbours


class Solution:
    def BFS(self, node: Node) -> Node:
        visited = set()
        queue = [node]
        while queue:
            tmp = queue.pop(0)
            print(tmp.val)
            for v in tmp.neighbours:
                if v not in visited:
                    visited.add(v)
                    queue.append(v)


if __name__ == '__main__':
    a = Node(1)
    b = Node(2)
    c = Node(3)
    d = Node(4)
    e = Node(5)
    a.neighbours = [b, d]
    b.neighbours = [c, d]
    c.neighbours = [d]
    d.neighbours = [e]

    Solution().BFS(a)
