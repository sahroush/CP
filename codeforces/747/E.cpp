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

string s;
vector <int> child[maxn];
string comment[maxn];
int par[maxn];
vector < string > lvl[maxn];
vector < int > nums;
vector < string > strings;
int cnt =0 ;
int n;
int mx = 0;

string get(){
    string ans = "";
    while(cnt < n and s[cnt]!=','){
        ans+=s[cnt];
        cnt++;
    }
    ++cnt;
    return(ans);
}

void solve(int level){
    mx = max(mx , level);
    string a = get();
    lvl[level].pb(a);
    int q = stoi(get());
    while(q--){
        solve(level+1);
    }
}

int main(){
    migmig
    cin >> s;
    n = s.size();
    /*
    comment[0] = "pippinpaddleopsicopolis";
    par[0] = -1;
    int n = s.size();
    bool f = 0;
    string a = "";
    int cnt = 1;
    int q =0;
    int par = 0;
    for (int i = 0 ; i < n ; i ++){
        if(s[i] == ','){
            if(f){
                q = stoi(a);
                num.pb(q);
            }
            else{
                string.pb(a);
                comment[cnt++] = a;
                par[]
            }
            a = "";
            f = !f;
            continue;
        }
        a+=s[i];
    }
    */
    while(cnt < s.size()){
        solve(0);
    }
    cout << mx + 1 << endl;
    cnt = 0;
    while(lvl[cnt].size()){
        for (int i = 0 ; i < lvl[cnt].size() ; i ++){
            cout << lvl[cnt][i] << ' ';
        }
        cout << endl;
        cnt++;
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
