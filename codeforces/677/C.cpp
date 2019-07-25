#include<iostream>
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
const int maxn=100010;
char s[maxn];
long long n[maxn];



int main()
{
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            n[i&j]++;
        }
    }
    scanf("%s",s);
    long long cnt=1;
    for(int i=0;s[i];i++){
        int boz;
        if(s[i]>='0' and s[i]<='9'){
            boz=s[i]-'0';
        }
        else if(s[i]>='A' and s[i]<='Z'){
            boz=s[i]-'A'+10;
        }
        else if(s[i]>='a' and s[i]<='z'){
            boz=s[i]-'a'+36;
        }
        else if(s[i]=='-'){
            boz=62;
        }
        else if(s[i]=='_'){
            boz=63;
        }
        cnt=cnt*(n[boz])%M;
    }
    printf("%lld\n",cnt%M);
    return 0;
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.

