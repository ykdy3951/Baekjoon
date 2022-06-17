s=0;m=1001
for _ in range(int(input())):
    n=int(input())
    if n == min(m, n):
        m=n
    else:
        s+=n-m
print(s)