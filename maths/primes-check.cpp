#include <iostream>
using namespace std;

int main() {
    int x, flag = 0;
    cin >> x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            flag = 1;
            cout << "divisible by i: " << i << " so x: " << x <<" is not prime";
            break;
        }
    }
    if (flag == 0)
        cout << "number is prime";
}
