def f(x):
    return int(x) < 0
n=int(input())
l=sum(list(map(f,input().split())))
print(l*n-l)