for _ in range(int(input())):
    a,b,c,d=map(int,input().split())
    print('Tie' if a*b==c*d else ['TelecomParisTech','Eurecom'][a*b<c*d])