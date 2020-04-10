#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
ll a[maxn] , b[maxn];
bool willkill[maxn];

int main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n;
        for(int i = 0 ; i < n ; i ++){
            cin >> a[i] >> b[i];
            willkill[i] = 0;
        }
        bool f = 1;
        for(int i = 0 ; i < n ; i ++){
            if(b[i]>=a[(i + 1)%n]){
                willkill[i] = 1;
            }
            if(willkill[i] == 0){
                f = 0;
            }
        }
        if(f){
            cout << *min_element(a , a + n) << endl;
            continue;
        }
        ll ans = 1e18;
        ll res = 0;
        for(int i = 0 ; i < n ; i ++){
            if(i == 0){
                res+=a[i];
                continue;
            }
            if(willkill[i - 1]){
                continue;
            }
            else{
                res+=a[i]- b[i - 1];
            }
        }
        ans = min(ans , res);
        int cur = n-1;
        for(int i = 1 ; i < n ; i ++){
            if(!willkill[i-1]){
                res+=b[i-1];
            }
            if(willkill[i - 1]){
                res+=a[i];
            }
            if(willkill[cur]){
                res-=a[i - 1];
            }
            else{
                res-=b[cur];
            }
            cur++;
            cur%=n;
            ans = min(ans , res);
        }
        cout << ans << endl;
    }



    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
