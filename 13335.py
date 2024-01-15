n,w,l=map(int,input().split())

a=list(map(int,input().split()))
bridge=[0]*w
time=0

while a:
    bridge.pop(0)
    tmp = a[0]
    if len(bridge) < w and sum(bridge) + tmp <= l:
        bridge.append(tmp)
        a.pop(0)
    else:
        bridge.append(0)
    time+=1

print(time+w)
