#include<iostream>
using namespace std;

bool laNguyenAm(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    int n;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;
    char *a = new char[n]; 
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i); 
    }
    char *nguyenAm = new char[n]; 
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laNguyenAm(*(a + i))) {
            *(nguyenAm + count) = *(a + i);
            count++;
        }
}
    cout << "Cac nguyen am trong day: ";
    for (int i = 0; i < count; i++) {
        cout << *(nguyenAm + i) << " ";
    }
    cout << endl;
    delete[] a;     
    delete[] nguyenAm; 
    return 0;
}

