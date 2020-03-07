#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6+100;
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

struct trio{
    int x , y , z, id;
}t[maxn];
int n;
map < int , vector < trio > > mp;

void solve2(vector < trio > &vec){
    map < int , trio> mp;
    for (auto &i : vec){
        mp[i.z]=i;
    }
    trio cur;
    bool f = 0;
    for (auto &itr : mp){
        if(1){
            if(f){
                cout << cur.id << ' ' << itr.second.id << endl;
            }
            else{
                cur = itr.second;
            }
            f=!f;
        }
    }
    vec.clear();
    if(f){
        vec.pb(cur);
    }
}

void solve(vector < trio > &vec){
    map < int , vector < trio > > mp;
    for (auto &i : vec){
        mp[i.y].pb(i);
    }
    trio cur;
    bool f = 0;
    for (auto &itr : mp){
        solve2(itr.second);
        if(!itr.second.empty()){
            if(f){
                cout << cur.id << ' ' << itr.second[0].id << endl;
            }
            else{
                cur = itr.second[0];
            }
            f=!f;
        }
    }
    vec.clear();
    if(f){
        vec.pb(cur);
    }
}

int main(){
    migmig
    assert(dominance);
    cin >> n;
    for (int i = 0 ; i  < n ; i ++){
        cin >> t[i].x >> t[i].y >> t[i].z;
        t[i].id = i + 1;
    }
    for (int i  =0  ; i < n ; i ++){
        mp[t[i].x].pb(t[i]);
    }
    trio cur;
    bool f = 0;
    for (auto &itr : mp){
        solve(itr.second);
        if(!itr.second.empty()){
            if(f){
                cout << cur.id << ' ' << itr.second[0].id << endl;
            }
            else{
                cur = itr.second[0];
            }
            f=!f;
        }
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
