#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e3+1;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

string inp = "";
string s;

int main(){
    cin >> s;
    bool s1 = 0  , s2  = 0 , s3 = 0 , f = 0;
    int indx = 0;
    for (int i = 0 ; i < s.size() ; i ++){
        if (s[i] == ']' or s[i] == '[' or s[i] == ':' or s[i] == '|'){
            inp+=s[i];
            if (s[i] == '['){
                s1 = 1;
            }
            if (s1 and s[i] == ':' and !s2){
                s2 = 1;
            }
            else if (s2 and s[i] == ':'){
                s3 = 1;
            }
            if (s3 and s[i] == ']'){
                f = 1;
            }
        }
    }
    swap (s , inp);
    if (f == 0){
        dokme(-1);
    }
    int cnt = s.size();
    for (int  i = 0 ; i < cnt ; i ++){
        if (s[i] == ']'){
            indx = i;
        }
    }
    int dn = 0;
    for (int i = 0 ; i < cnt ; i ++ ){
        if (s[i] == ':' and i < indx){
            dn = i;
        }
    }
    s1 = 0  , s2  = 0 , s3 = 0 , f = 0;
    for (int i = 0 ; i < s.size() ; i ++){
        if (s[i] == '[' and s1 == 0){
            s1 = 1;
        }
        else if (s[i] == ':' and s1 and !s2){
            s2 = 1;
        }
        else if (i == dn){
            s3 = 1;////////
        }
        else if (s1 and s[i] == '|' and s2 and !s3){
            continue;
        }
        else{
            cnt --;
        }
    }
    cout << ++cnt;

    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
