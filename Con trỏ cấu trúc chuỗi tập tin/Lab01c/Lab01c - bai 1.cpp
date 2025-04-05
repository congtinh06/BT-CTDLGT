#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100  
struct nhan_vien {
    char ma_so[11];
    char ho[11];
    char ten[51];
    int phai;
    int tham_nien;
};

struct phong_ban {
    nhan_vien anhan_vien[MAX]; 
    int so_luong;
};

void nhap_phong_ban(phong_ban &pb) {
    cout << "Nhap so luong nhan vien: ";
    cin >> pb.so_luong;

    if (pb.so_luong > MAX || pb.so_luong <= 0) {
        cout << "So luong nhan vien khong hop le!" << endl;
        return;
    }

    for (int i = 0; i < pb.so_luong; i++) {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
        cout << "Ma so: ";
        cin >> pb.anhan_vien[i].ma_so;
        cin.ignore();
        cout << "Ho: ";
        cin.getline(pb.anhan_vien[i].ho, 11);
        cout << "Ten: ";
        cin.getline(pb.anhan_vien[i].ten, 51);
        
        do {
            cout << "Phai (0: Nu, 1: Nam): ";
            cin >> pb.anhan_vien[i].phai;
        } while (pb.anhan_vien[i].phai != 0 && pb.anhan_vien[i].phai != 1);

        do {
            cout << "Tham nien (>= 0): ";
            cin >> pb.anhan_vien[i].tham_nien;
        } while (pb.anhan_vien[i].tham_nien < 0);
    }
}
void xuat_phong_ban(phong_ban pb) {
    cout << "\nDanh sach nhan vien:\n";
    for (int i = 0; i < pb.so_luong; i++) {
        cout << pb.anhan_vien[i].ma_so << " | " << pb.anhan_vien[i].ho << " " 
             << pb.anhan_vien[i].ten << " | " << (pb.anhan_vien[i].phai ? "Nam" : "Nu")
             << " | Tham nien: " << pb.anhan_vien[i].tham_nien << " nam\n";
    }
}
void dem_si_so(phong_ban ds, int &so_nam, int &so_nu) {
    so_nam = so_nu = 0;
    for (int i = 0; i < ds.so_luong; i++) {
        if (ds.anhan_vien[i].phai == 1)
            so_nam++;
        else
            so_nu++;
    }
}
void sap_xep_theo_tham_nien(phong_ban &pb) {
    for (int i = 0; i < pb.so_luong - 1; i++) {
        for (int j = i + 1; j < pb.so_luong; j++) {
            if (pb.anhan_vien[i].tham_nien > pb.anhan_vien[j].tham_nien) {
                swap(pb.anhan_vien[i], pb.anhan_vien[j]);
            }
        }
    }
}
int main() {
    phong_ban pb;
    int so_nam, so_nu;

    nhap_phong_ban(pb);
    xuat_phong_ban(pb);

    dem_si_so(pb, so_nam, so_nu);
    cout << "\nSo nhan vien nam: " << so_nam << endl;
    cout << "So nhan vien nu: " << so_nu << endl;

    sap_xep_theo_tham_nien(pb);
    cout << "\nDanh sach nhan vien sau khi sap xep theo tham nien tang dan:\n";
    xuat_phong_ban(pb);

    return 0;
}

