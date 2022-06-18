h,m=map(int,open(0));t=0
for i in range(1,m+1):
    if -6*(i**4)+h*(i**3)+2*(i**2)+i <= 0:
        t=i
        print('The balloon first touches ground at hour: %d' %t)
        break
if t == 0:
    print('The balloon does not touch ground in the given time.')