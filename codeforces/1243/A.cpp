#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 1e3+100;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define endl '\n'
#define push_back pb
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , q ,a[maxn];

bool chk(int x){
    int cnt = 0;
    for (int i =0 ; i < n ; i++){
        if (a[i] >= x){
            cnt++;
        }
        else{
            break;
        }
    }
    return(cnt >= x );
}


int main (){
    migmig
    cin >> q;
    while (q -- ){
        cin >> n;
        for (int i = 0; i < n ; i ++){
            cin >> a[i];
        }
        sort(a , a + n);
        reverse(a , a + n);
        int l = 0 , r = 10000;
        while(r - l > 1){
            int mid = (l+ r) / 2;
            if (chk(mid)){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        cout << l << endl;
    }



    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
