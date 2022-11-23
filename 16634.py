a,b=input().split();s=''
if a == 'E':
    t='';c=0
    for i in b:
        if i == t:
            c+=1
        else:
            if t != '':
                s+=t+str(c)
            t=i;c=1
    print(s+t+str(c))
else:
    for i in range(0,len(b),2):
        s+=b[i]*int(b[i+1])
    print(s)