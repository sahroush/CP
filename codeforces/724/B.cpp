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
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m ;
int a[60][60];
void swp(int i  , int j){
    for(int k =0 ; k < 50 ; k ++)
        swap(a[k][j] , a[k][i]);
}

void check(){
    for(int i = 0 ; i < n ; i ++){
        int mx = 0;
        int cnt = 0;
        for(int j = 0 ; j < m ; j ++){
            if(a[i][j] != j + 1) cnt++;
        }
        if(cnt > 2)
            return;
    }
    dokme("YES");
}

int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            cin >> a[i][j];
    check();
    for(int i = 0 ; i < m ; i ++){
        for(int j = i +1 ; j < m ; j ++){
            //dokme(i)
            swp(i , j);
            //dokme(i)
            check();
            swp(i , j);
        }
    }
    dokme("NO");
    return(0);
}