import sys
input=sys.stdin.readline
ans = 55
x,y=input().split()
for _ in range(len(y)-len(x)+1):
    cnt = 0
    for i in range(len(x)):
        if x[i] != y[i+_]:
            cnt += 1
    ans = min(ans, cnt)
print(ans)