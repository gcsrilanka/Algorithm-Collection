a=[]
for v in range(4):
    a.append(input('Enter a Number :'))
    print(a)

def selectionSort(a):
    for j in range(len(a)):
        min  = j
        for  i in range(j+1,len(a)):
            if(a[min] >a [i]):
                min = i
        temp = a[j]
        a[j] = a[min]
        a[min] = temp

selectionSort(a)
print(a)
