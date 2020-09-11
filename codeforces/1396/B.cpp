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

const ll maxn  = 200;
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
int q;
set < pii > st;

int solve(){
    pii cur = {-1 , -1};
    int t = 0;
    while(st.size()){
        pii lst = *st.rbegin();
        st.erase(lst);
        lst.first--;
        t = 1-t;
        if(cur.first > 0)
            st.insert(cur);
        cur = lst;
    }
    if(t)
        dokme("T")
    dokme("HL")
}

int32_t main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n;
        st.clear();
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i],st.insert({a[i] , i});
        solve();
        cout << endl;
    }
    return(0);
}