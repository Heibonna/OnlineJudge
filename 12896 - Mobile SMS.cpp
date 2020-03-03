#include <iostream>
using namespace std;

int main(){
    int itarations = 0;
    int n;
    string keys[10] = {" ", ".,?\"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    cin >> itarations;

    while(itarations--){
        cin >> n;
        int x[n], y[n];
        for(int i = 0; i<n; i++){
            cin >> x[i];
        }
        for(int i = 0; i<n; i++){
            cin >> y[i];
        }
        for(int i = 0; i<n; i++){
            cout << keys[x[i]][y[i]-1];
        }
        cout << endl;
    }
return 0;}