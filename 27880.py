ans=0
for i in list(open(0)):
    a,b=i.split();b=int(b)
    if a == 'Es':
        ans += b * 21
    else:
        ans += b * 17
print(ans)