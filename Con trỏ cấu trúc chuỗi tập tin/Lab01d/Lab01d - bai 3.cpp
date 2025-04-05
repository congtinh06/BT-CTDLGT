#include <iostream>
using namespace std;
int main() {
    string s;
    int k;
    char c;
    cout << "Moi ban nhap chuoi s: ";
    cin >> s;
    cout << "Moi ban nhap vi tri can chen: ";
    cin >> k;
    cout << "Moi ban nhap ky tu chen: ";
    cin >> c;
    if (k >= 0 && k <= s.length()) {
        s += ' '; 
        for (int i = s.length() - 1; i > k; i--) {
            s[i] = s[i - 1];
        }
        s[k] = c; 
    }
    cout << "Chuoi sau khi chen ky tu \"" << c << "\" vao vi tri " << k << ": " << s << endl;
    return 0;
}

