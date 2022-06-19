k,p,x=map(int,input().split())
l=[];i=1
while(True):
    l.append(x*i+p*(k/i))
    if len(l) >= 2 and l[-1] > l[-2]:
        break
    i+=1
print('%.3f' %round(min(l), 3))