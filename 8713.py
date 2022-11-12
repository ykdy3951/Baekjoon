a,b=input().split();l=['*','+','-']
m=[]
for i in range(3):
    m.append(eval(a+l[i]+b))
if m.count(max(m)) > 1:
    print('NIE')
else:
    i=m.index(max(m))
    print(['','('][int(a)<0]+a+['',')'][int(a)<0]+l[i]+['','('][int(b)<0]+b+['',')'][int(b)<0]+'='+['','('][m[i]<0]+str(m[i])+['',')'][m[i]<0])