for i in range(int(input())):
    l=input()
    if '.' in l:
        d,m,y=map(int,l.split('.'))
    else:
        m,d,y=map(int,l.split('/'))
    print('%02d.%02d.%04d %02d/%02d/%04d' %(d,m,y,m,d,y))