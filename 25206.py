import sys
input=sys.stdin.readline
grade_dict = {'A+' : 4.5, 'A0': 4.0, 'B+': 3.5, 'B0': 3.0, 'C+': 2.5, 'C0': 2.0, 'D+': 1.5, 'D0': 1.0, 'F': 0.0}
ans=0;cnt=0
for i in range(20):
    a,b,c=input().split()
    b=float(b);c=c.rstrip()
    if c == 'P': continue
    cnt+=b
    ans+=b*grade_dict[c]
print('%f'%(ans/cnt))