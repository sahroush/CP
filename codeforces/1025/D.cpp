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

const ll maxn  = 710;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int adj[maxn][maxn];
int ok[maxn][maxn][2];

int solve(int l , int r , int par){
    if(ok[l][r][par > r])
        return(ok[l][r][par > r]);
    if(l>r)
        return(ok[l][r][par > r] = 1);
    if(l == r)
        if(adj[par][l])
            return (ok[l][r][par > r] = 1);
        else
            return (ok[l][r][par > r] = -1);
    for(int i = l ; i <= r ; i ++)
        if(adj[par][i] and solve(l , i - 1 , i)==1 and solve(i+1 , r , i)==1)
            return (ok[l][r][par > r] = 1);
    return(ok[l][r][par > r] = -1);
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        for(int j = i ; j >= 0 ; j --)
            if(__gcd(a[i] , a[j]) > 1)
                adj[i][j] = adj[j][i] = 1;
    }
    cout << ((solve(1 , n , 0) == 1) ? "Yes" : "No");
    return(0);
}