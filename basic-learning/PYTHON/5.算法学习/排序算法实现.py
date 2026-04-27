"""
这次收集整理并用Python实现了八大经典排序算法，
包括冒泡排序，插入排序，选择排序，希尔排序，归并排序，快速排序，堆排序以及基数排序。
希望能帮助到有需要的同学。之所以用 Python 实现，
主要是因为它更接近伪代码，能用更少的代码实现算法，更利于理解。
本篇博客所有排序实现均默认从小到大。
"""
from time import *


class sort:
    # 一、冒泡排序
    """
    冒泡排序的原理非常简单，它重复地走访过要排序的数列，
    一次比较两个元素，如果他们的顺序错误就把他们交换过来。
    """

    def bubble_sort(self, ary):
        n = len(ary)
        for i in range(n):
            flag = True
            for j in range(1, n - i):
                if ary[j - 1] > ary[j]:
                    temp = ary[j - 1]
                    ary[j - 1] = ary[j]
                    ary[j] = temp
                    flag = False
            if flag:
                break

        return ary

    # 二、选择排序
    """
    选择排序是另一个很容易理解和实现的简单排序算法。
    学习它之前首先要知道它的两个很鲜明的特点。
    1. 运行时间和输入无关
    2. 数据移动是最少的
    """

    def select_sort(self, ary):

        n = len(ary)
        for i in range(0, n):
            min = i  # 最小元素下表标记
            for j in range(i + 1, n):
                if ary[j] < ary[min]:
                    min = j  # 找到最小值下标
            ary[min], ary[i] = ary[i], ary[min]  # 交换两者

    # 三、插入排序 InsertionSort
    """
    插入排序的工作原理是，对于每个未排序数据，
    在已排序序列中从后向前扫描，找到相应位置并插入。
    """

    def insert_sort(self, ary):
        n = len(ary)
        for i in range(1, n):
            key = i - 1
            mark = ary[i]
            while key >= 0 and ary[key] > mark:
                ary[key + 1] = ary[key]
                key -= 1
            ary[key + 1] = mark
        return ary

    # 四、希尔排序 ShellSort
    """
    希尔排序的实质就是分组插入排序，该方法又称缩小增量排序
    """

    def shell_sort(self, ary):
        count = len(ary)
        gap = round(count / 2)
        # 双杠用于整除（向下取整），在python直接用 “/” 得到的永远是浮点数，
        # 用round()得到四舍五入值
        while gap >= 1:
            for i in range(gap, count):
                temp = ary[i]
                j = i
                while j - gap >= 0 and ary[j - gap] > temp:
                    ary[j] = ary[j - gap]
                    j -= gap
                ary[j] = temp
            gap = round(gap / 2)
        return ary

    # 五、归并排序 MergeSort
    def Merge_sort(self, ary: list) -> list:
        if len(ary) <= 1:
            return ary
        median = int(len(ary) / 2)  # 二分分解
        left = self.Merge_sort(ary[:median])
        right = self.Merge_sort(ary[median:])

        def merge(left: list, right: list) -> list:
            """合并操作，
                将两个有序数组left[]和right[]合并成一个大的有序数组"""
            res = []
            i = j = 0
            while i < len(left) and j < len(right):
                if left[i] < right[j]:
                    res.append(left[i])
                    i += 1
                else:
                    res.append(right[j])
                    j += 1
            res = res + left[i:] + right[j:]
            return res

        return merge(left, right)  # 合并数组

    # 六、快速排序 QuickSort
    """
    快速排序通常明显比同为Ο(n log n)的其他算法更快，
    因此常被采用，而且快排采用了分治法的思想，
    所以在很多笔试面试中能经常看到快排的影子。可见掌握快排的重要性。
    步骤：
    1.从数列中挑出一个元素作为基准数。
    2.分区过程，将比基准数大的放到右边，小于或等于它的数都放到左边。
    3.再对左右区间递归执行第二步，直至各区间只有一个数。
    """

    def quick_sort(self, ary):
        return self.qsort(ary, 0, len(ary) - 1)

    def qsort(self, ary, start, end):
        if start < end:
            left = start
            right = end
            key = ary[start]
        else:
            return ary
        while left < right:
            while left < right and ary[right] >= key:
                right -= 1
            if left < right:  # 说明打破while循环的原因是ary[right] <= key
                ary[left] = ary[right]
                left += 1
            while left < right and ary[left] < key:
                left += 1
            if left < right:  # 说明打破while循环的原因是ary[left] >= key
                ary[right] = ary[left]
                right -= 1
        ary[left] = key  # 此时，left=right，用key来填坑

        self.qsort(ary, start, left - 1)
        self.qsort(ary, left + 1, end)
        return ary

    # 七、堆排序 HeapSort

    # 八、基数排序


if __name__ == '__main__':
    l = [123, 42, 543, 345, 12, 321, 12]
    # begin_time = time()

    # sort().bubble_sort(l)
    # sort().select_sort(l)
    # sort().insert_sort(l)
    # sort().shell_sort(l)
    # ll = sort().Merge_sort(l)
    ll = sort().quick_sort(l)

    # end_time = time()
    # runtime = end_time - begin_time
    # print(runtime)
    print(ll)
