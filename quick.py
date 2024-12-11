def partition(arr,low,high):
    pivot=arr[high]
    i=low-1
    for j in range(low,high):
        if arr[j]<=pivot:
            i+=1
            arr[i],arr[j]=arr[j],arr[i]
    i+=1
    arr[i],arr[high]=arr[high],arr[i]
    # print(arr)
    return i

def quick(arr,low,high):
    if low<high:
        pidx=partition(arr,low,high)

        quick(arr,low,pidx-1)
        quick(arr,pidx,high)
    if low==high==0:
        print(arr)

quick([12,8,7,6,2],0,4)

def quick_sort(arr):
    if len(arr) <= 1:  # Base case: arrays with 0 or 1 element are already sorted
        return arr
    else:
        pivot = arr[-1]  # Choosing the last element as the pivot
        less_than_pivot = [x for x in arr[:-1] if x <= pivot]  # Elements less than or equal to pivot
        greater_than_pivot = [x for x in arr[:-1] if x > pivot]  # Elements greater than pivot
        
        # Recursively apply quick_sort to the sub-arrays and concatenate results
        return quick_sort(less_than_pivot) + [pivot] + quick_sort(greater_than_pivot)

# Example usage
# array = [64, 34, 25, 12, 22, 11, 90]
# sorted_array = quick_sort(array)
# print(sorted_array)  # Output: [11, 12, 22, 25, 34, 64, 90]