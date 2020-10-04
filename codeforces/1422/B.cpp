/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;
#define int ll
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
ll a[200][200];
int n , m;

bool mark[200][200];

int32_t main(){
    migmig
    cin >> q;
    while (q -- ){
        cin >> n >> m;
        ms(mark , 0);
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                cin >> a[i][j];
        ll ans = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(mark[i][j])continue;
                ll sum = 0;
                ll cnt = 1;
                sum += a[i][j];
                mark[i][j] = 1;
                set < pii > st;
                st.clear();
                st.insert({i , j});
                if(!mark[i][m-1-j]){
                    sum += a[i][m-1 - j];
                    mark[i][m - 1 - j] = 1;
                    cnt ++;
                    st.insert({i , m - 1 - j});
                }
                if(!mark[n- 1 - i][m-1-j]){
                    sum += a[n - 1 - i][m-1 - j];
                    mark[n - 1 - i][m - 1 - j] = 1;
                    cnt ++;
                    st.insert({n - 1 - i , m - 1 - j});
                }
                if(!mark[n- 1 - i][j]){
                    sum += a[n - 1 - i][j];
                    mark[n - 1 - i][j] = 1;
                    cnt ++;
                    st.insert({n - 1 - i , j});
                }
                ll mid = (ld(sum)/ld(cnt) + 0.5);
                ll mn = 1e18;
                for(auto [kir , khar] : st){
                    mid = a[kir][khar];
                    ll s = 0;
                    for(auto [x , y] : st)
                        s += abs(a[x][y] - mid);
                    mn = min(mn , s);
                }
                ans += mn;
            } 
        }
        cout << ans << endl;
    }




    return(0);
}