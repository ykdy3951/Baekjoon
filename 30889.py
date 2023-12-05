s='.'*200
for a in list(open(0))[1:]:
    t=(ord(a[0])-65)*20+int(a[1:])-1
    s=s[:t]+'o'+s[t+1:]
print(*[s[i:i+20]for i in range(0,200,20)],sep='\n')