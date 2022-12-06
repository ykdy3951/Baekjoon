def S(n):
    if int(n) <= 0:
        return 0
    l=[0]*10
    ret=0
    num=1

    while n > 0:
        x,y=divmod(n,num*10)
        for i in range(10):
            l[i]+=x*num
        for i in range(1,y//num+1):
            l[i]+=num
        l[(y//num+1)%10]+=y%num
        n-=9*num
        num*=10
    for i in range(10):
        ret+=l[i]*i
    return ret

for i in range(int(input())):
    a,b=map(int,input().split())
    print(S(b)-S(a-1))