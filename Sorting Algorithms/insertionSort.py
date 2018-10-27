#This code Written by Dilshan Ramesh
# Insertion Sort Algorithm - Python


a = []

for x in range(5):
    a.append(int(input("Enter Number : ")))
print(a)


def InsertionSort(A):
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while(i >=0 and A[i] > key):
            A[i+1] = A[i]
            i = i - 1
        A[i+1] = key

InsertionSort(a)
print(a)