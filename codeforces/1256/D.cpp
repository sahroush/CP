#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e6+100;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

ll n , k , q ;
char s[maxn];
set <int> one , zero;

int main (){
    migmig
    cin >> q;
    while (q--){
        cin >> n >> k;
        cin >> s;
        ll num=0;
        for (ll i=0;i<n;i++)
        if (s[i]=='0'){
            if (i==num){num++;continue;}
            ll pos=max(num,i-k);
            k-=(i-pos);
            s[i]='1';
            s[pos]='0';
            if (k==0)break;
            num++;
        }
        cout<<s<<endl;
    }
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.