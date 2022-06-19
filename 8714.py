n=int(input());l=list(map(int,input().split()))
print(min(n-sum(l), sum(l)))