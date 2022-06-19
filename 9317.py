from math import sqrt
while(True):
    a,b,c=map(float,input().split())
    if [a,b,c]==[0,0,0]:
        break
    print('Horizontal DPI: %.2f' %(round(sqrt(337)*b/(16*a),2)))
    print('Vertical DPI: %.2f' %(round(sqrt(337)*c/(9*a),2)))