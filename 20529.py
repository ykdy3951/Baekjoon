import sys
input=sys.stdin.readline

def mbti(a, b):
    ans = 0
    for i in range(4):
        if a[i] != b[i]:
            ans += 1
    return ans

for _ in range(int(input())):
    n=int(input())
    l=[*map(str,input().split())]
    if n > 16**2:
        print(0)
        continue
    ans=10000
    for i in range(n-2):
        for j in range(i+1, n-1):
            for k in range(j+1, n):
                ans=min(ans, mbti(l[i], l[j])+mbti(l[j], l[k])+mbti(l[k], l[i]))
    print(ans)
