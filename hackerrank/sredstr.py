import sys

def super_reduced_string(s):
    # Complete this function
    stack = []
    for i in xrange(len(s)):
        if not stack or s[i] != stack[-1]:
            stack += [s[i]]
        else:
            stack.pop()
    if stack:
        return ''.join(stack)
    else:
        return 'Empty String'

s = raw_input().strip()
result = super_reduced_string(s)
print(result)
