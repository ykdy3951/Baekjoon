l=list(open(0))[1:]
for i,j in enumerate(l):
    t=''
    if int(j) < 26:
        t='World Finals'
    elif int(j) < 1001:
        t='Round 3'
    elif int(j) < 4501:
        t='Round 2'
    else:
        t='Round 1'
    print('Case #%d: %s'%(i+1,t))