#include<iostream>
using namespace std; 
int main(){
    int i=1,n,chips;
    cin >> n >> chips;
    while (true){
        if (chips<i){
            break;
        }
        chips=chips-i;
        i=i+1;
        if (i>n){
            i=1;
        }
        
    } 	
    cout << chips;
    return(0); 
}