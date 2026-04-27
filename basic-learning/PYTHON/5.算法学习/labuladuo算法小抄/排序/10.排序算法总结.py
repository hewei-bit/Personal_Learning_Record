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
        return self.merge(left, right)  # 合并数组

    def merge(self, left: list, right: list) -> list:
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
            if left < right:  # 说明打破while循环的原因是ary[right] < key
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

    # arr[] --> 排序数组
    # low  --> 起始索引
    # high  --> 结束索引
    # 快速排序函数
    def quickSort_2(self, arr, low, high):
        if low < high:
            pi = self.partition(arr, low, high)
            self.quickSort_2(arr, low, pi - 1)
            self.quickSort_2(arr, pi + 1, high)

    def partition(self, arr, low, high):
        i = (low - 1)  # 最小元素索引
        pivot = arr[high]
        for j in range(low, high):
            # 当前元素小于或等于 pivot
            if arr[j] <= pivot:
                i = i + 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    # 七、堆排序 HeapSort
    def heap_sort(self, ary: list):
        n = len(ary)
        first = int(n / 2 - 1)  # 最后一个非叶子节点
        for start in range(first, -1, -1):  # 构建最大堆
            self.max_heapify(ary, start, n - 1)
        for end in range(n - 1, 0, -1):  # 堆排，将最大跟堆转换成有序数组
            ary[end], ary[0] = ary[0], ary[end]  # 将根节点元素与最后叶子节点进行互换，取出最大根节点元素，对剩余节点重新构建最大堆
            self.max_heapify(ary, 0, end - 1)  # 因为end上面取的是n-1，故而这里直接放end-1，相当于忽略了最后最大根节点元素ary[n-1]
        return ary

    # 最大堆调整：将堆的末端子节点做调整，使得子节点永远小于父节点
    # start 为当前需要调整最大堆的位置。
    def max_heapify(self, ary: list, start: int, end: int):
        root = start
        while True:
            child = root * 2 + 1  # 找到左子节点
            if child > end:  # 如果左子节点超过最后一个元素
                break
            if child + 1 <= end and ary[child] < ary[child + 1]:
                child = child + 1  # 如果左子节点比较大
            if ary[root] < ary[child]:  # 选择较大元素成为父节点
                ary[root], ary[child] = ary[child], ary[root]
                root = child
            else:
                break

    # 八、计数排序
    def counting_sort(self, arr: list, maxValue: int) -> list:
        bucketlen = maxValue + 1
        bucket = [0] * bucketlen
        sortIndex = 0
        arrlen = len(arr)
        for i in range(arrlen):
            if not bucket[arr[i]]:
                bucket[arr[i]] = 0
            bucket[arr[i]] += 1
        for j in range(bucketlen):
            while bucket[j] > 0:
                arr[sortIndex] = j
                sortIndex += 1
                bucket[j] -= 1
        return arr

    # 九、基数排序
    def radix_sort(self, arr: list):
        """基数排序"""
        i = 0  # 记录当前正在排拿一位，最低位为1
        max_num = max(arr)  # 最大值
        j = len(str(max_num))  # 记录最大值的位数
        while i < j:
            bucket_list = [[] for _ in range(10)]  # 初始化桶数组
            for x in arr:
                bucket_list[int(x / (10 ** i)) % 10].append(x)  # 找到位置放入桶数组
            arr.clear()
            for x in bucket_list:  # 放回原序列
                for y in x:
                    arr.append(y)
            i += 1
        return arr

    # 十、桶排序
    def bucket_sort(self, arr: list):
        if not arr:
            return 0
        maxValue = max(arr)
        bucket = [0] * (maxValue + 1)
        sort_list = []
        for i in arr:
            bucket[i] += 1
        for j in range(len(bucket)):
            if bucket[j] != 0:
                for k in range(bucket[j]):
                    sort_list.append(j)
        return sort_list


if __name__ == '__main__':
    l = [123, 42, 543, 345, 12, 321, 12]
    # arr = [10, 7, 8, 9, 1, 5]

    # sort().bubble_sort(l) #冒泡
    # sort().select_sort(l) #选择
    # sort().insert_sort(l) #插入
    # sort().shell_sort(l)  #希尔
    # ll = sort().Merge_sort(l) #归并
    # ll = sort().quick_sort(l) #快速
    # ll = sort().heap_sort(l)  # 堆排序
    # ll = sort().counting_sort(l,max(l)) #计数排序
    # ll = sort().radix_sort(l)  # 基数排序
    # ll = sort().bucket_sort(l)
    # 第二个快速排序

    n = len(l)
    sort().quickSort_2(l, 0, n - 1)
    print("排序后的数组:")
    for i in range(n):
        print("%d" % l[i])

    # begin_time = time()

    # end_time = time()
    # runtime = end_time - begin_time
    # print(runtime)
    # print(ll)
