/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
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
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > d;
vector < vector < int > > ans;

void solve(vector < int > v){
    vector < vector < int > > res;
    vector < int > cur;
    int ind = 0;
    for(int i : v){
        cur.clear();
        for(int j = 0 ; j < i ; j ++)
            cur.pb(d[ind ++ ]);
        res.pb(cur);
    }
    reverse(res.begin() , res.end());
    d.clear();
    for(auto v : res)
        for(auto j : v)
            d.pb(j);
}

bool chk(){
    for(int i = 1 ; i <= n ; i ++)
        if(d[i-1]!=i)return(0);
    return(1);
}

bool khc(){
    for(int i = 1 ; i <= n ; i ++)
        if(d[i-1]!=n - i + 1)return(0);
    return(1);
}

bool mark[64];

int32_t main(){
    migmig;
    cin >> n;
    d.reserve(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> d[i];
    while(!chk()){
        if(khc()){
            vector < int > bz(n , 1);
            solve(bz);
            ans.pb(bz);
            break;
        }
        int l = -1 , r = 0;
        ms(mark , 0);
        for(int i = 0 ; i < n ; i ++){
            if(d[i] > 1 and !mark[d[i]-1] and l == -1)l = i;
            if(l != -1 and d[i] == d[l]-1)r = i;
            mark[d[i]] = 1;
        }
        vector < int > bz;
        if(l)
            bz.pb(l);
        int k;
        for(int i = l ; i < r ; i ++){
            if(d[i] > d[i + 1])
                k = i;
        }
        bz.pb(k - l + 1);
        if(r - k)
            bz.pb(r - k);
        if(n - r - 1)
            bz.pb(n - r - 1);
        solve(bz);
        ans.pb(bz);
        bz.clear();
    }
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.size() << ' ';
        for(auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    return(0);
}