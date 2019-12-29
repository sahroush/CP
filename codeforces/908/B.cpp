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

int n , m;
string s[maxn];
int mand[maxn];

int main(){
    migmig
    cin >> n >> m;
    pii start , end;
    for (int i =0 ; i < n ; i ++){
        cin >> s[i];
        for (int j = 0 ; j < m ; j ++){
            if(s[i][j] == 'S'){
                start = pii(i + 1 , j +1);
            }
            if(s[i][j] == 'E'){
                end = pii(i + 1 , j + 1);
            }
        }
    }
    string com;
    cin >> com;
    for (int i = 0;  i < com.size() ; i ++){
        mand[i] = com[i]-'0';
    }
    int cnt = 0;
    for (int i = 0;i < 4 ; i ++){
        for (int j = 0 ; j < 4 ; j ++){
            if(j == i){
                continue;
            }
            for (int k = 0 ; k < 4 ; k ++){
                if(k == j or k == i){
                    continue;
                }
                for (int l = 0 ; l < 4 ; l ++){
                    if(l == k or l == j or l == i){
                        continue;
                    }
                    pii pos = start;
                    for (int p = 0 ; p < com.size() ; p++){
                        if(mand[p] == i){
                            pos.first ++;
                        }
                        if(mand[p] == j){
                            pos.first --;
                        }
                        if(mand[p] == k){
                            pos.second++;
                        }
                        if(mand[p] == l){
                            pos.second --;
                        }
                        if(pos == end){
                            cnt++;
                            break;
                        }
                        if(pos.first < 1 or pos.first>n or pos.second < 1 or pos.second > m or s[pos.first - 1][pos.second - 1] == '#'){
                            break;
                        }

                    }
                }
            }
        }
    }
    dokme(cnt);



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
