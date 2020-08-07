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

const ll maxn  = 3e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> obds;

int n;
map < int , int > mp;
set < int > st;
obds ist[maxn];
int a[maxn] , b[maxn] , c[maxn];

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i] >> b[i] >> c[i];
        st.insert(c[i]);
    }
    int cnt = 1e5+1;
    for(int i : st)
        mp[i] = cnt++;
    for(int i = 0 ; i < n;  i ++){
        if(a[i] == 1){
            ist[(mp[c[i]])].insert(b[i]);
        }
        else if (a[i] == 2){
            ist[(mp[c[i]] - 100000)].insert(b[i]);
        }
        else{
            cout << (int)ist[(mp[c[i]])].order_of_key(b[i]) - (int)ist[mp[c[i]] - 100000].order_of_key(b[i]) << endl;
        }
    }
    return(0);
}