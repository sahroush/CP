#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =2e5;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);
const int mods[] = {998244353, 1000000007, 696969569, 1000000009, 998244853};
const int rmod = mods[rng()%5];
const int rmod2 = mods[rng()%5];

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = rmod) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

set < ll > st , st2;
string s;
ll n ,q;
ll wtf= 27 , wtf2 = 31;

void hashh(){
    ll ans = 0;
    for (auto i : s){
        ans = (ans *wtf)%rmod + (i- 'a' + 1);
        ans %= rmod;
    }
    st.insert(ans);
    ll ans2 = 0;
    for (auto i : s){
        ans2 = (ans2 *wtf2)%rmod2 + (i- 'a' + 1);
        ans2 %= rmod2;
    }
    st2.insert(ans2);
    return;
}

void solve(){
    ll ans = 0;
    for (auto i : s){
        ans = (ans *wtf)%rmod + (i- 'a' + 1);
        ans %= rmod;
    }
    ll ans2 = 0;
    for (auto i : s){
        ans2 = (ans2 *wtf2)%rmod2 + (i- 'a' + 1);
        ans2 %= rmod2;
    }
    int n = s.size();
    const ll boz = ans;
    const ll boz2 = ans2;
    for(int i = 0 ; i < n ; i ++ ){
        if(s[i] == 'a' or s[i] == 'b'){
            ans = (ans + pw(wtf , n - i - 1))%rmod;
            ans2 = (ans2 + pw(wtf2 , n - i - 1, rmod2) )%rmod2;
            if(st.count(ans) and st2.count(ans2)){
                cout << "YES" << endl;
                return;
            }
        }
        if(s[i] == 'a'){
            ans = (ans + pw(wtf , n - i - 1))%rmod;
            ans2 = (ans2 + pw(wtf2 , n - i - 1 , rmod2))%rmod2;
            if(st.count(ans) and st2.count(ans2)){
                cout << "YES" << endl;
                return;
            }
        }
        ans = boz;
        ans2 = boz2;
        if(s[i] == 'b' or s[i] == 'c'){
            ans = (ans - pw(wtf , (n - i - 1)) + rmod*(ll)100)%rmod;
            ans2 = (ans2 - pw(wtf2 , (n - i - 1) , rmod2) + rmod2*(ll)100)%rmod2;
            if(st.count(ans) and st2.count(ans2)){
                cout << "YES" << endl;
                return;
            }
        }
        if(s[i] == 'c'){
            ans = (ans - pw(wtf , n - i - 1) + rmod*(ll)100)%rmod;
            ans2 = (ans2 - pw(wtf2 , (n - i - 1) , rmod2) + rmod2*(ll)100)%rmod2;
            if(st.count(ans) and st2.count(ans2)){
                cout << "YES" << endl;
                return;
            }
        }
        ans = boz;
        ans2 = boz2;
    }
    cout << "NO" << endl;
    return;
}

int main(){
    migmig
    cin >> n >> q;;
    while(n -- ){
        cin >> s;
        hashh();
    }
    while(q -- ){
        cin >> s;
        solve();
    }

    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
