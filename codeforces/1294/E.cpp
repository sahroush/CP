#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m;
int ans= 0;

int main(){
    migmig
    cin >> n >> m;
    int a[n][m];
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){
            cin >> a[i][j];
        }
    }
    int cnt[n];
    for (int j = 0 ; j < m ; j ++){
        ms(cnt , 0);
        for (int i = 0 ; i < n ; i ++){
            if((a[i][j]-1)%m == j){
                int pos = (a[i][j] - 1)/m;
                if(pos < n){
                    cnt[(i - pos + n)%n]++;
                }
            }
        }
        int mn = 1e9;
        for (int i = 0 ; i < n ; i ++){
            mn = min(mn , n - cnt[i] + i);
        }
        ans += mn;
    }
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
