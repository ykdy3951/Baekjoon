a=100;b=1000;c=10;d=111
for i in range(a,b):
    for j in range(a,b):
        if i%d or j%d:
            if i*(j%a)==(i//c)*j and i%c==j//a:
                print(i,'/',j,'=',i//c,'/',j%a)  