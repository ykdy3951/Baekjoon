l=[1]*1000001
l[0]=l[1]=0
for i in range(2,1000001):
    for j in range(i*i,1000001,i):
        l[j]=0
for i in range(int(input())):
    n=int(input());s=0
    for j in range(2,n//2+1):
        if l[j] and l[n-j]:
            s+=1
    print(s)