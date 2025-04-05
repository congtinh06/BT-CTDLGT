#include <iostream>  
#include <string>  
using namespace std;  
#define MAX 100  
struct MatHang {  
    string MSMH;    
    string TenMH;   
    int SoLuong;   
    float DonGia;    
};  

MatHang danhSach[MAX]; 
int n = 0;             

void nhapMatHang() {  
    if (n >= MAX) {  
        cout << "Danh sach da day!\n";  
        return;  
    }  
    MatHang mh;  
    cout << "Nhap ma so mat hang: "; cin >> mh.MSMH;  
    cout << "Nhap ten mat hang: "; cin.ignore(); getline(cin, mh.TenMH);  
    cout << "Nhap so luong: "; cin >> mh.SoLuong;  
    cout << "Nhap don gia: "; cin >> mh.DonGia;  

    danhSach[n++] = mh;  
    cout << "Nhap mat hang thanh cong!\n";  
}  
void timMatHang(const string& tenMH) {  
    for (int i = 0; i < n; i++) {  
        if (danhSach[i].TenMH == tenMH) {  
            cout << "Thong tin mat hang:\n"  
                 << "Ma so: " << danhSach[i].MSMH << "\n"  
                 << "Ten mat hang: " << danhSach[i].TenMH << "\n"  
                 << "So luong: " << danhSach[i].SoLuong << "\n"  
                 << "Don gia: " << danhSach[i].DonGia << " VND\n";  
            return;  
        }  
    }  
    cout << "Khong co mat hang dang tim!\n";  
}  
int tinhTongSoLuong() {  
    int tong = 0;  
    for (int i = 0; i < n; i++) {  
        tong += danhSach[i].SoLuong;  
    }  
    return tong;  
}  
void menu() {  
    int luaChon;  
    do {  
        cout << "\n===== QUAN LY CUA HANG =====\n";  
        cout << "1. Nhap mat hang\n";  
        cout << "2. Tim mat hang\n";  
        cout << "3. Tinh tong so luong mat hang\n";  
        cout << "4. Thoat\n";  
        cout << "Nhap lua chon: ";  
        cin >> luaChon;  

        switch (luaChon) {  
            case 1: nhapMatHang(); break;  
            case 2: {  
                string tenMH;  
                cout << "Nhap ten mat hang can tim: "; cin.ignore(); getline(cin, tenMH);  
                timMatHang(tenMH);  
                break;  
            }  
            case 3: {  
                int tong = tinhTongSoLuong();  
                cout << "Tong so luong mat hang: " << tong << "\n";  
                break;  
            }  
            case 4: cout << "Thoat chuong trinh.\n"; break;  
            default: cout << "Lua chon khong hop le!\n";  
        }  
    } while (luaChon != 4);  
}  
int main() {  
    cout << "CHUONG TRINH QUAN LY CUA HANG\n";  
    cout << "------------------------------\n";  
    menu();  
    cout << "Cam on ban da su dung chuong trinh!\n";  
    return 0;  
}
