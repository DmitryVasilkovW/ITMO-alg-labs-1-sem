number_of_elements = int(input())
elementi_massiva = input().split()
list_of_elements = []
kol_vo_elementov = 0
for i in elementi_massiva:
    list_of_elements.append(int(i))
for i in range(number_of_elements - 2):
    if list_of_elements[i] < list_of_elements[i + 1] and list_of_elements[i + 1] > list_of_elements[i + 2]:
        kol_vo_elementov += 1
print(kol_vo_elementov)
