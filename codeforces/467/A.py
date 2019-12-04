n = int(input())
cnt = 0 
for i in range(n):
    a , b = tuple(map (int, input().strip().split()))
    if(a + 2 <= b):
        cnt+=1
print(cnt)
