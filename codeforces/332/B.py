n,k=map(int,input().split())
a=list(map(int,input().split()))
 
dp=[0]
for i in range(n):
    dp+=[dp[i]+int(a[i])]
 
ans1=0
ans2=0
b=0
pb=0
z=0
for i in range(n-2*k+1,0,-1):
	c=dp[i+2*k-1]-dp[i+k-1]
	if c>=b:
		b=c
		pb=i+k
	ca=dp[i+k-1]-dp[i-1]
	if ca+b>=z:
		z=ca+b
		ans1=i
		ans2=pb
 
print(ans1,ans2)
