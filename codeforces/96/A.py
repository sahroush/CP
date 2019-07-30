s=input()
cnt=0
l=["h","e","l","l","o"]
for i in range(1,len(s)):
    if s[i]==s[i-1]:
        cnt+=1
    else:
        cnt=0
    if cnt==6:
        print("YES")
        exit()
        
print("NO")
