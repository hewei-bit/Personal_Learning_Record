import heapq


# 堆是一个二叉树，其中每个父节点的值都小于或等于其所有子节点的值。
# 整个堆的最小元素总是位于二叉树的根节点。
# python的heapq模块提供了对堆的支持。
# 堆数据结构最重要的特征是heap[0]永远是最小的元素
class heap_examlpe:
    def heapq_example(self):
        h = []
        l = [2, 3, 3, 5, 6, 6, 1, 4, 54]

        # heap为定义堆，item增加的元素
        heapq.heappush(h, 1)
        print(h)

        # 将列表转换为堆
        heapq.heapify(l)
        print(l)

        # 删除最小值，因为堆的特征是heap[0]永远是最小的元素，所以一般都是删除第一个元素。
        heapq.heappop(l)
        print(l)

        # 删除最小元素值，添加新的元素值
        heapq.heapreplace(l, 99)
        print(l)

        # 首先判断添加元素值与堆的第一个元素值对比，
        # 如果大，则删除第一个元素，然后添加新的元素值，购置不更改堆
        heapq.heapreplace(l, 1)
        print(l)

        # 将多个堆合并
        print(heapq.merge(h, l))

        # 查询堆中的最大元素，n表示查询元素个数

        print(heapq.nlargest(3, l))
        # 查询堆中的最小元素，n表示查询元素的个数

        print(heapq.nsmallest(3, l))


if __name__ == '__main__':
    heap_examlpe().heapq_example()
