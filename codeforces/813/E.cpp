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

const ll maxn  = 1e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int a[maxn];
int n , k ;
int q;

deque < int > dq[maxn];

struct segment{
    int maxn;
    vector < vector < int >  > seg;
    segment (int n):
        maxn(n+100) , seg(4 * maxn){}
    void build(int v = 1,  int l = 1 , int r = 0){
        if(!r) r = maxn;
        if(r - l == 1){
            seg[v].pb(a[l]);
            return;
        }
        int mid = (l + r)/2;
        build(2*v , l , mid);
        build(2*v + 1 , mid , r);
        seg[v] = seg[2*v + 1];
        for(auto x : seg[2*v])
            seg[v].pb(x);
        sort(seg[v].begin() , seg[v].end());
    }
    int query(int L , int R , int v = 1 , int l = 1 , int r = 0){
        if(!r) r = maxn;
        if(R <= l or r <= L)
            return(0);
        if(L <= l and r <= R){
            return(lower_bound(seg[v].begin() , seg[v].end() , L ) - seg[v].begin());
        }
        int mid = (l + r)/2;
        return(query(L , R , 2*v , l , mid) + query(L , R , 2*v + 1 , mid , r));
    }
};

int32_t main(){
    migmig;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 1 ; i <= n ; i ++){
        dq[a[i]].pb(i);
        int x = dq[a[i]].front();
        if((int)dq[a[i]].size() > k)
            dq[a[i]].pop_front() , a[i] = x;
        else
            a[i] = 0;
    }
    segment seg(n);
    seg.build();
    cin >> q;
    int lst = 0;
    while(q -- ){
        int l , r;
        cin >> l >> r;
        l = (lst + l)%n + 1 , r = (lst + r)%n + 1;
        if(l > r)swap(l , r);
        cout << (lst = seg.query(l , ++r)) << endl;
    }
    return(0);
}