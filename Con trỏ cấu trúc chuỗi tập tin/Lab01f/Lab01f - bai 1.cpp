#include <iostream>  
#include <string>  
using namespace std;  
#define MAX 100  
struct dien_thoai {  
    string ma;  
    string nhan_hieu;  
    int gia;  
};  
dien_thoai danh_sach[MAX];  
int n = 0;                
int tim_vi_tri(string ma) {  
    for (int i = 0; i < n; i++) {  
        if (danh_sach[i].ma == ma) return i;  
    }  
    return -1;  
}  

void them_dien_thoai() {  
    if (n >= MAX) {  
        cout << "Danh sach da day!\n";  
        return;  
    }  

    dien_thoai dt;  
    cout << "Nhap ma dien thoai: ";   
    cin >> dt.ma;  

    if (tim_vi_tri(dt.ma) != -1) {  
        cout << "Ma dien thoai da ton tai!\n";  
        return;  
    }  
    cin.ignore();  

    cout << "Nhap nhan hieu: ";   
    getline(cin, dt.nhan_hieu);  
    cout << "Nhap gia: ";   
    cin >> dt.gia;  

    danh_sach[n++] = dt;  
    cout << "Them thanh cong!\n";  
}  

void cap_nhat_gia() {  
    string ma;  
    cout << "Nhap ma dien thoai can cap nhat gia: ";   
    cin >> ma;  

    int pos = tim_vi_tri(ma);  
    if (pos == -1) {  
        cout << "Khong tim thay dien thoai!\n";  
        return;  
    }  

    cout << "Nhap gia moi: ";   
    cin >> danh_sach[pos].gia; 
    cout << "Cap nhat thanh cong!\n";  
}  

void xoa_dien_thoai() {  
    string ma;  
    cout << "Nhap ma dien thoai can xoa: ";   
    cin >> ma;  

    int pos = tim_vi_tri(ma);  
    if (pos == -1) {  
        cout << "Khong tim thay dien thoai!\n";  
        return;  
    }  

    // Shift elements left  
    for (int i = pos; i < n - 1; i++) {  
        danh_sach[i] = danh_sach[i + 1];  
    }  
    n--;  
    cout << "Xoa thanh cong!\n";  
}  

void xuat_danh_sach() {  
    if (n == 0) {  
        cout << "Danh sach rong!\n";  
        return;  
    }  

    cout << "\nDANH SACH DIEN THOAI:\n";  
    for (int i = 0; i < n; i++) {  
        cout << "Ma: " << danh_sach[i].ma  
             << ", Nhan hieu: " << danh_sach[i].nhan_hieu  
             << ", Gia: " << danh_sach[i].gia << " VND\n";  
    }  
}  

void menu() {  
    int lua_chon; 
    do {  
        cout << "\n===== QUAN LY DIEN THOAI =====\n";  
        cout << "1. Them dien thoai\n";  
        cout << "2. Cap nhat gia\n";  
        cout << "3. Xoa dien thoai\n";  
        cout << "4. Xuat danh sach\n";  
        cout << "5. Thoat\n";  
        cout << "Nhap lua chon: ";  
        cin >> lua_chon;  

        switch (lua_chon) {  
            case 1: them_dien_thoai(); break;  
            case 2: cap_nhat_gia(); break;  
            case 3: xoa_dien_thoai(); break;  
            case 4: xuat_danh_sach(); break;  
            case 5: cout << "Thoat chuong trinh.\n"; break;  
            default: cout << "Lua chon khong hop le!\n";  
        }  
    } while (lua_chon != 5);  
}  

int main() {  
    cout << "CHUONG TRINH QUAN LY DIEN THOAI\n";  
    cout << "--------------------------------\n";  
    cout << "So luong toi da: " << MAX << " dien thoai\n";  
    
    menu();  

    cout << "Cam on ban da su dung chuong trinh!\n";  
    return 0;  
}
