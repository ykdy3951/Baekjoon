while(True):
    a,b,c=map(float,input().split())
    s=''
    if (a,b,c) == (0,0,0):
        break
    if a <= 4.5 and b >= 150 and c >= 200:
        s+='Wide Receiver '
    if a <= 6.0 and b >= 300 and c >= 500:
        s+='Lineman '
    if a <= 5.0 and b >= 200 and c >= 300:
        s+='Quarterback '        
    print('No positions' if s == '' else s)