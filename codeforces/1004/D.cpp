#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int t;
int a[maxn];
int cnt[maxn];
int mat[maxn];

bool chk(int n , int m , int x , int y){
    ms(mat , 0);
    for (int i = 1 ; i <= n ;i ++){
        for (int j = 1 ; j <= m ; j ++){
            mat[abs(x - i) + abs(y - j)]++;
        }
    }
    for (int i = 0 ; i <= 1000000 ; i ++){
        if(mat[i]!=cnt[i]){
            return(0);
        }
    }
    return(1);
}

int main(){
    migmig
    ms(cnt , 0);
    cin >> t;
    for (int i =0  ; i < t ; i ++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a , a + t);
    int mx = a[t - 1];
    int mn = -1;
    for (int i = 1 ; i <= t; i ++){
        if(cnt[i]< 4 * i ){
            mn = i;
            break;
        }
    }
    if(mn == -1){
        dokme(-1)
    }
    //dokme(mx)
    for (int i = 1 ; i*i<=t ; i ++){
        if(t%i == 0){
            int boz = t / i;
            int ans = i -mn + boz - mx ;
            if(chk(i , boz , mn , ans)){
                cout << i << ' ' << boz << endl;
                cout << mn << ' ' << ans;
                return(0);
            }
            if(chk(boz , i, mn , ans)){
                cout << boz << ' ' << i << endl;
                cout << mn << ' ' << ans;
                return(0);
            }
        }
    }
    cout << -1;

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
