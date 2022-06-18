from math import sqrt
l=[]
for i in range(3):
    l.append(list(map(int,input().split())))
a=sqrt((l[1][0]-l[0][0])**2+(l[1][1]-l[0][1])**2)
b=sqrt((l[2][0]-l[0][0])**2+(l[2][1]-l[0][1])**2)
c=sqrt((l[1][0]-l[2][0])**2+(l[1][1]-l[2][1])**2)

r = sqrt(4*a*a*b*b-(a*a+b*b-c*c)**2) / (2* (a+b+c))
r2=float(input())
print(((r-r2)/r2*100))