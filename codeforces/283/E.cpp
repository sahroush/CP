/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 1e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , k;
int s[maxn];
vector < int > segl[maxn] , segr[maxn];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

int seg[maxn*4];
int lazy[maxn*4];

void shift(int v , int l , int r){
  if(!lazy[v])return;
  if(r - l > 1)
    lazy[lc] ^= 1 , lazy[rc] ^= 1;
  seg[v] = r - l - seg[v];
  lazy[v] = 0;
}

void update(int L , int R , int v = 1 , int l = 0 , int r = n){
  shift(v , l , r);
  if(r <= L or R <= l)
    return;
  if(L <= l and r <= R){
    lazy[v]=1;
    shift(v , l , r);
    return;
  }
  update(L , R , lc , l , mid);
  update(L , R , rc , mid , r);
  seg[v] = seg[lc] + seg[rc];
}

int query(int L , int R , int v = 1 , int l = 0 , int r = n){
  shift(v , l , r);
  if(r <= L or R <= l)
    return(0);
  if(L <= l and r <= R)
    return(seg[v]);
  return(query(L , R , lc , l , mid) + query(L , R , rc , mid , r));
}


int32_t main(){
  migmig;
  cin >> n >> k;
  for(int i = 0 ; i < n ; i ++)
    cin >> s[i];
  sort(s , s + n);
  while(k --){
    int l , r;
    cin >> l >> r;
    l = lower_bound(s , s + n , l) - s;
    r = upper_bound(s , s + n , r) - s - 1;
    if(l > r)continue;
    segl[l].pb(r) , segr[r].pb(l);
	}
  ll ans = n * (n - 1) * (n - 2) / 6;
  for(int i = 0 ; i < n ; i ++){
    for(auto r : segl[i])
      update(i , r + 1);
    ll res = 0;
    if(i)
      res = i - query(0 , i);
    if(i^(n-1))
      res += query(i + 1 , n);
    ans -= res * (res - 1) / 2;
    for(int l : segr[i])
      update(l , i + 1);
  }
  cout << ans;
  return(0);
}
