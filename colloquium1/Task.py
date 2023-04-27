a = int(input())
s = input()
s1 = []
for i in s:
    s1.append(i)
counter = {}
single = ''
result = ''
s1.sort()
for ch in s1:
    if ch not in counter:
        counter[ch] = 1
    else:
        counter[ch] += 1
        if counter[ch] == 2:
            counter[ch] = 0
            result += ch

for ch, count in counter.items():
    if count == 1:
        single = ch
        break
print(result + single + result[::-1])


