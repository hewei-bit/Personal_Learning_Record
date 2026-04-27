class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        return self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


if __name__ == '__main__':
    aaa = Stack()
    print(aaa.isEmpty())
    aaa.push(4)
    aaa.push('dog')
    print(aaa.peek())
    aaa.push(True)
    print(aaa.size())
    print(aaa.pop())
