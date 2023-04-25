number_of_elements = int(input())
elements = input().split(' ')
answer = elements[-1] + ' '
for i in range(number_of_elements - 1):
    answer += elements[i] + ' '
print(answer)
