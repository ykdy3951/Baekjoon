input();l=list(map(int,input().split()));s=0
for i in l:
    if i == 0:
        s+=2
        continue
    s+=1/i
print(s)