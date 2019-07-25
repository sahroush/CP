#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<list>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define MOD 1000000007
using namespace std;
const int maxn=100010;
char str[maxn];
long long num[maxn];
int main()
{
    for(int i=0;i<64;++i){
        for(int j=0;j<64;++j){
            num[i&j]++;//????i&j??????????i j??
        }
    }
    scanf("%s",str);
    long long ans=1;
    for(int i=0;str[i];++i){
        int temp;
        if(str[i]>='0'&&str[i]<='9'){
            temp=str[i]-'0';
        }
        else if(str[i]>='A'&&str[i]<='Z'){
            temp=str[i]-'A'+10;
        }
        else if(str[i]>='a'&&str[i]<='z'){
            temp=str[i]-'a'+36;
        }
        else if(str[i]=='-'){
            temp=62;
        }
        else if(str[i]=='_'){
            temp=63;
        }
        ans=ans*(num[temp])%MOD;
    }
    printf("%lld\n",ans%MOD);
    return 0;
}
