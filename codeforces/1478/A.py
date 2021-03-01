q = int(input())
while(q > 0):
    q -= 1
    n = int(input())
    a = list(map(int, input().split()))
    cnt = 1
    lst = a[0]
    ans = 1
    for i in range(1 , n):
        if(a[i] != lst):
            lst = a[i]
            cnt = 0
        cnt += 1
        ans = max(ans , cnt)
    print(ans)