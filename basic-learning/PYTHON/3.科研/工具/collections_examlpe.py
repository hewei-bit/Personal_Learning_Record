from collections import namedtuple
from collections import deque
from collections import defaultdict
from collections import OrderedDict
from collections import Counter


class collections_example:
    # amedtuple是一个函数，它用来创建一个自定义的tuple对象，
    # 并且规定了tuple元素的个数，并可以用属性而不是索引来引用tuple的某个元素
    def nametuple_example(self):
        Point = namedtuple('Point', ['x', 'y'])
        p = Point(1, 2)
        print(p.x)
        print(p.y)
        print(isinstance(p, tuple))

    # deque是为了高效实现插入和删除操作的双向列表，适合用于队列和栈：
    def deque_example(self):
        q = deque(['a', 'b', 'c'])
        q.append('x')
        q.appendleft('y')
        print(q)

    # 使用dict时，如果引用的Key不存在，就会抛出KeyError。
    # 如果希望key不存在时，返回一个默认值，就可以用defaultdict
    def defaultdict_example(self):
        dd = defaultdict(lambda: 'N/A')
        dd['key1'] = 'abc'
        print(dd['key1'])
        print(dd['key2'])

    # 使用dict时，Key是无序的。在对dict做迭代时，我们无法确定Key的顺序。
    # 如果要保持Key的顺序，可以用OrderedDict：
    def OrderedDict_example(self):
        d = dict([('a', 1), ('b', 2), ('c', 3)])
        print(d)
        od = OrderedDict([('a', 1), ('b', 2), ('c', 3)])
        print(od)
        od['z'] = 1
        od['y'] = 2
        od['x'] = 3
        # 注意，OrderedDict的Key会按照插入的顺序排列，不是Key本身排序
        print(od)
        print(od.keys())

    # Counter是一个简单的计数器，例如，统计字符出现的个数：
    def counter_helpe(self):
        c = Counter()
        for ch in 'programming':
            c[ch] = c[ch] + 1
        print(c['r'])
        print(c)


if __name__ == '__main__':
    # collections_example().nametuple_example()
    # collections_example().defaultdict_example()

    # collections_example().OrderedDict_example()
    collections_example().counter_helpe()
