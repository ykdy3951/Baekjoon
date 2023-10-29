from math import *
x1,y1,z1,x2,y2,z2,x3,y3,z3 = map(int,input().split())

class Point:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def __sub__(self, other):
        return sqrt((self.x-other.x)**2+(self.y-other.y)**2+(self.z-other.z)**2)

def area(p1 : Point, p2 : Point, p3 : Point):
    a = p1-p2
    b = p2-p3
    c = p3-p1
    s = (a+b+c)/2
    return sqrt(s*(s-a)*(s-b)*(s-c))

p1 = Point(x1,y1,z1)
p2 = Point(x2,y2,z2)
p3 = Point(x3,y3,z3)

distance1 = p1-p2
distance2 = p2-p3
distance3 = p3-p1

if max(distance1,distance2,distance3) == distance2 and distance2**2 > (distance1**2+distance3**2):
    print(distance3)
elif max(distance1,distance2,distance3) == distance3 and distance3**2 > (distance1**2+distance2**2):
    print(distance2)
else:
    areaOfPoints = area(p1,p2,p3)
    print(areaOfPoints/distance1*2)