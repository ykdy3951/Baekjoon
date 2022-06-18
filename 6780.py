l=list(map(int,open(0)));i=1
while(True):
    if l[i-1] - l[i] < 0:
        break
    l.append(l[i-1]-l[i])
    i+=1
print(i+1)