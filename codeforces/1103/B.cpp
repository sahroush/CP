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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s;

bool ask(int x , int y){
    cout << "? " << x << ' ' << y << endl;
    string ans;
    cin >> ans;
    return(ans == "x");
}

pii find(int l = 0 , int r = 1){
    if(ask(l , r))
        return(pii(l , r));
    return(find(r , r * 2));
}

int find(int base ,int l , int r){
    while(r - l > 1){
        int mid = (l + r)/2;
        if(ask(l , mid))
            r = mid;
        else
            l = mid;
    }
    return(r);
}

int query(){
    auto [l , r] = find();
    return(find(l , l , r));
}

int32_t main(){
    migmig
    cin >> s;
    while(s == "start"){
        int ans = query();
        cout <<  "! "<< ans << endl;
        cin >> s;
    }
    return(0);
}