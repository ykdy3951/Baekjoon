n=int(input())
a=[list(map(int,input().split())) for i in range(n)]
ans=[]
for i in range(n):
    for j in range(n):
        if a[i][j]==1:
            
            #  Find the horizontally maximal black run from i. = k
            #  Assume pixels in (i,j) to (i,k-1) are all black.
            #  Find the vertically and maximal black run from i. = l
            #  Assume pixels in (i,j) to (j,l-1) are all black.
            #  // so rectangle region [i,k-1] × [j,l-1] is a black rectangle
            #  XOR (j, k-1, i, l-1);

            k = j
            while k < n and a[i][k] == 1:
                k += 1
            l = i
            while l < n and a[l][j] == 1:
                l += 1
            ans.append((j+1, k, i+1, l))
            for x in range(i, l):
                for y in range(j, k):
                    a[x][y] ^= 1
print(len(ans))
for i in ans[::-1]:
    print(*i)