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



int q;


int main(){
    migmig
    cin >> q;
    while(q -- ){
        string p;
        string s;
        cin >> p >> s;
        int cnt[27];
        ms(cnt , 0 );
        for(int i = 0;  i < p.size() ; i ++){
            cnt[p[i] - 'a'] ++;
        }
        if(s.size() < p.size()){
            cout << "NO" << endl ;
            continue;
        }
        int cnt2[27];
        bool pos = 0;
        for (int i = 0;  i < s.size() - p.size() + 1; i ++){
            ms(cnt2 , 0 );
            for (int j = 0 ; j < p.size() ; j ++){
                cnt2[s[i + j] - 'a'] ++;
            }
            bool f = 1;
            for (int j = 0 ; j < 27 ; j ++){
                if(cnt[j]!=cnt2[j]){
                    f = 0;
                    break;
                }
            }
            if(f){
                pos = 1;
                break;
            }
        }

        if(pos){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
