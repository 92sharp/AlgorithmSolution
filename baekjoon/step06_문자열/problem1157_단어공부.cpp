#include <iostream>

using namespace std;

int main()
{
    char input[1000001] = { 0 };
    int a[26] = { 0 };
    cin.getline(input, 1000001);

    for (auto t : input) {
        if (t == '\n') break;
        if (t >= 'a' && t <= 'z') {
            a[t - 'a']++;
        }
        if (t >= 'A' && t <= 'Z') {
            a[t - 'A']++;
        }
    }

    int max = 0;
    int k = 0;
    bool second = false;
    for (int i = 0; i < 26;i++) {
        if (max < a[i]) {
            max = a[i];
            k = i;
            second = false;
        }
        else if (max == a[i] && a[i] != 0) {
            second = true;
        }
    }
    if (second) cout.put('?');
    else cout.put('A' + k);
}