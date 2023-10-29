a=[];b=[]
for i in range(3):
    x,y,z=input().split()
    a.append([-int(x), z])
    b.append(int(y))
a.sort();b.sort();
x,y='',''
for i in range(3):
    x+=str(b[i]%100)
    y+=a[i][1][0]
print(x)
print(y)