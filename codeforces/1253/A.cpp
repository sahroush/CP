#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn =1e6+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , q , a[maxn] , b[maxn];
int solve(){
    int l = -1, r;
    for(int i = 0 ; i < n ; i ++){
        if (a[i]!=b[i]){
            l = i;
            break;
        }
    }
    if (l == -1){
        dokme("YES");
    }
    for (int i = n-1 ; i >= 0 ; i --){
        if(a[i]!=b[i]){
            r = i;
            break;
        }
    }
    int dif = a[l] - b[l];
    if (dif > 0){
        dokme("NO");
    }
    for (int i = l ; i <= r ; i ++){
        if (a[i] - b[i]!=dif){
            dokme("NO");
        }
    }
    dokme("YES");
}

int main (){
    migmig
    cin >> q;
    while(q--){
        cin >> n;
        for (int i = 0 ;  i <  n ; i ++){
                cin >> a[i];
        }
        for (int i =0; i < n ; i ++){
            cin >> b[i];
        }
        solve();
        cout << endl;
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
