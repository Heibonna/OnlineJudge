#include <iostream>
#define MAX 101
using namespace std;

char map[MAX][MAX];
int n, m;

bool markDeposits(int x, int y){
	if(map[x][y]=='*'){
		return false;
	}
	map[x][y] = '*';
	if(x-1>=0){
		markDeposits(x-1,y);
	}
	if((x-1>=0)&&(y+1<=m-1)){
		markDeposits(x-1,y+1);
	}
	if(y+1<=m-1){
		markDeposits(x,y+1);
	}
	if((x+1<=n-1)&&(y+1<=m-1)){
		markDeposits(x+1,y+1);
	}
	if(x+1<=n-1){
		markDeposits(x+1,y);
	}
	if((x+1<=n-1)&&(y-1>=0)){
		markDeposits(x+1,y-1);
	}
	if(y-1>=0){
		markDeposits(x,y-1);
	}
	if((x-1>=0)&&(y-1>=0)){
		markDeposits(x-1,y-1);
	}
	return true;
}

int main(){

	while ((cin >> n >> m)&&(!((n==0)&&(m==0)))){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> map[i][j];
			}
		}
		int count = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(markDeposits(i,j)){
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}