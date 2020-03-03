#include <iostream>
#include <map>

using namespace std;

int main()
{
    int cases;
    int n;
    int snowflake;
    int *snowflakes = new int[1000001];
    int current, first, result, counter;

    cin >> cases;
    while(cases--){
        first = current = result = counter = 0;
        map<int,bool> taken;

        cin >> n;

        while (n--) {
            cin >> snowflake;
            snowflakes[current++] = snowflake;

            if (taken.find(snowflake) != taken.end()) {
                if (counter > result) result = counter;

                while (true) {
                    if (snowflakes[first] == snowflake) break;
                    taken.erase(snowflakes[first]);
                    counter--;
                    first++;
                }

                first++;
            } else {
                counter++;
                taken[snowflake] = true;
            }
        }

        if (counter > result) result = counter;

        cout << result << endl;
    }

    delete snowflakes;

    return 0;
}