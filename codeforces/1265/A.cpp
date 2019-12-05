#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =10e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int   q;


int main(){
    migmig
    cin >> q;
    while(q -- ){
        string s;
        bool f = 0;
        cin >> s;
        int n = s.size();
        if(s[0] == '?'){
            if(s[1]!='a'){
                s[0] = 'a';
            }
            else{
                s[0] = 'b';
            }
        }
        if(s[n - 1] == '?'){
            if(s[n - 2]!='a'){
                s[n - 1] = 'a';
            }
            else{
                s[n - 1] = 'b';
            }
        }
        for (int i = 1 ; i < n-1 ; i ++){
            if(s[i] != '?'){
                if(s[i] == s[i-1]){
                    cout << -1 << endl;
                    f = 1;
                    break;
                }
            }
            else{
                if(s[i-1] == 'a' and s[i + 1] == 'b'){
                    s[i] = 'c';
                }
                else if(s[i-1] == 'a' and s[i + 1] == 'a' ){
                    s[i] = 'b';
                }
                else if(s[i-1] == 'a' and s[i + 1] == 'c' ){
                    s[i] = 'b';
                }
                else if(s[i-1] == 'a' and s[i + 1] == '?' ){
                    s[i] = 'b';
                }
                else if(s[i-1] == 'b' and s[i + 1] == 'a' ){
                    s[i] = 'c';
                }
                else if(s[i-1] == 'b' and s[i + 1] == 'c' ){
                    s[i] = 'a';
                }
                else if(s[i-1] == 'b' and s[i + 1] == 'b' ){
                    s[i] = 'a';
                }
                else if(s[i-1] == 'b' and s[i + 1] == '?' ){
                    s[i] = 'a';
                }
                else if(s[i-1] == 'c' and s[i + 1] == 'a' ){
                    s[i] = 'b';
                }
                else if(s[i-1] == 'c' and s[i + 1] == 'b' ){
                    s[i] = 'a';
                }
                else if(s[i-1] == 'c' and s[i + 1] == 'c' ){
                    s[i] = 'b';
                }
                else if(s[i-1] == 'c' and s[i + 1] == '?' ){
                    s[i] = 'b';
                }
            }
        }
        if(s[n - 1] == s[n - 2] and !f){
            cout << -1 << endl;
            f = 1;
        }
        if(!f){
            cout << s << endl;
        }

    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
