import sys
input=sys.stdin.readline
while True:
    n=int(input())
    if n==-1:
        break
    divisor_list=[]
    for i in range(1,n):
        if n % i == 0:
            divisor_list.append(i)
    
    if sum(divisor_list) == n:
        print(f'{n} = {" + ".join(map(str,divisor_list))}')
    else:
        print(f'{n} is NOT perfect.') 