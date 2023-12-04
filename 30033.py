n=int(input())
a=list(map(int,input().split()));b=list(map(int,input().split()))
print(sum(map(lambda x:b[x]-a[x]>=0,range(n))))