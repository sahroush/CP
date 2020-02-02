#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6+5;
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

int q;
int a[maxn];
int n;
bool l[maxn] , r[maxn];
int lnum[maxn] , rnum[maxn];

int main(){
    migmig
    cin >> q;
    while(q--){
        cin >> n;
        for (int i = 1 ; i <= n ; i ++){
            cin >> a[i];
        }
        for (int i = 1 ; i <= n ; i ++){
            l[i] = r[i] = 0;
        }
        l[0] = 1;
        for (int i = 1 ; i <= n ; i ++){
            if(a[i] >= i - 1 and l[i - 1] ){
                l[i] = 1;
            }
            else{
                l[i] = 0;
            }
        }
        r[n + 1] = 1;
        for (int i = n ; i >= 1 ; i --){
            if(a[i] >= n - i and r[i + 1]){
                r[i] = 1;
            }
            else{
                r[i] = 0;
            }
        }
        bool boz = 0;
        for (int i = 1 ; i <= n ; i ++){
            if(l[i] and r[i]){
                cout << "YES" << endl;
                boz = 1;
                break;
            }
        }
        if(!boz){
            cout << "NO" << endl;
        }
    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
