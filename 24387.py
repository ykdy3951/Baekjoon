x=sorted(list(map(int,input().split())))
y=sorted(list(map(int,input().split())))
s=0
for i in range(3):
    s+=x[i]*y[i]
print(s)