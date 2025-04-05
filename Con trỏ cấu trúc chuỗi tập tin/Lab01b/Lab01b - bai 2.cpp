#include<iostream>
using namespace std;
bool kiem_tra_xen_ke_chan_le(int *a, int n) {
	for(int i = 1; i < n; i++) {
		if  (((*a + i) % 2 ) == (*(a + i - 1 ) % 2)) {
			return false;
		}
	}
	return true;
}
bool kiem_tra_toan_chan(int *a , int n) {
	for(int i = 0 ; i < n ;i++) {
		if(*(a + i ) % 2 != 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	cout <<"Moi ban nhap so luong phan tu: ";
	cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++) {
		cout << "Phan tu: " << i << ": " ;
		cin >> *(a + i);
		
	}
	if(kiem_tra_xen_ke_chan_le(a,n))
	cout << "Day co tinh chat chan le \n ";
	else 
	cout <<	"Day khong co tinh chan le \n ";
	if (kiem_tra_toan_chan(a,n)) 
	cout << "Day co tinh chat toan chan \n ";
	else
	cout << "Day khogn co tinh chat toan chan \n ";
	delete[] a;
	return 0;
	}
