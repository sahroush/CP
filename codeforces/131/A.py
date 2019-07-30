s=input()
f=0
for i in range(1,len(s)):
    if s[i]!=s[i].lower():
        f+=1
if f==len(s)-1:
    
    a=""
    for i in range(len(s)):
        if s[i]==s[i].upper():
            a+=s[i].lower()
        else:
            a+=s[i].upper()
    print(a) 
else:
    print(s)
