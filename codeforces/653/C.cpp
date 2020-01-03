#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
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
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n;
int a[maxn];
vector < pii > ans;
vector <int> vec;

bool good(int pos) {
    if (pos < 0 || pos + 1 >= n) {
        return (1);
    }
    if (pos % 2 == 0) {
        if (a[pos] >= a[pos + 1]) {
            return (0);
        }
    } else {
        if (a[pos] <= a[pos + 1]) {
            return (0);
        }
    }
    return (1);
}

bool good() {
    for (int i = 0; i < vec.size(); i++) {
        int pos = vec[i];
        if (!good(pos)) {
            return(0);
        }
    }
    return (1);
}

int main(){
    migmig
    cin >> n;
    for (int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    for (int i = 0 ; i  < n - 1 ; i ++){
        if(!good(i)){
            vec.pb(i);
        }
    }
    if(vec.size() > 10){
        dokme(0);
    }
    for (int i = 0; i < vec.size(); i++) {
       for (int j = vec[i] - 1; j <= vec[i] + 1; j++) {
           if (j < 0 or j >= n) {
               continue;
           }
           for (int k = 0; k < n; k++) {
               swap(a[j], a[k]);
               if (good()) {
                   if (good(j - 1) and good(j) and good(j + 1) and good(k - 1) and good(k) and good(k + 1)) {
                       int x = min(k, j);
                       int y = max(k, j);
                       ans.push_back(make_pair(x, y));
                   }
               }
               swap(a[k], a[j]);
          }
       }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
