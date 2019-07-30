a,b=input(),input()
cnt=0
for i in range(len (a)):
    cnt+=ord(a[i].upper())-ord(b[i].upper())
    if cnt>0:
        print(1)
        exit()
    if cnt <0:
        print(-1)
        exit()
print(0)
