def s(r,g,b,a,c):
    return a*(r*r+g*g+b*b)+c*min(r,g,b)
for _ in range(int(input())):
    a,c=map(int,input().split());r,g,b=map(int,input().split())
    x,y,z=s(r+1,g,b,a,c),s(r,g+1,b,a,c),s(r,g,b+1,a,c)
    print('RED'if x>y and x>z else['GREEN','BLUE'][y<z])