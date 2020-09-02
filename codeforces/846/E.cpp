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

const ll maxn  = 1e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int boz = 0;

struct node{
    int par;
    vector < int > ch;
    int zarib; //zaribe inke babash befreste be in
    int val , target;   
}m[maxn];

void dfs(int v){
    for(auto u : m[v].ch)
        dfs(u);
    m[v].val -= m[v].target;
    if(v == 1)
        return;
    if(m[v].val >= 0){
        m[m[v].par].val += m[v].val;
        return;
    }
    if(1e17 / m[v].zarib < abs(m[v].val))
        boz = 1;
    m[m[v].par].val += m[v].zarib * m[v].val;
    if(m[m[v].par].val < -1e17)
        boz = 1;
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> m[i].val;
    for(int i = 1 ; i <= n ; i ++)
        cin >> m[i].target;
    for(int i = 2 ; i <= n ; i ++){
        cin >> m[i].par;
        cin >> m[i].zarib;
        m[m[i].par].ch.pb(i);
    }
    dfs(1);
    if(boz)
        dokme("NO");
    cout << ((m[1].val >= 0)?"YES":"NO");
    return(0);
}