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

int n;
string s;
int cnt[4];
int need;

int main(){
    migmig
    cin >> n;
    if(n%4!=0){
        dokme("===");
    }
    cnt[0] = cnt[1] = cnt[2] = cnt[3] = n/4;
    cin >> s;
    for (int i = 0 ; i < n ; i ++){
        if(s[i] == 'A'){
            cnt[0]--;
        }
        if(s[i] == 'T'){
            cnt[1]--;
        }
        if(s[i] == 'C'){
            cnt[2]--;
        }
        if(s[i] == 'G'){
            cnt[3]--;
        }
    }
    for (int i = 0 ; i < 4 ; i ++){
        if(cnt[i]<0){
            dokme("===")
        }
    }
    for (int i = 0 ; i < n ; i ++){
        if(s[i] == '?'){
            for (int j = 0 ; j < 4 ; j ++){
                if(cnt[j]){
                    cnt[j]--;
                    if(j == 0){
                        s[i] ='A';
                        break;
                    }
                    if(j == 1){
                        s[i] ='T';
                        break;
                    }
                    if(j == 2){
                        s[i] ='C';
                        break;
                    }
                    if(j == 3){
                        s[i] ='G';
                        break;
                    }
                }
            }
        }
        if(s[i]=='?'){
            dokme("===")
        }
    }
    if(cnt[1]+cnt[0]+cnt[1]+cnt[2]!=0){
        dokme("===")
    }
    cout << s;


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
