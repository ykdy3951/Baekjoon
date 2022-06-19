for i in range(int(input())):
    a,b=map(int,input().split())
    print('Case %d:' %(i+1), end=' ')
    s=''
    s+=str(a//b)+' ' if a//b else ''
    s+=str(a%b)+'/'+str(b) if a%b else ''
    print(s if s else '0')