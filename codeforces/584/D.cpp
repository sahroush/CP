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
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;

bool prime(int x){
    if(x < 2)return(0);
    for(int i = 2 ; i * i <= x ; i ++)
        if(x%i == 0)
            return(0);
    return(1);
}

int32_t main(){
    migmig
    cin >> n;
    if(prime(n)){
        cout << 1 << endl;
        dokme(n);
    }
    if(prime(n - 4)){
        cout << 3 << endl;
        cout << 2 << ' ' << 2 <<  ' ' << n-4;
        return(0);
    }
    int a = n-2;
    while(!prime(a))
        a--;
    n = n - a;
    if(prime(n)){
        cout << 2 << endl;
        cout << a << ' ' ;
        dokme(n);
    }
    cout << 3 << endl;
    for(int i = 3 ; i < n ; i ++)
        if(prime(i) and prime(n - i))
        {
            cout << a << ' ' << i << ' ' << n-i;
            return(0);
        }
    return(0);
}