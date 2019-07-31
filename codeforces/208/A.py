a=input()
i=0
flag=0
while (1):
    if i<=len(a)-3:
        if a[i]=="W" and a[i+1] == "U" and a[i+2] == "B":
            a=a[:i]+" "+a[i+3:]
            i=0
            flag=1
    elif i==len(a):
        break
    if flag==0:
        i+=1
    else:
        flag=0
s=' '
for i in range (len(a)-1):
    if a[i]!=a[i+1] and a[i]==" " and s[len(s)-1]!=" ":
        s+=" "
    elif a[i]!=" ":
        s+=a[i]
if a[len(a)-1]!=" ":
    s+=a[len(a)-1]
if s[0]==" ":
    s=s[1::]
print(s)
