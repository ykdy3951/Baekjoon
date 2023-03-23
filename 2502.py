# A B A+B A+2B 2A+3B 3A+5B
# - - 1 1 1 2 2 3 3 5

l=[0, 0, 0, 1, 1, 2]
n, m = map(int, input().split())
for i in range(6, n+2):
    l.append(l[i-1]+l[i-2])

a, b = l[n], l[n+1]

i = 1
while True:
    if (m - a * i) % b == 0:
        print(i)
        print((m - a * i) // b)
        break
    i+=1