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

const ll maxn  = 2e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k , q;
int a[maxn] , r[maxn] , x[maxn] , y[maxn];
vector < int > comp , R[maxn], Qu[maxn];
int fen[maxn];
int ans[maxn];

void add(int pos){
    for(; pos < maxn ; pos += pos & -pos)
        fen[pos]++;
}

int get(int pos){
    int ans = 0;
    for( ; pos ; pos -= pos & -pos)
        ans += fen[pos];
    return(ans);
}

int get(int l , int r){
    return(get(r) - get(l - 1));
}

int bm(int x){
    return(lower_bound(comp.begin() , comp.end() , x) - comp.begin() + 5);
}

struct segment{
    vector < int > seg;
    segment(int x):
        seg(maxn*4 , -1){}
    void update(int x , int pos , int v = 1, int l = 1, int r = maxn){
        if(r - l == 1){
            seg[v] = max(seg[v] , x);
            return;
        }
        int mid = (l + r)/2;
        if(pos < mid){
            update(x , pos , 2*v , l , mid);
        }
        else{
            update(x , pos , 2*v +1 , mid , r);
        }
        seg[v] = max(seg[2*v] , seg[2*v + 1]);
    }
    int query(int L , int R , int v = 1 , int l = 1, int r = maxn){
        if(r <= L or R <= l)
            return(-1);
        if(L <= l and r <= R)
            return(seg[v]);
        int mid = (l + r)/2;
        return(max( query(L , R , 2*v , l , mid) ,  query(L , R , 2*v + 1 , mid , r)));
    }
};
segment mxseg(2);

int32_t main(){
    migmig
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++)
        cin >> r[i], comp.pb(r[i]);
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i], comp.pb(a[i]) , comp.pb(a[i] + k) , comp.pb(a[i] - k);
    comp.pb(-1e18), comp.pb(1e18);
    sort(comp.begin() , comp.end());
    comp.resize(unique(comp.begin() , comp.end()) - comp.begin());
    for(int i = 1 ; i <= n ; i ++)
        R[bm(r[i])].pb(i);
    for(int i = 0 ; i < maxn ; i ++){
        for(auto x : R[i])
            add(bm(a[x]));
        for(auto x : R[i])
            ans[x] = get(bm(a[x] - k) , bm(a[x] + k));
    }
    cin >> q;
    for(int i = 0 ; i < q ; i ++)
        cin >> x[i] >> y[i], Qu[bm(max(r[x[i]] , r[y[i]]))].pb(i);
    for(int i = maxn-1 ; i >= 0 ; i --){
        for(auto x : R[i])
            mxseg.update(ans[x] , bm(a[x]));
        for(auto j : Qu[i]){
            x[j] = mxseg.query(bm(max(a[x[j]] , a[y[j]]) - k) ,bm(min(a[x[j]] , a[y[j]]) + k)+1);        
        }
    }
    for(int i = 0 ; i < q ; i ++)
        cout << x[i] << endl;
    return(0);
}
