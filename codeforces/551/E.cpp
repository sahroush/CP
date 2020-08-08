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

const ll maxn  = 6e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct com{
    int l = 1e9 , r;
    int size = 0;
    int delta = 0;
    bool retarded = 0;
    unordered_map < int , int > mp;
}comp[800];

int n , q;
int a[maxn];
int sq = 1000;

void update(com &c , int x){
    if(c.delta + x > 1e9){c.retarded = 1;return;}
    c.delta+=x;
}

void add(int l ,int r , int x){
    for(int i = 0 ; i <= n/sq ; i ++){
        if(l > comp[i].r or r < comp[i].l or comp[i].retarded) continue;
        if(l<=comp[i].l and r>=comp[i].r){
            update(comp[i] , x);
        }
        else{
            for(int j = max(comp[i].l , l) ; j <= min(comp[i].r , r) ; j ++){
                if(a[j]==-1)continue;
                comp[i].mp[a[j]]--;
                if(comp[i].mp[a[j]] == 0)comp[i].mp.erase(a[j]);
                if(a[j]*1LL+comp[i].delta*1LL+x*1LL > 1e9)a[j] = -1;
                else{
                    a[j]+=x;
                    comp[i].mp[a[j]]++;
                }
            }
        }
    }
}

int solve(int x){
    int l = 1e9 , r = -1;
    for(int i = 0 ; i <= n/sq ; i ++){
        if(comp[i].retarded)continue;
        if(comp[i].delta >= x) continue;
        if(comp[i].mp.count(x - comp[i].delta)){
        l = min(l , i);
        r = i;}
    }
    if(r == -1)return(-1);
    int mn = 1e9;
    int mx = 0;
    for(int i = comp[l].l ; i <= comp[l].r ; i ++){
        if(a[i] == -1)continue;
        if(a[i]+comp[l].delta == x){mn = i;break;}
    }
    for(int i = comp[r].r ; i >= comp[r].l ; i --){
        if(a[i] == -1)continue;
        if(a[i]+comp[r].delta == x){mx = i;break;}
    }
    return(mx - mn);
}

int main(){
    migmig
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        comp[i/sq].l = min(comp[i/sq].l , i);
        comp[i/sq].r = i;
        comp[i/sq].size ++ ;
        comp[i/sq].mp[a[i]]++;
    }
    while(q -- ){
        int t;
        cin >> t;
        if(t%2){
            int l , r;
            int x;
            cin >> l >> r >> x;
            add(l , r , x); 
        }
        else{
            int y;
            cin >> y;
            cout << solve(y) << endl;
        }
    }
    return(0);
}