number_of_people = int(input())
list_of_people = []
proceed = number_of_people
for i in range(number_of_people):
    participant, point = map(int, input().split())
    list_of_people.append([participant, point])
for i in range(1, number_of_people):
    key = list_of_people[i][1]
    key2 = list_of_people[i][0]
    before = i - 1
    while list_of_people[before][1] < key and before + 1 > 0:
        list_of_people[before + 1][1] = list_of_people[before][1]
        list_of_people[before + 1][0] = list_of_people[before][0]
        before -= 1
        list_of_people[before + 1][1] = key
        list_of_people[before + 1][0] = key2
while proceed > 0:
    for i in range(1, number_of_people):
        if (list_of_people[i - 1][1] == list_of_people[i][1]) and (list_of_people[i - 1][0] > list_of_people[i][0]):
            key3 = list_of_people[i - 1][0]
            key4 = list_of_people[i][0]
            list_of_people[i - 1][0] = key4
            list_of_people[i][0] = key3
    proceed -= 1
for i in range(number_of_people):
    print(list_of_people[i][0], list_of_people[i][1])
