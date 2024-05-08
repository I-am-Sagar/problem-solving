def partition(arr, low, high):
    i = low-1   # i elements will be smaller, index of left part

    for j in range(low, high):
        if arr[j] != 0:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1

def push_zeros(arr):
    n = len(arr)//2

    # Partitioning
    pivot_index = partition(arr, 0, len(arr)-1)

    # neg_idx = 0
    # pos_idx = n

    # while pos_idx < 2*n and neg_idx < n:
    #     arr[pos_idx], arr[neg_idx] = arr[neg_idx], arr[pos_idx]
    #     pos_idx += 2
    #     neg_idx += 2
    
    return arr

array = [3, 0, 1, 0, 6, 0, 10, 11, 0, 10]
print(push_zeros(array))