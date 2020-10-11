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

int q;
int n;
vector < int > vec[maxn];

int32_t main(){
    migmig
    cin >> q;
    vec[3].pb(3) , vec[5].pb(5) , vec[7].pb(7);
    for(int i = 0 ; i <= 1000 ; i ++){
        if(i - 3 >= 0 ){
            if(vec[i - 3].size()){
                vec[i] = vec[i - 3];
                vec[i].pb(3);
            }
        }
        if(i - 5 >= 0 ){
            if(vec[i -5].size()){
                vec[i] = vec[i - 5];
                vec[i].pb(5);
            }
        }
        if(i - 7 >= 0 ){
            if(vec[i - 7].size()){
                vec[i] = vec[i - 7];
                vec[i].pb(7);
            }
        }
    }
    while(q -- ){
        cin >> n;
        if(vec[n].size() == 0){
            cout << -1 << endl;
            continue;
        }
        int cnt[3] = {0 , 0 , 0 };
        for(int x : vec[n])
            if(x == 3)cnt[0]++;
            else if(x == 5)cnt[1] ++;
            else cnt[2] ++;
        cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
    }




    return(0);
}