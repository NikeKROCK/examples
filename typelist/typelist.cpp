#include <iostream>
using namespace std;
int main() {
    int a[3]{ 0,0,0 };
    int b[3]{ 0,0,0 };
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
            }
            if (b[j] < b[i]) {
                swap(b[i], b[j]);
            }
        }
    }
    int cnt=0;
    if (a[0] > b[0]) { cnt++; }
    if (a[1] > b[1]) { cnt++; }
    if (a[2] > b[2]) { cnt++; }
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
        cout << "Boxes are equal";
    }
    else if (cnt >= 2) {
        cout << "The first box is smaller than the second one";
    }
    else {
        cout << "The first box is larger than the second one";
    }
    for (int i = 0; i < 3; i++) {
        std::cout << a[i] << ' ' << b[i] << '\n';
    }
    return 0;
}