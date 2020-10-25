//*
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

int a[10];
int n;
int b[maxn];
vector < pii > d;
set < int > st;
int cnt[maxn];

void add(int x){
    cnt[d[x].second] ++;
    if(cnt[d[x].second] == 1)
        st.insert(d[x].second);
}

void rm(int x){
    cnt[d[x].second] --;
    if(cnt[d[x].second] == 0)
        st.erase(d[x].second);
}

int32_t main(){
    migmig;
    int mn = 1e9;
    for(int i = 0 ; i < 6 ; i ++)
        cin >> a[i] , mn = min(mn , a[i]);
    cin >> n;
    if(n == 1)dokme(0);
    for(int i = 0 ; i < n ; i ++ )
        cin >> b[i] , mn = min(mn , b[i]);
    sort(b , b + n);
    sort(a , a + 6);
    mn = 1e9;
    d.pb({-102 , 0});
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < 6 ; j ++)
            d.pb({b[i] - a[j] , i});
    sort(d.begin() , d.end());
    int l =  0 , r = 0;
    add(0);
    int ans = 1e9;
    while(r!=n * 6){
        if((int)st.size() == n)
            ans = min(ans ,  d[r].first - d[l].first),
            rm(l),
            l++;
        else
            r ++ ,
            add(r);
    }
    cout  << ans;
    return(0);
}