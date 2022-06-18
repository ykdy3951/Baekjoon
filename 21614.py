l=list(map(int,open(0)))
t=''
for i in l[:-1]:
    if sum(divmod(i//1000, 10)) % 2:
        t='left'
    elif sum(divmod(i//1000, 10)) != 0:
        t='right'
    print(t,i%1000)