from datetime import datetime
l=["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
d='2009'
b,a=input().split();d+='-'+a+'-'+b
d=datetime.strptime(d,'%Y-%m-%d')
print(l[d.weekday()])