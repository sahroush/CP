#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,ll > pii;

const ll maxn =2e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e9+10;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define all(x) x.begin() , x.end()
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , k;
string s[2000];
map <string , int > mp;

int main(){
    migmig
    cin >> n >> k;
    for (int i =0  ; i < n ; i ++){
        cin >> s[i];
        mp[s[i]]++;
    }
    ll ans = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j =i + 1 ; j < n ; j ++){
            if(i == j ){
                continue;
            }
            string a = "";
            for (int l = 0 ; l < k ; l ++ ){
                if(s[i][l] == s[j][l]){
                    a+=s[i][l];
                }
                else{
                    if(s[i][l]!='S' and s[j][l]!='S'){
                        a+='S';
                    }
                    if(s[i][l]!='E' and s[j][l]!='E'){
                        a+='E';
                    }
                    if(s[i][l]!='T' and s[j][l]!='T'){
                        a+='T';
                    }
                }
            }
            ans+=mp[a];
        }
    }
    if(ans == 0){
        dokme(0)
    }
    dokme(ans/3)

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
