import sys
input=sys.stdin.readline
d={}
for _ in range(int(input())):
    a, b = input().split()
    d[str(a)] = int(b)
print(d['jinju'])
print(len(list(filter(lambda x: d['jinju'] < x, d.values()))))