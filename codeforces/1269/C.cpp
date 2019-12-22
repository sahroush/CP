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

int n , k;
string s;
string ans;

int main(){
    migmig
    cin >> n >> k;
    cin >> s;
    bool f = 0;
    ans = s;
    for (int i = k ;  i < n ; i ++){
        if(i % k == k - 1 and s[i]!=s[i-k]){
            f = 1;
        }
        s[i] = s[i - k];
    }
    if(s < ans){
        int pos = 0;
        for (int i = 0 ; i < k ; i ++){
            if(s[i]!='9'){
                pos = i;
            }
        }
        s[pos]+=1;
        for (int i = pos+1 ; i < k ; i ++){
            s[i] = '0';
        }
        for (int i = k ;  i < n ; i ++){
            s[i] = s[i - k];
        }
    }
    cout << n << endl << s;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
