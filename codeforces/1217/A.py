t = int(input())
 
for i in range(t):
    a, b, c = map(int, input().split())
    d = (a + b + c)//2+1
    e = a + c
    print(min([c + 1, max([0, e - d + 1])]))