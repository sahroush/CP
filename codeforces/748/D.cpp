#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int k , n , a[maxn];
map <string , vector < int > > mp;
string s[maxn];
vector < string > all;
bool mark[maxn];
map < string , int > odd , even;

bool cmp(int i , int j){
    return(a[i] > a[j]);
}

int ans = 0;

int main(){
    migmig
    cin >> n  >> k;
    for (int i = 0 ; i < n ; i ++){
        cin >> s[i] >> a[i];
        mp[s[i]].pb(i);
        all.pb(s[i]);
    }
    sort(all.begin() , all.end());
    all.resize(unique(all.begin() , all.end()) - all.begin());
    int maxx = 0;
    for (auto  i : all){
        sort(mp[i].begin() , mp[i].end() , cmp);
    }
    for (auto i : all){
        string j = i;
        reverse(j.begin() , j.end());
        if(i == j){
            int sum = 0;
            for (int k = 0 ; k < mp[i].size() ; k ++){
                sum += a[mp[i][k]];
                if(k%2 == 0){
                    odd[i] = max(odd[i] , sum);
                }
                else{
                    even[i] = max(even[i] , sum);
                }
            }
            if(odd[i] > even[i]){
                maxx = max(maxx , odd[i] - even[i]);
            }
            continue;
        }
        int l = 0 , r = 0;
        while(l < mp[i].size() and r < mp[j].size()){
            if(a[mp[i][l]] + a[mp[j][r]] > 0 and !mark[mp[i][l]] && !mark[mp[j][r]]){
                ans+=a[mp[i][l]] + a[mp[j][r]];
                mark[mp[i][l]] = mark[mp[j][r]] = 1;
            }
            l++, r++;
        }
    }
    bool f = 0;
    for (auto i : all){
        string j = i;
        reverse(j.begin() , j.end());
        if(i == j){
            if(odd[i] > even[i]){
                if(!f and odd[i]-even[i] == maxx){
                    f = 1;
                    ans+=odd[i];
                }
                else{
                    ans+=even[i];
                }
            }
            else{
                ans+=even[i];
            }
        }
    }

    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
