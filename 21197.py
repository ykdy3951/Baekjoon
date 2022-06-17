l=list(map(int,open(0)))
if len(l) % 2:
    s=0
    for i in range(1, len(l), 2):
        s+=l[i+1]-l[i]
    print(s)
else:
    print('still running')