h,m=map(int,input().split(':'))
t=h*60+m 
if t > 300 and t < 600:
    if t <= 390:
        a=420-t
        b=120-a
        h,m=divmod(420+2*b,60)
        print('%02d:%02d' %(h,m))
    elif t > 390 and t < 420:
        a=420-t+90
        b=120-a
        h,m=divmod(600+b,60)
        print('%02d:%02d' %(h,m))
    else:
        a=600-t
        b=240-a
        h,m=divmod(600+b//2, 60)
        print('%02d:%02d' %(h,m))
elif t > 780 and t < 19*60:
    if t <= 900:
        a=900-t
        b=120-a
        h,m=divmod(900+2*b, 60)
        print('%02d:%02d' %(h,m))
    else:
        a=19*60-t
        b=240-a
        h,m=divmod(19*60+b//2, 60)
        print('%02d:%02d' %(h,m))
else:
    t+=120
    if t >= 24*60:
        t-=24*60
    h,m=divmod(t,60)
    print('%02d:%02d' %(h,m))