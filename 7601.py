i=1
while(True):
    n,d=map(int,input().split())
    if [n,d]==[0,0]:
        break
    print('Scenario %d' %i)
    l=[i+1 for i in range(n)]
    r=[i+1 for i in range(n)]
    a=int(input())
    if a != 0:
        del l[a-1]
    a=int(input())
    if a != 0:
        del r[-a]
    for j in range(d):
        a,b=map(int,input().split())
        print('Day %d' %(j+1), end=' ')
        if l[a-1] == r[-b]:
            print('ALERT')
        else:
            print('OK')
    i+=1