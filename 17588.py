l=list(map(int,open(0)))[1:]
i=1;f=True
for a in l:
    while(a != i):
        print(i)
        f=False
        i+=1
    i+=1
if f: print('good job')