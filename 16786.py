n=int(input())
l=list(map(int,input().split()));l.append(2020)
m=int(input())
for i in list(map(int,input().split())):
    if l[i]-l[i-1]==1:
        continue
    l[i-1]+=1
for i in l[:-1]:
    print(i) 