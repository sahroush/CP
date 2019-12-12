#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =9e5+1000;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int q;

int main(){
    migmig
    cin >> q;
    while(q -- ){
        ll a , b , c;
        cin >> a >> b >> c;
        ll arr [] = {a , b , c};
        sort(arr , arr + 3);
        ll d [] = {0 , - 1 , 1};
        ll mn = abs(arr[0] - arr[1]) + abs (arr[1] - arr[2]) + abs(arr[2] - arr[0]);
        for (int i = 0 ; i < 3 ; i ++){
            for(int j =0 ;  j < 3; j ++){
                for(int k  =0 ; k < 3 ; k ++){
                    mn = min (mn , abs((arr[0] - d[i]) - (arr[1] - d[j])) + abs ((arr[1] - d[j]) - (arr[2] - d[k])) + abs((arr[2] - d[k]) - (arr[0] - d[i])));
                }
            }
        }
        cout << mn << endl;
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
