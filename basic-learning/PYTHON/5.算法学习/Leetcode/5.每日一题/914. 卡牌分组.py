import math
import collections

from functools import reduce


class Solution:
    def hasGroupsSizeX(self, deck):
        def gcd(a, b):
            if (a < b):
                temp = a
                a = b
                b = temp
            if b == 0:
                return a
            return gcd(b, a % b)

        return reduce(gcd, collections.Counter(deck).values()) > 1


c = ['adc', 'cda', 'dac']
d = reduce(lambda x, y: x + y, c)
h = lambda x: x + 1
