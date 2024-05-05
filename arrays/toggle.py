import time

def timer(func):
    def wrapper_func(*args, **kwargs):
        t = time.time()
        result = func(*args, **kwargs)
        print("Time taken by {} is {} seconds.".format(func.__name__, time.time()-t))
        return result
    return wrapper_func

# ------------------------------------------------------------------------------------

import random

n = 100000
q = 5000
bulbs = [random.choice([0, 1]) for _ in range(n)]
bulbs2 = bulbs.copy()

# print(bulbs)

queries = []
for _ in range(q):
    l = random.randint(0, n-1)
    m = random.randint(l, n-1)
    queries.append((l, m))

# print(queries)
    
# O(nq)
@timer
def bulb_toggle(bulbs, queries):
    for query in queries:
        l, m = query
        for i in range(l, m+1):
            bulbs[i] = 1 - bulbs[i]
    print("Total lit bulbs: ", sum(bulbs))

# O(n+q)
@timer
def bulb_toggle_prefix_sum(bulbs, queries):
    diff_array = [0]*(n+1) 

    for query in queries:
        l, m = query
        diff_array[l] += 1
        diff_array[m+1] -= 1
    # print(sum(diff_array))

    prefix_array = [0]*n
    prefix_array[0] = diff_array[0]
    for i in range(1, n):
        prefix_array[i] = prefix_array[i - 1] + diff_array[i]

    for i in range(len(bulbs)):
        if prefix_array[i]%2 != 0:
            bulbs[i] = 1 - bulbs[i]
    
    print("Total lit bulbs: ", sum(bulbs))


bulb_toggle(bulbs, queries)
bulb_toggle_prefix_sum(bulbs2, queries)