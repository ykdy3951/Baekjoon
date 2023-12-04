n=int(input());l=list(map(int,input().split()))+[0]*(5-n)
print((l[4]*707+abs(l[0]-l[2])*[108,508][l[0]>l[2]]+abs(l[1]-l[3])*[305,212][l[1]>l[3]])*4763)
