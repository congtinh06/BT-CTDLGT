#include <iostream>  
using namespace std;  
int main() {  
    string s;  
    int k;  
    cout << "Moi ban nhap chuoi s: ";  
    cin >> s;  
    cout << "Moi ban nhap vi tri can xoa: ";  
    cin >> k;  
    if (k >= 0 && k < s.length()) {  
        s.erase(k, 1);  
    } else {  
        cout << "Vi tri khong hop le!" << endl; 
    }  
		cout << "Chuoi sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;  
    return 0;  
}
