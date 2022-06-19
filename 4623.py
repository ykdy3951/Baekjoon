while(True):
    a,b,c,d=map(int,input().split())
    if [a,b,c,d]==[0,0,0,0]:
        break
    if a > b:
        a,b=b,a
    if c > d:
        c,d=d,c
    if a <= c and b <= d:
        print('100%')
    else:
        print('%d%%' %(max(1,int(min(c/a*100, d/b*100)))))