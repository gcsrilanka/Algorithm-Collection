def quicksort(A,p,r):

    if(p<r):

        q = partition(A,p,r)

        quicksort(A,p,q-1)

        quicksort(A,q+1,r)


def partition(A,p,r):

    x = A[r]

    i = p - 1

    for j in range(p,r):

        if(A[j] <= x):
            i = i+1

            temp = A[j]
            temp2 = A[i]

            A[j] = temp2
            A[i] = temp


    temp3 = A[r]
    temp4 = A[i+1]

    A[r] = temp4
    A[i+1] = temp3

    return i+1

A = [8,6,3,2,1,5,4,7]

quicksort(A,0,7)

print(list(A))
