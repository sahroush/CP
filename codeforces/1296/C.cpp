#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
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

int q , n;
string s;
map <pii , int > mp;

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> s;
        mp.clear();
        pii ans = {-1 , -1};
        mp[{0 , 0}] = 1;
        pii pos = { 0 , 0};
        for (int i=  0 ; i < n ; i ++){
            if(s[i] == 'U'){
                pos.second++;
            }
            if(s[i] == 'D'){
                pos.second--;
            }
            if(s[i] == 'L'){
                pos.first--;
            }
            if(s[i] == 'R'){
                pos.first++;
            }
            if(mp.count(pos)){
                if(ans.first == -1){
                    ans.first = mp[pos];
                    ans.second = i + 1;
                }
                else{
                    if(i + 1 - mp[pos] < ans.second - ans.first){
                        ans.first = mp[pos];
                        ans.second = i + 1;
                    }
                }
            }
            mp[pos] = i + 2;
        }
        if(ans.first == -1){
            cout << -1 << endl;
        }
        else{
            cout << ans.first << ' ' << ans.second << endl;
        }
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
