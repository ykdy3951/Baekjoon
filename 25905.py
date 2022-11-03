l=[];s=1
for i in range(10):
    x=float(input())
    l.append(x)
    s*=x
s/=min(l)
print(s*1000000000/362880)