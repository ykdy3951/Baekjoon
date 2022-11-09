n=input();a,b=0,0
for i in range(len(n)):
    if n[i] == '(':
        if n[i+1] == '(':
            b+=1
        else:
            a+=b
    else:
        if n[i-1] == ')':
            a+=1
            b-=1
print(a)