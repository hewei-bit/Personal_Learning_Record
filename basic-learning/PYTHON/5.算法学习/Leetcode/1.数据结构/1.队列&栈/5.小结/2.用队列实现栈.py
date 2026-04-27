class Mystack:

    def __init__(self):
        self.q = []

    def push(self,x):
        self.q.append(x)
        q_length = len(self.q)
        while q_length > 1:
            self.q.append(self.q.pop(0))
            q_length -= 1

    def pop(self):
        return self.q.pop(0)

    def top(self):
        return self.q[0]

    def empty(self):
        if len(self.q) == 0:
            return True
        else:
            return False
