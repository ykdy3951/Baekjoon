n=int(input())
l=[*map(int,input().split())]
t,p=map(int,input().split())
print(sum(map(lambda x:(x+t-1)//t,l)))
print(*divmod(n,p))