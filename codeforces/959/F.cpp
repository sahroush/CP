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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

set < int >  st;
vector < int > boz;
vector < pii > qu[maxn];
int a[maxn] , ans[maxn] , n , q , cur = 1;

void add(int x){
    int val = a[x];
    if(st.count(val))
        cur = (cur + cur)%mod;
    else{
        for(auto i : st)
            boz.pb(i^val);
        for(auto bz : boz)st.insert(bz);
        boz.clear();
    }
    for(auto [f , s] : qu[x])
        ans[s] = int(st.count(f))*cur;
}

int main(){
    migmig
    cin >> n >> q;
    st.insert(0);
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < q ; i ++){
        pii p;cin >> p.first >> p.second;
        qu[p.first - 1].pb({p.second , i});
    }
    for(int i = 0 ; i < n ; i ++)
        add(i);
    for(int i = 0 ; i < q ; i ++)
        cout << ans[i] << endl;
    return(0);
}