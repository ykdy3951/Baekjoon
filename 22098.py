def f(x,y,z):
    if x**2+y**2 == z**2:
        return 0
    elif x**2+y**2 > z**2:
        return 1
    return 2
for _ in range(int(input())):
    l=[0,0,0]
    a=sorted(list(map(int,input().split())))
    if a[1]+a[2]>a[3]:
        l[f(a[1],a[2],a[3])]+=1
    if a[0]+a[2]>a[3]:
        l[f(a[0],a[2],a[3])]+=1
    if a[0]+a[1]>a[3]:
        l[f(a[0],a[1],a[3])]+=1
    if a[0]+a[1]>a[2]:
        l[f(a[0],a[1],a[2])]+=1
    print(*l)