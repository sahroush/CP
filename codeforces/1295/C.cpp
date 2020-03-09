#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e5+100;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int q;
string s , t;
bool cnt[26] , cnt2[26];
int nextt[maxn][26];

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> s >> t;
        ms(cnt , 0);
        for (int i = 0 ; i < t.size() ; i ++){
            cnt[t[i] - 'a'] = 1;
        }
        ms(cnt2 , 0);
        for (int i = 0 ; i < s.size() ; i ++){
            cnt2[s[i] - 'a'] = 1;
        }
        bool sik = 0;
        for (int  i = 0 ; i < 26 ; i ++){
            if(cnt[i] and !cnt2[i]){
                sik = 1;
                break;
            }
        }
        if(sik){
            cout << -1 << endl;
            continue;
        }
        ms(nextt , 63);
        for (int  i = s.size()  - 1 ; i >= 0 ; i --){
            for(int j = 0 ; j < 26 ; j ++){
                nextt[i][j] = nextt[i+1][j];
            }
            nextt[i][s[i] - 'a'] = i;
        }
        int p1=0 , p2 = 0;
        int ans = 1;
        while(p2!=t.size()){
            if(p1 == nextt[maxn - 10][1]){
                p1=0;
                ans++;
            }
            else if(nextt[p1][t[p2] - 'a'] == nextt[maxn - 10][1]){
                p1=0;
                ans++;
            }
            p1 = nextt[p1][t[p2] - 'a']+1;
            p2++;
        }
        cout << ans << endl;
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
