#include <bits/stdc++.h>

using namespace std;




#define pb(x) push_back(x);
#define endl '\n'



int q;
int n;

int main(){
   
    cin >> q;
    while(q -- ){
		cin >> n;
		vector< int > v;
		v.clear();
		for(int i = 0 ; i < 5 ; i ++){
			int a = n%10;
			if(a){
				v.pb(a * pow(10 , i));
				
			}
			n/=10;
		}
		cout << v.size() << endl;
		for(int i : v)cout << i << ' ';
		cout << endl;
	}
    
    
    
    return(0);
}