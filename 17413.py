l=input()
i=0
while i < len(l):
    if l[i] == '<':
        i+=1
        print('<',end='')
        while True:
            print(l[i],end='')
            if l[i] == '>':
                i+=1
                break
            i+=1  
    elif l[i] == ' ':
        print(' ',end='')
        i+=1
    else:
        s=''
        while i < len(l):
            if l[i] in ' <>':
                print(s[::-1],end='')
                s=''
                break
            s+=l[i]
            i+=1
        print(s[::-1],end='')
print()