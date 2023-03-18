n=int(input())
l=list(map(int,input().split()))

if l == sorted(l):
    print(-1)

else:
    for i in range(n-1, 0, -1):
        if l[i-1] > l[i]:
            for j in range(n-1, 0, -1):
                if l[i-1] > l[j]:
                    l[i-1],l[j]=l[j],l[i-1]
                    l=l[:i]+sorted(l[i:], reverse=True)
                    print(*l)
                    exit(0)