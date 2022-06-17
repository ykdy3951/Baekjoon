x,k,a=map(int,input().split())
x=x%(k+a)
print(1 if x < k else 0)
