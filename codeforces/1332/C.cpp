#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int q;
int n , k;
string s;
int cnt[maxn][26];

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> k;
        cin >> s;
        for(int i = 0 ; i <= k ; i ++){
            for(int j = 0 ; j < 26 ; j ++){
                cnt[i][j] = 0;
            }
        }
        for(int i = 0 ; i < n ; i ++){
            cnt[i%k][s[i]-'a']++;
        }
        int ans = 0;
        for(int i = 0 ; i < k/2 ; i ++){
            int mn = 1e9;
            for(int j = 0 ; j < 26 ; j ++){
                mn = min(mn , (n/k)*2 - (cnt[i][j]+cnt[k-1-i][j]));
            }
            ans+=mn;
        }
        if(k%2){
            int mx = 0;
            for(int j = 0 ; j < 26 ; j ++){
                if(cnt[k/2][j] > cnt[k/2][mx]){
                    mx = j;
                }
            }
            ans+=(n/k) - cnt[k/2][mx];
        }
        cout << ans << endl;
    }





    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
