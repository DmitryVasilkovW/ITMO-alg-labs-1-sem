array = []
number_of_elements = int(input())
element = input().split()
for i in element:
    array.append(int(i))
def Sort(list):
    if len(list) == 1 or len(list) == 0:
        return list
    left = Sort(list[:len(list) // 2])
    right = Sort(list[len(list) // 2:])
    res_index = 0
    l_index = 0
    r_index = 0
    result_array = [''] * (len(left) + len(right))
    while l_index < len(left) and r_index < len(right):
        if left[l_index] <= right[r_index]:
            result_array[res_index] = left[l_index]
            l_index += 1
        else:
            result_array[res_index] = right[r_index]
            r_index += 1
        res_index += 1
    while l_index < len(left):
        result_array[res_index] = left[l_index]
        l_index += 1
        res_index += 1
    while r_index < len(right):
        result_array[res_index] = right[r_index]
        r_index += 1
        res_index += 1
    for i in range(len(list)):
        list[i] = result_array[i]
    return list
print(*Sort(array))
