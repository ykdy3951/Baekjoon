a=list(map(int,input().split()))
b=list(map(int,input().split()))
x=0;y=0
for i in a:
    for j in b:
        if i > j:
            x+=1
        elif i < j:
            y+=1
print('%.5f' %(x / (x+y)))