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
int n , k;
string s;
vector < pii > vec;
vector < pair < int , pii > > wtf;

int32_t main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> k;
        cin >> s;
        
        vec.clear();
        for(int i = 0 ; i < n ; i ++){
            if(i){
                if(s[i] == 'W' and s[i - 1] == 'L')
                    vec.pb({i , 0});
            }
            if(i+1 < n){
                if(s[i] == 'W' and s[i + 1] == 'L')
                    vec.pb({i , 1});
            }
        }
        
        for(int i = 1 ; i < vec.size() ; i ++){
            if(vec[i].second == 0 and vec[i - 1].second == 1){
                wtf.pb({vec[i].first - vec[i - 1].first , {vec[i-1].first + 1 , vec[i].first -1}});
            }
        }
        sort(wtf.begin() , wtf.end());
        for(auto [f , S] : wtf){
            auto [l , r] = S;
            //0cout << l << ' ' << r << endl;
            for(int i = l ; i <= r ; i ++){
                if(!k)break;
                s[i] = 'W' , k--;
            }
        }
        //dokme(s)
        if(k){
            for(int i = 1 ; i < n ; i ++){
                if(s[i - 1] == 'W' and k and s[i] == 'L') k-- , s[i] = 'W';
            }
            for(int i = n-2 ; i >= 0 ; i --){
                if(s[i + 1] == 'W' and k and s[i] == 'L') k-- , s[i] = 'W';
            }
            if(k)
                s[0] = 'W' , k--;
            for(int i = 1 ; i < n ; i ++){
                if(s[i - 1] == 'W' and k and s[i] == 'L') k-- , s[i] = 'W';
            }
        }
        int ans = 0;
        wtf.clear();
        //dokme(s)
        for(int i = 0 ; i < n ; i ++){
            if(s[i] == 'W'){
                ans ++ ;
                if(i)
                    if(s[i - 1] == 'W')
                        ans ++;
            }
        }
        cout << ans << endl;
    }




    return(0);
}