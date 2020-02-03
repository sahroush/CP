#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =5e5+5;
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

int n , m  , a[maxn][8];
bool mark[maxn];

bool chk(int x){
    for (int i = 0 ; i < pow(2 , m) ; i ++){
        mark[i]=0;
    }
    for (int i = 0 ; i < n ; i ++){
        int num = 0 ;
        for (int j = 0 ; j < m ; j ++){
            num+=(a[i][j]>=x) * pw(2 , j);
        }
        mark[num] = 1;
    }
    for (int i = 0 ; i < pow(2 , m) ; i ++){
        for (int j = 0 ; j < pow(2 , m) ; j ++){
            if(mark[i] and mark[j] and (i|j) == pow(2 , m)-1){
                return(1);
            }
        }
    }
    return(0);
}

void solve(int x){
    for (int i = 0 ; i < pow(2 , m) ; i ++){
        mark[i]=0;
    }
    for (int i = 0 ; i < n ; i ++){
        int num = 0 ;
        for (int j = 0 ; j < m ; j ++){
            num+=(a[i][j]>=x) * pw(2 , j);
        }
        mark[num] = 1;
    }
    int aa , b;
    for (int i = 0 ; i < pow(2 , m) ; i ++){
        for (int j = 0 ; j < pow(2 , m) ; j ++){
            if(mark[i] and mark[j] and (i|j) == pow(2 , m)-1){
                aa = i , b = j;
                break;
            }
        }
    }
    int ans1 = -1 , ans2 = -1;
    for (int i = 0 ; i < n ; i ++){
        int num = 0 ;
        for (int j = 0 ; j < m ; j ++){
            num+=(a[i][j]>=x) * pw(2 , j);
        }
        if(num == aa){
            ans1 = i + 1;
        }
        if(num == b){
            ans2 = i + 1;
        }
    }
    cout << ans1 << ' ' << ans2;
}

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){
            cin >> a[i][j];
        }
    }
    int l = 0 , r = 1e9+1;
    while(r - l > 1){
        int mid = (l + r)/2;
        if(chk(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    solve(l);


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
