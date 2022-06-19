n=int(input())
l=list(map(int,input().split()))
i=l.count(-1)
print((sum(l)+i)/(n-i))