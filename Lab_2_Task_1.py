numder_of_elements = int(input())       
elements = input().split()
element_to_replace, position = map(int, input().split())
list_of_elements = []
result_arry = []  
for i in elements:
    list_of_elements.append(int(i))   
for i in range(position - 1):
    result_arry.append(list_of_elements[i])
result_arry.append(element_to_replace)
for i in list_of_elements[position - 1::]:
    result_arry.append(i)
print(*result_arry)
