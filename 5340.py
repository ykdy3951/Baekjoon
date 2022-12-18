l=[]
for _ in range(6):
    l.append(len(input().rstrip()))
print("Latitude %d:%d:%d" %(l[0],l[1],l[2]))
print("Longitude %d:%d:%d" %(l[3],l[4],l[5]))