print("Enter no. of elements in array")
a=int(input())
arr=[]
print("Enter array elements")
for i in range(a):
    arr.append(int(input()))

def linear_search(numbers,target):
    for i in range(len(numbers)):
        if numbers[i]== target:
            return i
    else: 
        return -1
    
def sentinel_search(numbers,targest):
    n = len(arr)
    last = arr[-1]
    arr[-1] = target
    
    i = 0
    while arr[i] != target:
        i += 1

    arr[-1] = last

    if i < n - 1 or arr[-1] == target:
        return i
    return -1

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2 

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

def fibMonaccianSearch(arr, x, n):

    # Initialize fibonacci numbers
    fibMMm2 = 0  # (m-2)'th Fibonacci No.
    fibMMm1 = 1  # (m-1)'th Fibonacci No.
    fibM = fibMMm2 + fibMMm1  # m'th Fibonacci

    # fibM is going to store the smallest
    # Fibonacci Number greater than or equal to n
    while (fibM < n):
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm2 + fibMMm1

    # Marks the eliminated range from front
    offset = -1

    # while there are elements to be inspected.
    # Note that we compare arr[fibMm2] with x.
    # When fibM becomes 1, fibMm2 becomes 0
    while (fibM > 1):

        # Check if fibMm2 is a valid location
        i = min(offset+fibMMm2, n-1)

        # If x is greater than the value at
        # index fibMm2, cut the subarray array
        # from offset to i
        if (arr[i] < x):#1 down
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i

        # If x is less than the value at
        # index fibMm2, cut the subarray
        # after i+1
        elif (arr[i] > x):#2 down
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1

        # element found. return index
        else:
            return i

    # comparing the last element with x */
    if(arr[n-1] == x):
        return n-1

    # element not found. return -1
    return -1



target=int(input("Enter element to be searched"))
print("Using linear search:")
result=linear_search(arr,target)
if result == -1:
    print("Not found")
else:
    print("Found at:",result)

print("Using sentinel search:")
result=sentinel_search(arr,target)
if result == -1:
    print("Not found")
else:
    print("Found at:",result)

print("Using binary search:")
result=binary_search(arr,target)
if result == -1:
    print("Not found")
else:
    print("Found at:",result)

print("Using fibo search:")
result=fibMonaccianSearch(arr,target,len(arr))
if result == -1:
    print("Not found")
else:
    print("Found at:",result)