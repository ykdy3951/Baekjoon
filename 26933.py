ans = 0
for _ in range(int(input())):
    x,y,z=map(int,input().split())
    ans += z * max(0, y - x)
print(ans)