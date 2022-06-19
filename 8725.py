s=0
for _ in range(int(input())):
    s+=max(max(list(map(int,input().split()))),0)
print(s)