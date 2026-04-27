"""
# Definition for a Node.
"""


class Node:
    def __init__(self, val=0, neighbors=[]):
        self.val = val
        self.neighbors = neighbors


# DFS
class Solution1:
    def cloneGraph(self, node: 'Node') -> 'Node':
        lookup = {}

        def dfs(node: 'Node'):
            if not node:
                return
            if node in lookup:
                return lookup[node]
            clone = Node(node.val, [])
            lookup[node] = clone
            for i in node.neighbors:
                clone.neighbors.append(dfs(i))
            return clone


        return dfs(node)

# BFS
class Solution2:
    def cloneGraph(self, node: 'Node') -> 'Node':
        lookup = {}

        def BFS(node: 'Node') -> 'Node':
            if not node:
                return
            clone = Node(node.val,[])
            lookup[node] = clone
            queue = [node]
            while queue:
                tmp = queue.pop(0)
                for i in tmp.neighbors:
                    if i not in lookup:
                        lookup[i] = Node(i.val,[])
                        queue.append(i)
                    lookup[tmp].neighbors.append(lookup[i])
            return clone
        return BFS(node)

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

    obj = Solution1().cloneGraph(a)
    obj2 = Solution2().cloneGraph(a)