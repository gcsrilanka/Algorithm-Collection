stack = [7, 7, 22, 37, 47, 55, 57, 57, 86, 91]
num = int(input("Enter the number you are searching for: "))
length = len(stack)
lower = 0
upper = length - 1
found = False

while found == False and lower <= upper:
    mid_point = (lower + upper) 
    if stack[mid_point] == num:
        print("You number has been found.")
        found = True
    elif stack[mid_point] < num:
        lower = mid_point + 1
    else:
        upper = mid_point - 1
if found == False:
    print("Your number is not in the list.")
