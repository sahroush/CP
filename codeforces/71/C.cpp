#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e6;
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
bool f[maxn];
vector <int> vec;

bool chk(int v){
    int tool  = n / v;
    for (int i = 1; i <= tool ; i ++ ){
        bool fl = 1;
        for (int j = i ; j<=n ; j+=tool){
            if(!f[j]){
                fl = 0 ;
                break;
            }
        }
        if(fl){
            return(1);
        }
    }
    return(0);
}

int main(){
    migmig
    cin >> n;
    for (int i  = 1 ; i <= n ; i ++){
        cin >> f[i];
    }
    int p = 3;
    vec.pb(-1);
    int boz = n;
    while(n>2){
        while(n%p == 0){
            n/=p;
            if(vec.back() != p){
                vec.pb(p);
            }
        }
        p++;
    }
    n = boz;
    while(vec.back()!= -1){
        int v= vec.back();
        vec.pop_back();
        if(chk(v)){
            dokme("YES");
        }
    }
    cout << "NO";
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
