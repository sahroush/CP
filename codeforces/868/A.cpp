#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9;
int main(){

    string pass;
    bool f=0,h=0;
    cin>>pass;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s==pass)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        if(s[0]== pass[1])h=1;
        if(s[1]== pass[0])f=1;
    }
    if( h==1 && f==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;

}

