#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =210000;
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

ll n , m ;
ll a[maxn];
queue <ll> q;
ll zarib[maxn];

int main (){
    migmig
    cin >> n >> m;
    for (ll i = 0 ; i < n; i ++){
        cin >> a[i];
    }
    sort(a , a+n);
    //reverse(a , a + n);
    memset(zarib , 0 , sizeof(zarib));
    ll sum = 0 ;
    ll day = 1;
    ll cnt = 0;
    ll pos = 0;
    ll wtf = 0;
    ll sz = 0 ;
    for (ll i = 0 ; i < n ; i ++){
        sum += a[i];
        cnt++;
        if (cnt == m){
            cnt --;
            pos = i - (m - 1);
            sum += zarib[i%m];
            zarib[pos%m]+=a[pos];
        }

        cout<< sum << ' ';
    }



    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
