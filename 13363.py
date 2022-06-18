a,b=map(int,open(0))
if b - a > 180:
    print(b-a-360)
elif b - a <= -180:
    print(b-a+360)
else:
    print(b-a)