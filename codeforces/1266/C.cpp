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

int r , c;
ll a[600][600];

int main(){
    migmig
    cin >> r >> c;
    if(r == 1 and c == 1){
        dokme(0);
    }
    for (int i = 0 ; i < 550 ; i ++){
        for (int j = 0 ; j < 550 ; j ++){
            a[i][j]  = 1;
        }
    }
    bool f = 0 ;
    if(r > c){
        swap(r , c);
        f=  1;
    }
    for (int i = 1 ; i <= r ; i ++ ){
        a[i][0] = i;
        for (int j = 1 ; j <= c ; j ++){
            a[i][j]*=a[i][j - 1];
        }
    }
    for (int i = 1 ; i <=c ; i ++ ){
        a[0][i] = i+r;
        for (int j = 1; j <= r ; j ++){
            a[j][i]*=i+r;
        }
    }
    if(f){
        for (int i = 1; i <= c ; i ++){
            for (int j =1 ; j <= r ; j ++){
                cout << a[j][i] << ' ';
            }
            cout << endl;
        }
        return(0);
    }

    for (int i = 1; i <= r ; i ++){
        for (int j =1 ; j <= c ; j ++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
