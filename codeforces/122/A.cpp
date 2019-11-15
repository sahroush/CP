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

int n;
string s;

int main (){
    migmig
    cin >> n;
    vector <int> lucky;
    for (int i  = 1 ; i <= 1000 ; i ++){
        stringstream ss;
        ss << i;
        s = ss.str();
        bool f = 1;
        ss.clear();

        for (int j = 0 ; j < s.size() ; j ++){
            if (s[j]!='4' and s[j]!='7'){
                f = 0;
            }
        }
        if (f){
            lucky.pb(i);
        }
    }
    for (int i = 0 ; i < lucky.size() ; i ++){
        if(n%lucky[i] == 0){
            dokme("YES");
        }
    }
    dokme("NO");

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
