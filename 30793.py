p,r=map(int,input().split());a=p*10//r
print(['','very '][a>5]+['weak','normal','strong'][min(a,5)//2])