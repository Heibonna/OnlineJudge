#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int zlicz(string x, char what){
int suma = 0;
    for(int i = 0; i < x.size(); i++){
        if(x[i] == what) suma++;
    }
return suma;
}


int main(){

int N,tmp, j, i = 0, maxX, maxY = 0, startY, tmpMaxY = 0,
UP=0, //max w gore
DOWN=0; //max w dol
char test;
string graph;

cin >> N;

for(int No = 1; No <= N; No++){
    UP = 0;
    DOWN = 0;
    tmpMaxY = 0;
    maxY = 0;
    cin >> graph;

    cout << "Case #" << No << ":" << endl;

maxX = graph.size() + 2;

//obliczanie wysokosci grafu//
    for(i = 0; i < graph.size(); i++){
        if(graph[i] == 'R') tmpMaxY++;
        else if(graph[i] == 'F'){
            if(tmpMaxY > UP) UP = tmpMaxY;
            tmpMaxY--;
        }
    }
    if(UP < tmpMaxY) UP = tmpMaxY;

    tmpMaxY = 0;
    for(i = 0; i < graph.size(); i++){
        if(graph[i] == 'F') tmpMaxY++;
        else if(graph[i] == 'R'){
            if(tmpMaxY > DOWN) DOWN = tmpMaxY;
            tmpMaxY--;
        }
    }
    if(DOWN < tmpMaxY) DOWN = tmpMaxY;

    if(DOWN > UP) maxY = DOWN +1;
    else maxY = UP +1;

/////

char Final[maxY+2][maxX+2];

//generowanie//
    for(i = 0; i <= maxY; i++){
        for(j = 0; j <= maxX; j++){
            if(j == 0 && i == maxY) Final[i][j] = '+';
            else if(j == 0) Final[i][j] = '|';
            else if(i == maxY && j > 0) Final[i][j] = '-';
            else{
                if(j > 1 && graph[j-2] == 'R') Final[i][j] = '/';
                else if(j > 1 && graph[j-2] == 'C') Final[i][j] = '_';
                else if(j > 1 && graph[j-2] == 'F') Final[i][j] = '\\';
                else Final[i][j] = ' ';

            }
        }
        Final[i][j] = '\n';
    }
/////startY

//startX = 3
startY = UP;

//oczyszczanie

    for(j = 1; j < maxX + 1; j++){
        for(i = 0; i < maxY; i++){
            tmp = 0;

            if(j == 2){
                if(i == startY) tmp++;
            }
            else if(i != 0){
                if(Final[i][j] == '\\'){
                    if(Final[i-1][j-1] == '\\') tmp++;
                    else if(Final[i-1][j-1] == '_') tmp++;
                    else if(Final[i][j-1] == '/') tmp++;
                }
                else if(Final[i][j] == '_'){
                    if(Final[i][j-1] == '\\') tmp++;
                    else if(Final[i][j-1] == '_') tmp++;
                    else if(Final[i+1][j-1] == '/') tmp++;
                }
                else{
                    if(Final[i][j-1] == '\\') tmp++;
                    else if(Final[i][j-1] == '_') tmp++;
                    else if(Final[i+1][j-1] == '/') tmp++;
                }
            }
            else{
                if(Final[i][j] == '\\'){
                    if(Final[i][j-1] == '/') tmp++;
                }
                else if(Final[i][j-1] == '_') tmp++;
                else if(Final[i+1][j-1] == '/') tmp++;
            }

            if(tmp == 0) Final[i][j] = ' ';
        }
    }
//


//wyswietlanie
    for(i = 0; i < maxY + 1; i++){
        for(j = 0; j < maxX + 2; j++){
                cout << Final[i][j];
            }
        }
/////

}

return 0;
}
