#include <iostream>

using namespace std;

int res = 0;
int tab[50000], tab1[50000];


int findfromset(int x){
    if(tab[x] != x)
        tab[x] = findfromset(tab[x]);
    return tab[x];
}

void unioninset(int &x, int &y){
    int PX = findfromset(x);
    int PY = findfromset(y);
    if(PX == PY) return;
    res--;
    if(tab1[PX]>tab1[PY]) tab[PY] = PX;
    else{
        tab[PX] = PY;
        if(tab1[PX] == tab1[PY])
            tab1[PY]++;
    }
}

int main(){
    int n, m, x, y, c = 1;

    while(true){
        cin >> n >> m;
        if(n == 0) break;

        for(int i = 0; i < n; i++){
            tab[i] = i;
            tab1[i] = 0;
        }
        res = n;

        for(int i = 0; i< m; i++){
            cin >> x >> y;
            unioninset(x,y);
        }

        cout << "Case" << c << ": " << res << endl;
        c++;
    }

}