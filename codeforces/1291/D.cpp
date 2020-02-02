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

int q;
string s;
int l[maxn] , r[maxn];
bool ans[maxn];
int prt[30][maxn];

int main(){
    migmig
    cin >> s;
    cin >> q;
    ms(prt , 0);
    for (int i = 1 ; i <= s.size() ; i ++){
        prt[s[i - 1] - 'a'][i] = 1;
        for (int j = 0 ; j < 30 ; j ++){
            prt[j][i] += prt[j][i - 1];
        }
    }
    for (int i = 0; i < q; i ++){
        cin >> l[i] >> r[i];
        if(l[i] == r[i]){
            ans[i] = 1;
        }
        if(s[l[i]-1] != s[r[i]-1]){
            ans[i] = 1;
        }
        int cnt = 0;
        for (int j = 0 ; j < 30 ; j ++){
            if(prt[j][r[i]] - prt[j][l[i]] > 0){
                cnt++;
            }
        }
        ans[i]|=(cnt>=3);
        cout << ((ans[i])? "YES" : "NO") << endl;
    }




    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
