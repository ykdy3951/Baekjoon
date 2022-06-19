def f(i):
    if int(i) >= 7:
        return 7
    else:
        return int(i)
n=int(input())
l=list(map(f,input().split()))
print(sum(l)-n//2*5-n%2*2)