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
int n;
int d , l , r , u;
string s;

int main(){
    migmig
    cin >> q;
    while(q--){
        //cin >> n;
        cin >> s;
        n = s.size();
        u = 0 , r = 0 , l = 0  , d = 0;
        for (int i =0 ; i < n ; i ++){
            if(s[i] == 'U'){
                u ++ ;
            }
            if(s[i ] == 'D'){
                d++;
            }
            if(s[i] == 'L'){
                l++;
            }
            if(s[i] == 'R'){
                r++;
            }
        }
            r = min(l , r);
            l = min(l , r);
            u = min(u , d);
            d = min(u , d);
            if(u ==0){
                l = min(l , 1);
                r = l;
            }
            if(l == 0){
                u = min(1 , u);
                d = u;
            }
            cout << u + r + l + d << endl;
            for (int i =0 ; i < u ; i ++ ){
                cout << 'U';
            }
            for (int i =0 ; i < r ; i ++ ){
                cout << 'R';
            }
            for (int i =0 ; i < d; i ++ ){
                cout << 'D';
            }
            for (int i =0 ; i < l ; i ++ ){
                cout << 'L';
            }
            cout << endl;

    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
