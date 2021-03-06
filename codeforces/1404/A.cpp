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

int q;
int n , k;
string s;

int32_t main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> k;
        cin >> s;
        bool ok = 1;
        for(int i = n-1 ; i  >= k ; i --){
            if(s[i] != '?')
                if(s[i - k] != s[i])
                    if(s[i-k]!='?')
                        ok = 0;
                    else
                        s[i-k] = s[i];
        }
        int cnt[2]= { 0 , 0};
        for(int i = 0 ; i < k ; i ++){
            if(s[i] == '1')
                cnt[1] ++;
            if(s[i] == '0')
                cnt[0] ++;
        }
        cnt[1] = k/2 - cnt[1];
        cnt[0] = k/2 - cnt[0];
        if(cnt[0] < 0 or cnt[1]<0)
            {
                cout << "NO" << endl;
                continue;
            }
        for(int i = 0  ; i < k ; i ++){
            if(s[i] == '?')
                if(cnt[0])
                    s[i] = '0' ,
                    cnt[0]--;
                else
                    s[i] = '1';
        }
        for(int i = n-1 ; i  >= k ; i --){
            if(s[i] != '?')
                if(s[i - k] != s[i])
                    if(s[i-k]!='?')
                        ok = 0;
                    else
                        s[i-k] = s[i];
        }
        if(ok)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }




    return(0);
}