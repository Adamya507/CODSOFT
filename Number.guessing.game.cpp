#include<bits/stdc++.h>
using namespace std;
//NUMBER GUESSING GAME//

int main() {
    int num = 13;
    int n, i = 0;
    cout<<"Let the game begin!"<<endl;
    cout << "Guess the number : " << endl;

    do {
        cin >> n;
        if (n == num) {
            cout << "correct :)";
            break;
        }
        else if (n > num) {
            cout << "guess lower";
        }
        else {
            cout << "guess higher";
        }
        cout << endl;
    } while (i >= 0);
    i++;
    return 0;
}
