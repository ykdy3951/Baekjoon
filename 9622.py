l=[]
for _ in range(int(input())):
    a,b,c,d=map(float,input().split())
    a=int(a*100);b=int(b*100);c=int(c*100);d=int(d*100)
    if ((a<= 5600 and b <= 4500 and c <= 2500) or a+b+c <= 12500) and d <= 700:
        l.append(1)
    else:
        l.append(0)
for i in l:
    print(i)
print(sum(l))