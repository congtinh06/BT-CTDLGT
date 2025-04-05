#include <iostream>
using namespace std;
void Chan_Le(int *a, int n, int *b, int &m, int *c, int &p) {
    int *pa = a, *pb = b, *pc = c;
    m = p = 0;

    for (int i = 0; i < n; i++) {
        if (*(pa + i) % 2 == 0) { 
            *(pb + m) = *(pa + i);
            m++;
        } else {
            *(pc + p) = *(pa + i);
            p++;
        }
    }
}
int main() {
    int n, m, p;
    int a[100], b[100], c[100];
    cout << "+ Day so a\n";
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i);
    }
    Chan_Le(a, n, b, m, c, p);
    cout << "+ Day so b chua so chan\n";
    cout << "Day so co " << m << " phan tu: ";
    for (int i = 0; i < m; i++) {
        cout << *(b + i) << " ";
    }
    cout << endl;
    cout << "+ Day so c\n";
    cout << "Day so co " << p << " phan tu: ";
    for (int i = 0; i < p; i++) {
        cout << *(c + i) << " ";
    }
    cout << endl;

    return 0;
}

