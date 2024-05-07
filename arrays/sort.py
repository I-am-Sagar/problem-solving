import time

def timer(func):
    def wrapper_func(*args, **kwargs):
        t = time.time()
        result = func(*args, **kwargs)
        print("Time taken by {} is {} seconds.".format(func.__name__, time.time()-t))
        return result
    return wrapper_func

# ----------------------------------------------------------------------
import random

# MERGE SORT

def merge(arr, left_half, right_half):
    i = j = k = 0

    while i < len(left_half) and j < len(right_half):
        if left_half[i] < right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1
        k += 1
    
    while i < len(left_half):
        arr[k] = left_half[i]
        i += 1
        k += 1

    while j < len(right_half):
        arr[k] = right_half[j]
        j += 1
        k += 1

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)
        merge(arr, left_half, right_half)

@timer
def merge_sort_wrapper(arr):
    merge_sort(arr)

# BUBBLE SORT

@timer
def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# QUICK SORT
def partition(arr, low, high):
    pivot = arr[high]
    i = low-1   # i elements will be smaller, index of left part

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1

def quick_sort(arr, low, high):
    if low < high:
        pivot_index = partition(arr, low, high)
        quick_sort(arr, low, pivot_index-1)
        quick_sort(arr, pivot_index+1, high)

@timer
def quick_sort_wrapper(arr):
    quick_sort(arr, 0, len(arr)-1)

n = 100000
array1 = [random.randint(1, 1000) for i in range(n)]
array2 = array1.copy()
array3 = array1.copy()

# array = [3, 4, 2, 5, 0, 1, 2, 7, 6]

# bubble_sort(array1)
# print(array1)

merge_sort_wrapper(array2)
# print(array2)

quick_sort_wrapper(array3)
# print(array3)