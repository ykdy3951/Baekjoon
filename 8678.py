l=list(open(0))
for i in l[1:]:
    a,b=map(int,i.split())
    if b % a:
        print('NIE')
    else:
        print('TAK')