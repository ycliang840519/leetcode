class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bracket = {')':'(', ']':'[', '}':'{'}
        for c in s:
            if c in bracket:
                top = stack.pop() if stack else '0'
                if top != bracket[c]:
                    return False
            else:
                stack.append(c)
        return not stack
