l=[];s=0
for _ in range(int(input())):
    s+=int(input())
    l.append(s)
print(-min(min(l),0))