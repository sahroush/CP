#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6+1000;
const ll mod =1e9+7;
const ll mod2 = 13013621;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int state = 0; // 0 : equal , 1 : first is bigger , 2 : second is bigger
ll cur[2];
int q;
ll n , a[maxn] , p;
ll hsh[2];

int main(){
    migmig
    cin >> q;
    while (q -- ){
        cin >> n >> p;
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        if(p == 1){
            cout << n%2 << endl;
            continue;
        }
        sort(a , a + n);
        reverse(a , a + n);
        ms(cur , 0);
        state = 0;
        ms(hsh,0);
        for(int i = 0 ; i < n ; i ++){
            if(state == 0){
                state = 1;
                cur[0] += pw(p , a[i]);
                cur[0]%=mod;
                hsh[0] += pw(p , a[i] , mod2);
                hsh[0]%=mod2;
            }
            else if(state == 1){
                cur[1] += pw(p , a[i]);
                cur[1]%=mod;
                hsh[1] += pw(p , a[i] , mod2);
                hsh[1]%=mod2;
                if(cur[0] == cur[1] and hsh[0] == hsh[1])
                    state = 0;
            }
        }
        ll ans = (cur[0] - cur[1] + mod)%mod;
        cout << ans << endl;
    }
    return(0);
}