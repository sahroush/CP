//*
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

const ll maxn  = 1e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

map < int , int > cnt;
int a[maxn];
int n , q;
set < int > st;
vector < int > vec;
int ps[maxn][450];

int main(){
    migmig
    cin >> n >> q;
    for(int i = 1 ; i <= n;  i ++){
        cin >> a[i];
        cnt[a[i]] ++;
        if(cnt[a[i]] >= a[i])
            st.insert(a[i]);
    }
    for(auto i : st)
        vec.pb(i);
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 0 ; j < vec.size() ; j ++){
            ps[i][j] = ps[i-1][j];
            if(vec[j] == a[i])
                ps[i][j]++;
        }
    }
    while(q -- ){
        int ans = 0;
        int l , r;
        cin >> l >> r;
        l--;
        for(int i = 0 ; i < vec.size() ; i ++){
            if(ps[r][i] - ps[l][i] == vec[i])
                ans++;
        }
        cout << ans << endl;
    }
    return(0);
}