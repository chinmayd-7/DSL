def selection(arr):
    n=len(arr)
    for i in range(n-1):
        min=i
        for j in range(i+1,n):
            if arr[min]>arr[j]:
                min=j
        #swap
        arr[i],arr[min]=arr[min],arr[i]
    print(arr)

def bubble(arr):
    n=len(arr) 
    for i in range(1,n):
        for j in range(n-i):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    print(arr)

def insertion(arr):
    n=len(arr)
    for i in range(1,n):
        temp=arr[i]
        j=i-1
        while j>=0 and arr[j]>temp:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=temp

    print(arr)
arr=[21,20,3,5,19]
selection(arr)
bubble(arr)
insertion(arr)
