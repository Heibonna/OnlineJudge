#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int size_buf = 100;
int licznik=0;

class Trie{
public:
    bool eow;
    Trie* parent;
    vector<Trie> child;
    unsigned multi = 1;
    char letter;
    unsigned int key;

public:
    Trie(){
        parent = NULL;
        letter = '#';
        key = 1;
        eow = false;
    }
    Trie(Trie* p, char l, unsigned int k, bool e){
        parent = p;
        letter = l;
        key = k;
        eow = e;
    }
    void update_key(){
        for(int i = this -> child.size() -1; i >= 0;i--){
            (this -> child[i]).key++;
            child[i].update_key();
        }
    }
    Trie &addchild(char letter, bool eow){
        if((this -> child).size() == 0){
            Trie t1(this, letter, this -> key, eow);
            if(this -> eow || this -> key == 0) t1.key += 1;

            (this -> child).push_back(t1);
            return (this -> child).back();
        }
        else if((this -> child).size() > 0){
            for(int i = 0; i < (this -> child).size(); i++){
                if((&(this -> child[i])) -> letter == letter){
                    if(eow){
                        if(this -> child[i].eow) this -> child[i].multi += 1;
                        else{
                            this -> child[i].eow = true;
                            if(this -> key !=0) this -> child[i].update_key();
                        }

                    }
                    return this -> child[i];
                }
            }

            Trie t2(this, letter,this -> key, eow);

            if(this -> key == 0) t2.key++;

            (this -> child).push_back(t2);

            if(this -> key != 0 && this->child.size() == 2 && !(this->eow)) (*this).update_key();
            else if(this -> key != 0) this->child.back().key +=1;

            return (this -> child).back();
        }
        else exit(1);
    }
    void input(string word){
        char letter;
        if(word.length() != 0){
            letter = *word.begin();
            word.erase(word.begin());
            if(word.length() == 0){
                addchild(letter,true);
            }
            else
                (addchild(letter,false)).input(word);
        }
    }
    void debug(){
        int s;
//        licznik++;
    //    if(this -> key != 0){
            cout << this -> key << "." << this -> letter << "." << this -> eow;
            cout << ' ';
    //    }

        if((s=this -> child.size()) != 0){
            if(s != 1) cout << endl;
//          int l = licznik;
            for(int i = s-1; i >= 0; i--){
//                cout << l << "." << i << '\t';
                (this -> child[i]).debug();
            }
        }
        else{
            cout << endl;
        }
    }
    int sum(int summ){
        int s;
        if((s=this -> child.size()) != 0){
            for(int i = s-1; i >= 0; i--){
                summ = child[i].sum(summ);
            }
        }
        if(this -> eow) summ += ((this -> key)*(this->multi));
        return summ;
    }
    int amount(int am){
        int s;
        if((s=this -> child.size()) != 0){
            for(int i = s-1; i >= 0; i--){
                    am = child[i].amount(am);
            }
        }
        if(this -> eow) am = am + this->multi;
        return am;
    }
    float avg(){
        int sum,ammount;

        sum = (*this).sum(0);
        ammount = (*this).amount(0);

        return 1.0 * sum/ammount;
   }
};

Trie root(NULL, '#', 0, false);

int main(){
    string word;
    Trie two, three, four, five;
    int n;

    while(cin >> n){
        for(n; n > 0; n--){
            cin >> word;
            root.input(word);
        }

    root.debug();
        printf("%.2f\n",root.avg());

        root.child.clear();
        }
return 0;
}
