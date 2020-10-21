# this function sorts a list in bubble sort algorithm
def bubble_sort(lst):
    flag = True

    while flag :
        flag = False
        for i in range(len(lst)-1):
            if lst[i] > lst[i+1]:
                lst[i],lst[i+1] = lst[i+1],lst[i]
                flag = True


lst = [1,5,2,7] # initialize the list which want to be sorted

bubble_sort(lst)
print(lst) # print the sorted list
