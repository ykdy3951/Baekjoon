for _ in range(int(input())):
    l=list(map(int,input().split()))
    n=l[0];l=l[1:];l.sort();s='no'
    for i in range(n):
        if l[i]+l[-(i+1)] != n:
            s='yes'
            break
    print(s)
