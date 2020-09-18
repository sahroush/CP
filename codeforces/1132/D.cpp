/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld  ,int > pii;

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

ll a[maxn];
ll b[maxn];
ll c[maxn];
ll n , k;
priority_queue < pii > st ;

bool chk(ll x){
    while(st.size())
        st.pop();
    for(int i = 0 ; i < n ; i ++)
        c[i] = a[i];
    for(int i = 0 ; i < n ; i ++)
        if(c[i] >= b[i]*k)
            continue;
        else
            st.push({-ld(c[i])/ld(b[i]) , i });
    for(ll i = 1; i <= k ; i ++){
        if(st.size() == 0)break;
        auto odkodkos = st.top();
        auto v = odkodkos.second;
        st.pop();
        c[v]+=x;
        if(c[v] < b[v] * k)
            st.push({-ld(c[v])/ld(b[v]) , v });
        if(st.size() == 0)
            break;
        auto f = st.top();
        auto s = f.second;
        if(c[s] < i * b[s])
            return(0);
    }
    for(int i = 0 ; i < n ; i ++)
        if(c[i] < b[i]*k)
            return(0);
    return(1);
}

int32_t main(){
    migmig
    cin >> n >> k;
    k--;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> b[i];
    ll r = 2e12 , l = -1;
    while(r - l > 1){
        ll mid = (l + r)/2;
        if(chk(mid))
            r = mid;
        else
            l = mid;
    }
    if(!chk(r))
        dokme(-1);
    dokme(r);
    return(0);
}