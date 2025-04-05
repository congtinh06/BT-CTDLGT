#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
struct loai_hoa {
    char ten[50];     
    int so_luong;     
    char dvt[20];      
    double don_gia;    
};
struct danh_sach_loai_hoa {
    vector<loai_hoa> ds;
};
void nhap_danh_sach(danh_sach_loai_hoa &ds) {
    int n;
    cout << "Nhap so loai hoa: ";
    cin >> n;
    cin.ignore();  
    for (int i = 0; i < n; i++) {
        loai_hoa hoa;
        cout << "\nNhap ten loai hoa: ";
        cin.getline(hoa.ten, 50);
        cout << "Nhap so luong: ";
        cin >> hoa.so_luong;
        cin.ignore();
        cout << "Nhap don vi tinh: ";
        cin.getline(hoa.dvt, 20);
        cout << "Nhap don gia: ";
        cin >> hoa.don_gia;
        cin.ignore();
        ds.ds.push_back(hoa);
    }
}
void xuat_danh_sach(danh_sach_loai_hoa ds) {
    cout << "\nDanh sach loai hoa:\n";
    for (size_t i = 0; i < ds.ds.size(); i++) {
        cout << "Ten: " << ds.ds[i].ten
             << ", So luong: " << ds.ds[i].so_luong
             << ", DVT: " << ds.ds[i].dvt
             << ", Don gia: " << ds.ds[i].don_gia << "\n";
    }
}
int tim_loai_hoa(danh_sach_loai_hoa ds, const string &ten_loai) {
    for (size_t i = 0; i < ds.ds.size(); i++) {
        if (strcmp(ds.ds[i].ten, ten_loai.c_str()) == 0) {
            return i;  
        }
    }
    return -1;  
}
void xu_ly_ban_hoa(danh_sach_loai_hoa &ds, const string &ten_loai, int so_luong) {
    int index = tim_loai_hoa(ds, ten_loai);
    if (index == -1) {
        cout << "Loai hoa khong ton tai!\n";
        return;
    }
    if (ds.ds[index].so_luong >= so_luong) {
        double tong_tien = so_luong * ds.ds[index].don_gia;
        ds.ds[index].so_luong -= so_luong;
        cout << "Ban thanh cong! Tong tien: " << tong_tien << " VND\n";
    } else {
        cout << "Khong du so luong hoa de ban!\n";
    }
}
int main() {
    danh_sach_loai_hoa ds;
    nhap_danh_sach(ds);
    xuat_danh_sach(ds);
    string ten_loai;
    int so_luong;
    cout << "\nNhap ten loai hoa can mua: ";
    getline(cin, ten_loai);
    cout << "Nhap so luong can mua: ";
    cin >> so_luong;
    cin.ignore();
    xu_ly_ban_hoa(ds, ten_loai, so_luong);
    xuat_danh_sach(ds);
    return 0;
}

