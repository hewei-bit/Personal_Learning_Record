class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'{': '}', '(': ')', '[': ']'}
        stack = []
        for c in s:
            if c in dic:
                stack.append(c)
            elif dic[stack.pop()] != c:
                return False
        return len(stack) == 0


if __name__ == '__main__':
    s1 = "{[]}"
    s2 = "({)}"
    print(Solution().isValid(s2))
