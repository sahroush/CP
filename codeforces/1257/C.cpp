#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn =1e6+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int t , n , a[maxn];
map <int , int> last;

int main (){
    migmig
    cin >> t;
    while(t -- ){
        cin >> n;
        last.clear();
        int ans= 1e6;
        for (int i = 0 ; i< n; i ++){
            cin >> a[i];
            if(last.count(a[i]) == 0){
                last[a[i]] = i;
            }
            else{
                ans = min(ans , i - last[a[i]]);
                last[a[i]] = i;
            }
        }
        ans++;
        if (ans >= 1e6){
            ans = -1;
        }
        cout << ans << endl;
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
