import sys
input=sys.stdin.readline

l = ['a','e','i','o','u']
s=input().rstrip()
ans=0
for i in l:
    ans+=s.count(i)
print(ans, ans+s.count('y'))