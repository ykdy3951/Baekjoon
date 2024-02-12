import sys
input=sys.stdin.readline
for _ in range(int(input())):
    s=input().strip()
    l=[0]*8
    for i in range(3,41):
        t=s[i-3:i]
        if t == 'TTT':
            l[0]+=1
        elif t == 'TTH':
            l[1]+=1
        elif t == 'THT':
            l[2]+=1
        elif t == 'THH':
            l[3]+=1
        elif t == 'HTT':
            l[4]+=1
        elif t == 'HTH':
            l[5]+=1
        elif t == 'HHT':
            l[6]+=1
        else:
            l[7]+=1
    print(*l)