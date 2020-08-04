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

int n , q;
int nxt[maxn];
int dist[maxn];
int last[maxn];
int comp[maxn];
int a[maxn];

void solve(int i){
    if(i + a[i] == n+1)
        nxt[i] = 0 , last[i] = i , dist[i] = 1;
    else if(comp[i] == comp[i+a[i]])
        nxt[i] = nxt[i+a[i]] , last[i] = last[i+a[i]] , dist[i] = dist[i + a[i]] + 1;
    else
        nxt[i] = i + a[i] ,last[i] = last[i+a[i]], dist[i] = 1;
}

int main(){
    migmig
    cin >> n >> q;
    int sq = sqrt(n);
    for(int i = 1 ; i <= n; i ++){
        cin >> a[i];
        if(i+a[i] > n) a[i] = n+1 - i;
        comp[i] = i / sq;
    }
    for(int i = n ; i ; i --)
        solve(i);
    while(q -- ){
        int t; cin >> t;
        if(t){
            int cur;
            int sum = 0;
            int lst = 0;
            cin >> cur;
            while(cur!=0){
                sum += dist[cur];
                lst = last[cur];
                cur = nxt[cur];
            }
            cout << lst << ' ' << sum << endl;
        }
        else{
            int pos , x;
            cin >> pos >> x;
            if(x+pos > n) x = n+1 - pos;
            a[pos] = x;
            for(int i = pos ; i and comp[i] == comp[pos] ; i --)
                solve(i);
        }
    }
    return(0);
}
