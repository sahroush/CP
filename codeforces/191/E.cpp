/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> obds;

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

ll a[maxn];
ll prt[maxn];
ll n , k;
obds st; // :obd:

ll chk(ll x){
    ll ans = 0;
    st.clear();
    st.insert({0 , -1e18});
    for(int i = 1 ; i <= n ; i ++){
        ans += st.order_of_key({prt[i] - x , 1e18});
        st.insert({prt[i] , i});
    }
    return(ans);
}

int main(){
    migmig
    cin >> n >> k;
    for(int i = 1 ;i <= n ; i ++){
        cin >> a[i]; prt[i] = (prt[i-1] + a[i]);}
    ll l = -1e18 , r = 1e18;
    while(r - l > 1){
        ll mid = (l + r)/2;
        if(chk(mid) >= k) l = mid;
        else r = mid;
    }
    cout << l;
    return(0);
}