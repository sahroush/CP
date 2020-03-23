#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =3e5+1000;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n , k;
int q;
vector < int > want[maxn];
bool mark[maxn] , done[maxn];

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n;
        int emp = 0;
        for (int i = 1 ; i <= n ; i ++){
            int sz;
            cin >> sz;
            for (int j = 0 ; j < sz ; j ++){
                int inp;
                cin >> inp;
                want[i].pb(inp);
            }
            for (int j:want[i]){
                if(!mark[j]){
                    mark[j] = 1;
                    done[i] = 1;
                    break;
                }
            }
            if(!done[i]){
                emp=i;
            }
        }
        int bak = 0;
        for (int i = 1 ; i <= n ; i ++){
            if(!mark[i]){
                bak = i;
            }
        }
        if(emp and bak){
            cout << "IMPROVE" << endl;
            cout << emp << ' ' << bak << endl;
        }
        else{
            cout << "OPTIMAL" << endl;
        }
        for (int i = 1 ; i <= n ; i ++){
            mark[i] = done[i] = 0;
            want[i].clear();
        }




    }



    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
