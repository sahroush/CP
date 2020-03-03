#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =9e5+100;
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
vector < int > ans;

bool solve(int x){
    if(x == 0){
        bool f = 0;
        for (int i = 0 ; i < s.size(); i ++){
            if(s[i] == '('){
                f =1;
            }
            else if (f){
                return(0);
            }
        }
        return(1);
    }
    ans.clear();
    int boz = -1;
    for (int i = 0 ; i < s.size() ; i ++){
        if(s[i] == '(' and ans.size() < x){
            ans.pb(i);
        }
        if(ans.size() == x){
            boz = i;
            break;
        }
    }
    if(boz == -1){
        return(0);
    }
    for (int i = s.size() - 1 ; i >= boz ; i --){
        if(s[i] == ')'){
            ans.pb(i);
        }
        if(ans.size() == x*2){
            boz = i;
            break;
        }
    }
    return((ans.size() == 2*x));
}

int main(){
    migmig
    cin >> s;
    int cnt = 0;
    for(int i = 0 ; i < s.size() ; i ++){
        if(s[i] == '('){
            cnt++;
        }
    }
    if(cnt == 0 or cnt == s.size()){
        dokme(0);
    }
    if(solve(0)){
        dokme(0);
    }
    for (int i = cnt ; i > 0 ; i --){
        if(solve(i)){
            cout <<  1 << endl;
            cout << 2*i<< endl;
            sort(ans.begin() , ans.end());
            for (auto i : ans){
                cout << i+1 << ' ';
            }
            break;
        }
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
