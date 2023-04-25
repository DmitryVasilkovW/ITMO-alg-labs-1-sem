array_size = int(input())
arry = input().split()
chislo = int(input())
list_of_elemtnts = []
for i in arry:
    list_of_elemtnts.append(int(i))
list_of_elemtnts_and_raznosty = []
for i in list_of_elemtnts:
    list_of_elemtnts_and_raznosty.append([abs(chislo - i), i])
list_of_elemtnts_and_raznosty.sort()
print(list_of_elemtnts_and_raznosty[0][1])
