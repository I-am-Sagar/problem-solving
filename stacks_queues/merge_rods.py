import heapq

def min_cost_rods_merge(arr):
    cost = 0

    min_heap = arr[:]
    heapq.heapify(min_heap)

    while len(min_heap) > 1:
        rod1 = heapq.heappop(min_heap)
        rod2 = heapq.heappop(min_heap)

        cost += rod1 + rod2

        heapq.heappush(min_heap, rod1 + rod2)

    return cost

arr = [1, 2, 3, 2, 1, 4]
print(min_cost_rods_merge(arr))
