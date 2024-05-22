def nsr_i(arr):
    n = len(arr)
    s = []
    result = []

    for i in range(n - 1, -1, -1):
        while s and s[-1][0] >= arr[i]:
            s.pop()

        if not s:
            result.append(n)
        else:
            result.append(s[-1][1])

        s.append((arr[i], i))

    result.reverse()
    return result

def nsl_i(arr):
    n = len(arr)
    s = []
    result = []

    for i in range(n):
        while s and s[-1][0] >= arr[i]:
            s.pop()

        if not s:
            result.append(-1)
        else:
            result.append(s[-1][1])

        s.append((arr[i], i))

    return result

def main():
    hist = [6, 2, 5, 4, 5, 1, 6]

    nsr_index = nsr_i(hist)
    nsl_index = nsl_i(hist)

    width = []
    for i in range(len(hist)):
        w = nsr_index[i] - nsl_index[i] - 1
        width.append(w)

    max_area = 0
    for i in range(len(width)):
        area = hist[i] * width[i]
        max_area = max(max_area, area)

    print(max_area)

if __name__ == "__main__":
    main()
