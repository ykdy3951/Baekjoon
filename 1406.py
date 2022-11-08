import sys
input=sys.stdin.readline

l=list(input().strip())
r=[]

for i in range(int(input())):
    cmd=input().split()
    if cmd[0] == 'L':
        if l != []:
            r.append(l.pop())
    elif cmd[0] == 'D':
        if r != []:
            l.append(r.pop())
    elif cmd[0] == 'B':
        if l != []:
            l.pop()
    else:
        l.append(cmd[1])

while r:
    l.append(r.pop())
print(''.join(l))