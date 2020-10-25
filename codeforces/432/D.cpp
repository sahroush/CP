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

vector < int > kmp(string s){
    int n = s.size();
    vector < int > f(n);
    for(int i = 1; i < n ; i ++){
        int j = f[i-1];
        while(j and s[i]!=s[j])
            j = f[j-1];
        j+=(s[i]==s[j]) , f[i] = j;
    }
    return(f);
}

string s;
vector < int > ch[maxn];
vector < pii > ans;
int sum[maxn];
int cnt[maxn];

void dfs(int v = 0){
    for(int u : ch[v])
        dfs(u) , sum[v] += sum[u];
    sum[v] += cnt[v];
}

int32_t main(){
    migmig;
    cin >> s;
    int n = s.size();
    auto f = kmp(s);
    for(int i = 1 ; i <= n ; i ++){
        ch[f[i-1]].pb(i);
        cnt[f[i-1]] ++;
    }
    dfs();
    while(n){
        ans.pb({n , sum[n] + 1});
        n = f[n-1];
    }
    cout << ans.size() << endl;
    reverse(ans.begin() , ans.end());
    for(auto [f , s] : ans)
        cout << f << ' ' << s << endl;
    return(0);
}