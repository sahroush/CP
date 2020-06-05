#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , m;
ll l[maxn] , r[maxn] , q[maxn];
ll fen[maxn][32];
ll b[maxn][32];

void udp(ll pos , ll x ,ll ind){
    for(;pos<maxn;pos+=pos&(-pos))
        fen[pos][ind]+=x;
}

ll sum(ll pos , ll x){
    ll ans = 0;
    for(;pos;pos-=pos&(-pos))
        ans+=fen[pos][x];
    return((ans)?(1 << x) : 0);
}

void add(ll x){
    cin >> l[x] >> r[x] >> q[x];
    for(ll i = 0 ; i <= 30 ; i ++)
        if(q[x] & (1<<i))
            udp(l[x] , 1 , i) , udp(r[x]+1 , -1 , i);
}

ll get(ll l , ll r){
    ll ans = b[l][0];
    for(ll i = 17 ; i >= 0 ; i --)
        if(l + (1LL << i)-1 <= r)
            ans&=b[l][i] , l+=(1LL << i);
    return(ans);
}

bool chk(ll x){
    return(get(l[x] , r[x]) == q[x]);
}

int main(){
    migmig
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i ++)
        add(i);
    for(ll i = 1 ; i <= n ; i ++)
        for(ll j = 0 ; j <= 30 ; j ++)
            b[i][0]|=sum(i,j);
    for(ll i = 1 ; i <= 17 ; i ++)
        for(ll j = 1 ; j <= n ; j ++)
            if(j + (1LL << i)-1 <= n)
                b[j][i] = b[j][i-1] & b[j + (1LL << (i-1))][i-1];
    for(ll i = 0 ; i < m ; i ++)
        if(!chk(i))
            dokme("NO");
    cout << "YES" << endl;
    for(ll i = 1 ; i <= n ; i ++)
        cout << b[i][0] << ' ';
    return(0);
}