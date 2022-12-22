a,b=map(int,input().split())
print('Sun Mon Tue Wed Thr Fri Sat')
a-=1
print(' '*(4*a),end='')
for i in range(1,b):
    print('%3d' %i,end='')
    if a == 6:
        print()
        a=0
    else:
        print(' ', end='')
        a+=1
print('%3d' %(b))