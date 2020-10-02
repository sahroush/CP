/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
//#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int ask(int c , int d){
    cout << "? " << c << ' ' << d << endl;
    int ans;
    cin >> ans;
    return(ans);
}

int a = 0 , b = 0;

int32_t main(){
    migmig
    int big = ask( 0 , 0 ); 
    for(int i = 29 ; i >= 0 ; i --){
        int res = ask(a^(1 << i) , b);
        int ser = ask(a , b^(1 << i));
        if(ser == res){
            if(res == 1 and big == 1)
                a^=(1 << i);
            else if(res == 1 and big == -1)
                b^=(1 << i),big = -1;
            else if(res == -1 and big == -1)
                b^=(1 << i);
            else if(res == -1 and big == 1)
                a^=(1 << i);
            else if(res == 0 and big == 1)
                a^=(1 << i);
            else
                b^=(1 << i);
            big = res;
        }
        else{
            if(res == -1)
                a^=(1 << i) , b^=(1 << i);
        }
    }
    cout << "! " << a << ' ' << b;
    return(0);
}