def F(n):
    if n == 0:
        return 8
    if n % 3 == 0:
        return 5 + F(n // 3)
    return F(n // 3)

k = 0
for n in range(1, 100000000):
    if F(n) == 18:
        k += 1
print(k)
