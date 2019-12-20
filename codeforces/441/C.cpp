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


int n , m , k;
pii pos;

int main(){
    migmig
    cin >> m >> n >> k;
    pos = pii(1 , 1);
    int cnt = 0;
    int lim = n*m / k;
    int f = n*m - lim*k;
    cout << f + lim << ' ';
    cout << 1 << ' ' << 1 << ' ';
    cnt++;
    int ph = 1;
    int ans = 1;
    while(ans!=n*m){
        ans++;
        if(f){
            f--;
            pos.first+=ph;
            if(pos.first > n){
                pos.first --;
                pos.second++;
                ph*=-1;
                if(pos.second > m){
                    return(0);
                }
            }
            if(pos.first == 0){
                pos.first ++;
                pos.second++;
                ph*=-1;
                if(pos.second > m){
                    return(0);
                }
            }

        }
        else{
            cnt++;
            pos.first+=ph;
            if(pos.first > n){
                pos.first = n;
                ph*=-1;
                pos.second++;
                if(pos.second > m){

                    return(0);
                }
            }
            if(pos.first == 0){
                pos.first ++;
                pos.second++;
                ph*=-1;
                if(pos.second > m){

                    return(0);
                }
            }
        }
        cout << pos.second << ' ' << pos.first << ' ';
        if(cnt == lim){
            cout << endl;
            cnt = 0;
            if(ans < n * m){
                cout << lim << ' ';
            }

        }
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.