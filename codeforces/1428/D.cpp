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
int a[maxn];
vector < int > vec[4];
int match[maxn];
vector < pii > ans;
int mark[maxn];
int par[maxn];

int32_t main(){
    migmig;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = n ; i ; i --)if(a[i]){
        if(a[i] == 1)
            match[i] = i , vec[1].pb(i);
        else if(a[i] == 2){
            if(vec[1].size())
                match[i] = vec[1].back() , vec[1].pop_back();
            else
                dokme(-1);
            vec[2].pb(i);
        }
        else{
            if(vec[3].size())
                match[i] = vec[3].back() , vec[3].pop_back();
            else if(vec[2].size())
                match[i] = vec[2].back() , vec[2].pop_back();
            else if(vec[1].size())
                match[i] = vec[1].back() , vec[1].pop_back();
            else
                dokme(-1);
            vec[3].pb(i);
        }
    }
    int cur = n;
    for(int i = n; i  ; i --){
        if(a[i] == 1){
            ans.pb({i , cur});
            mark[i] = cur;
            cur -- ;
        }
        if(a[i] == 2){
            ans.pb({i , mark[match[i]]});
            mark[i] = mark[match[i]];
        }
        if(a[i] == 3){
            ans.pb({i , cur});
            ans.pb({match[i] , cur});
            mark[i] = cur;
            cur -- ;
        }
    }
    cout << ans.size() << endl;
    for(auto [s , f] : ans)
        cout << f << ' ' << s << endl;
    return(0);
}