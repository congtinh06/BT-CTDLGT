#include <iostream>
using namespace std;
void tang_dan(float *a, int n, float *b, int m, float *c, int &p) {
    float *pa = a, *pb = b, *pc = c;
    p = 0;

    while (pa < a + n && pb < b + m) {
        if (*pa < *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
        p++;
    }

    while (pa < a + n) { 
        *pc++ = *pa++;
        p++;
    }

    while (pb < b + m) { 
        *pc++ = *pb++;
        p++;
    }
}

int main() {
    int n, m, p;
    float a[100], b[100], c[200];
    cout << "Moi ban nhap so luong phan tu cua day a: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i);
    }
    cout << "Moi ban nhap so luong phan tu cua day b: ";
    cin >> m;
    for (int i = 0; i < m; i++) { 
        cout << "Phan tu " << i << ": ";
        cin >> *(b + i);
    }
    tang_dan(a, n, b, m, c, p);
    cout << "+ Day so c\n";
    cout << "Day so co " << p << " phan tu: ";
    for (int i = 0; i < p; i++) {
        cout << *(c + i) << " ";
    }
    cout << endl;

    return 0;
}

