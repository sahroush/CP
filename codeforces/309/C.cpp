#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e5;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);


#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define sa(x) x.begin() , x.end()
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m , ans = 0;
vector <int> sz;
vector <int> b;
int c[50];

bool ibit(int x , int i){
    return((x & (1 << i)));
}

void prc(int x){
    for (int i = 0 ; i < 32 ; i ++){
        if(ibit(x , i)){
            c[i]++;
        }
    }
}

int main(){
    migmig
    ms(c , 0);
    cin >> n >> m;
    for (int i =0;  i < n ; i ++){
        int inp;
        cin >> inp;
        sz.pb(inp);
        prc(inp);
    }
    int cnt = 0;
    for (int i =0;  i < m ; i ++){
        int inp;
        cin >> inp;
        b.pb(inp);
    }
    sort(sa(b));
    for (int i = 0;  i< m ; i ++){
        for (int j = b[i] ; j <= 30 ; j++){
            if(c[j]){
                ans++;
                c[j]--;
                for (int k = b[i] ; k < j ; k ++){
                    c[k] ++;
                }
                break;
            }
        }
    }
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
