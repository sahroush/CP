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

const ll maxn  = 1e6+100;
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

int n , k;
set < int > st;
int a[maxn];
int pos[maxn];

int fen[maxn];

void add(int pos,int x){
    for(;pos<maxn;pos+=pos&(-pos))
        fen[pos]+=x;
}
int get(int pos){
    int ans = 0;
    for(;pos;pos-=pos&(-pos))
        ans+=fen[pos];
    return(ans);
}
int sum(int l , int r){
    l++ , r --;
    return(get(r) - get(l - 1));
}

int32_t main(){
    migmig
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i],
        pos[a[i]] = -i;
    for(int i = 1 ; i <= k ; i ++){
        int x;
        cin >> x;
        pos[x]*=-1;
    }
    for(int i = 1 ; i<= n; i ++)
        add(i , 1);
    st.insert(0),st.insert(n + 1);
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++){
        if(pos[i] > 0){
            st.insert(pos[i]);
            continue;
        }
        pos[i]*=-1;
        auto l = st.lower_bound(pos[i]);
        auto r = l--; 
        ans += sum(*l , *r);
        add(pos[i] , -1);
    }
    cout << ans;
    return(0);
}