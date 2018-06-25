def find_pivot(arr, arr_len):
    i = 0
    sum = 0
    left = 0
    while i < arr_len:
        sum += arr[i]
        i += 1
    i = 0
    while i < arr_len:
        sum -= arr[i]
        if sum == left:
            return i
        left += arr[i]
        i += 1
    return (-1)

arr = [1,3,1]
print(find_pivot(arr, 3))