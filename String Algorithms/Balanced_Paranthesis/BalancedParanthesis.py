""""Check Using Stacks"""

open_br_list = ["[", "{", "("]
close_br_list = ["]", "}", ")"]

def bracketStack(Str):
    stack = []
    for i in Str:
        if i in open_br_list:
            stack.append(i)
        elif i in close_br_list:
            pos = close_br_list.index(i)
            if (len(stack) > 0) and (open_br_list[pos] == stack[len(stack) - 1]):
                stack.pop()
            else:
                return False

    if len(stack) == 0:
        return True
    else:
        return False


""" Method 2 """

def brackets(expression):
    bracks = ['()', '{}', '[]']
    while any(x in expression for x in bracks):
        for br in bracks:
            expression = expression.replace(br, '')
    return not expression


# Driver code
input_string = "([]{}()){}"

if bracketStack(input_string):
    print("balanced")
else:
    print("Not balanced")

# Method 2
if brackets(input_string):
    print("balanced")
else:
    print("Not balanced")
