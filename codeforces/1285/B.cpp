#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e18;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define all(x) x.begin() , x.end()
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int q;
int n;
ll a[maxn];
ll dp[maxn];

ll max(ll a, ll b, ll c) { return max(max(a, b), c); }


ll maxCrossingSum(ll arr[], ll l, ll m, ll h)
{

    ll sum = 0;
    ll left_sum = INT_MIN;
    for (ll i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }

    sum = 0;
    ll right_sum = INT_MIN;
    for (ll i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }

    return left_sum + right_sum;
}
ll maxSubArraySum(ll arr[], ll l, ll h) {
   if (l == h)
     return arr[l];

   ll m = (l + h)/2;

   return max(maxSubArraySum(arr, l, m),
              maxSubArraySum(arr, m+1, h),
              maxCrossingSum(arr, l, m, h));
}

int main(){
    migmig
    cin >> q;
    while(q--){
        cin >> n;
        ll sum = 0;
        for (int i = 0 ; i < n ; i ++){
            cin >> a[i];
            sum+=a[i];
        }
        ll mx = maxSubArraySum(a, 1, n-1);
        mx = max(mx , maxSubArraySum(a, 0, n-2));
        if(mx >= sum){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }

    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
