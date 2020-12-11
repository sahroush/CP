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

int n , m , q;
string s[maxn];
bool ok[200][200];


int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> m;
        for(int i = 0 ; i < n ; i ++)
            cin >> s[i];
        ms(ok , 0);
        int ans = 0;
        for (int i = n - 1 ; i >= 0 ; i --){
            for(int j = m-1 ; j >= 0 ; j --){
                if(s[i][j] == 'C'){
                    ok[i][j] = 1;
                    continue;
                }
                if(s[i][j] == 'D'){
                    if(i == n-1)ans++;
                }
                if(s[i][j] == 'R'){
                    if(j == m-1)ans++;
                }
                ok[i][j] = 1;
            }
        }
        cout << ans << endl;;
    }
    return(0);
}