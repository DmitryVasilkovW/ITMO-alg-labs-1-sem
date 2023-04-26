number_of_droids = int(input())
seriiniky = input().split()
min_znach = 2 * (10 ** 100)
min_znach2 = 2 * (10 ** 100)
list_droidov = []
for i in seriiniky:
    list_droidov.append(int(i))
for i in list_droidov:
    if i < min_znach2:
        min_znach2 = i
if list_droidov.count(min_znach2) != 1:
    min_znach = min_znach2
if list_droidov.count(min_znach2) == 1:
    for i in list_droidov:
        if i != min_znach2:
            if i < min_znach:
                min_znach = i
otvet = str(min_znach2) + ' ' + str(min_znach)
print(otvet)
