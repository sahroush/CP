#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll INF = 1e15;
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

string s;
int ans = 0;
int a[maxn];
int n;

int solve (int x){
    int mx = 0;
    int start = -1;
    for (int i = 0 ; i < n; i++){
        if(a[i] == x){
            start = i;
            break;
        }
    }
    if(start == -1){
        return(0);
    }
    for (int i = start ; i < n ; i ++){
        if(a[i] == x and (i - start)%2==1){
            mx++;
            start = i;
        }
    }
    return(mx+1);
}

int main(){
    migmig
    cin >> s;
    n = s.size();
    for (int i = 0 ; i < s.size() ; i ++){
        a[i] = s[i] - 'A';
    }
    for (int i = 0 ; i < 27 ; i ++){
        ans = max(ans , solve(i));
        reverse(a , a + n);
        ans = max(ans , solve(i));
    }
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
