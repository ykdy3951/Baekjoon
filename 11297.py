while(True):
    s=sum(map(int,input().split()))
    if s == 0:
        break
    s%=25
    t=''
    for i in input():
        if i >= 'a' and i <= 'z':
            i=ord(i)-s-1
            if i < 97:
                i+=26
            i=chr(i)
        t+=i
    print(t)