import sys
input=sys.stdin.readline
x=[
    ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'],
    ['a','b','k','d','e','g','h','i','l','m','n','ng','o','p','r','s','t','u','w','y']
]
l=[]
for _ in range(int(input())):
    s=input().rstrip()
    t='';f=False
    for j in range(len(s)):
        if f:
            f=False
            continue
        if j < len(s)-1:
            if s[j:j+2] == 'ng':
                t+=x[0][x[1].index('ng')]
                f=True                
                continue
        t+=x[0][x[1].index(s[j])]
    l.append(t)
l.sort()
for s in l:
    t=''
    for i in range(len(s)):
        t+=x[1][x[0].index(s[i])]
    print(t)