#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
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

int q;

int main(){
    migmig
    cin >> q;
    while(q -- ){
        ll n=0 , k=0;
        cin >> n >> k;
        if(n == 2 and k == 3){
            cout << "NO" << endl;
            continue; 
        }
        ll sum = 0;
        for (ll i = 0 , j = 1 ; i < n ; i ++ , j*=4){
            sum+=j;
            if(sum >= k ){
                break;
            }
        }
        if(sum < k){
            cout << "NO" << endl;
            continue;
        }
        k--;
        cout << "YES" << ' ';
        ll i = 1;
        ll cnt = 1;
        while(k >= 4*cnt - 1 and i < n){
            k-=4*cnt - 1;
            cnt*=2;
            i++;
        }
        cout << n - i << endl;
        i = cnt = 1;
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
