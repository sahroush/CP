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
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s;
string q[maxn];
int t;
ll val[10] , len[10];

string parse(string x){
    string ans = "";
    for(int i = 3 ; i < (int)x.size() ; i ++)
        ans += x[i];
    return(ans);
}

void solve(int x , string q){
    ll ans = 0;
    ll sz = 0;
    for(auto i : q){
        ans *= pw(10 , len[i - '0']);
        ans%=mod;
        ans += val[i - '0'];
        ans%=mod;
        sz += len[i - '0'];
        sz%=mod-1;
    }
    val[x] = ans;
    len[x] = sz;
}

int32_t main(){
    migmig
    cin >> s;
    cin >> t;
    for(int i = t-1; i>=0 ; i --)
        cin >> q[i];
    for(int i = 0 ; i < 10 ; i ++)
        val[i] = i , len[i] = 1;
    q[t] = "0->"+s;
    for(int i = 0 ; i <= t ; i ++)
        solve(q[i][0] - '0' , parse(q[i]));
    dokme(val[0])
    return(0);
}