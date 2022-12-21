l=[]
a=int(input())
b=int(input())
c=int(input())
d=int(input())
x=int(input())
for i in range(0,x//a+1):
    y=x-i*a
    for j in range(0,y//b+1):
        z=y-j*b
        for k in range(0, z//c+1):
            if (z-k*c) % d:
                continue
            l.append([i+j+k+(z-k*c)//d,i,j,k,(z-k*c)//d])
l.sort()
for i in l:
    print('# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d' %(i[1],i[2],i[3],i[4]))
print('Total combinations is %d.' %(len(l)))
print('Minimum number of tickets to print is %d.' %(l[0][0]))