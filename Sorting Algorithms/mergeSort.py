def mergeSort(A,p,r):

    if(p < r):
        q = (p+r)//2

        mergeSort(A,p,q)
        mergeSort(A,q+1,r)

        merge(A,p,q,r)


def merge(A,p,q,r):

    n1 = q-p+1
    n2 = r-q

    L = []

    for l1 in range(0,n1+1):
        L.append(0)


    R = []
    for r1 in range(0,n2+1):
        R.append(0)

    for i in range(0,n1):
        L[i] = A[p+i]

    for j in range(0,n2):
        R[j] = A[q+j+1]

    L[n1] = 99999

    R[n2] = 99999

    i = 0
    j = 0

    for k in range(p,r+1):
        if(L[i] <= R[j]):
            A[k] = L[i]
            i = i + 1

        else:
            A[k] = R[j]
            j = j + 1

 
A = [8,7,1,2,3,6,5,4]

mergeSort(A,0,7)

print(list(A))

    

        
