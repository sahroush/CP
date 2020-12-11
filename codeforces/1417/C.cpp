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

int q;
int n;
int a[maxn];
vector < int > pos[maxn];
int ans[maxn];
vector < pii > vec;

int32_t main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n;
        for(int i = 1; i <= n ; i ++)
            cin >> a[i],
            pos[i].clear(),
            pos[i].pb(0);
        for(int i = 1 ; i <= n ; i ++){
            pos[a[i]].pb(i),
            ans[i] = 0;
        }
        for(int i = 1 ; i <= n ; i ++){
            pos[i].pb(n+1);
        }
        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1 ; j < pos[i].size() ; j ++)
                ans[i] = max(ans[i] , pos[i][j] - pos[i][j-1]);
        }
        vec.clear();
        for(int i = 1 ; i <= n ; i ++)
            vec.pb({ans[i] , i});
        sort(vec.begin() , vec.end());
        int res = 1e9;
        int pos = 0;
        for(int i = 1 ; i <= n ; i ++){
            while(pos < vec.size() and vec[pos].first == i)
                res = min(res , vec[pos].second),pos++;
            if(res == 1e9)
                cout << -1 << ' ';
            else
                cout << res << ' ';
        }
        cout << endl;
    }




    return(0);
}