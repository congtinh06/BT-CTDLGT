#include<iostream>
#include<cmath>
using namespace std;
int main() {
	float a,b,c,delta, *x1,*x2;
	x1 = new float;
	x2 = new float;
	cout << "Nhap he so a b c: ";
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			cout << "Phuong trinh vo nghiem!";
			
		}
		else {
			cout << "Phuong trinh co 1 nghiem: x = " << -c / b;
			
		}
		
	}
	else {
		delta = b * b - 4 * a * c;
		if (delta < 0) {
			cout << "Phuong trinh vo nghiem ";
			
		}
		else if (delta == 0) {
			*x1 = -b / (2 * a ) ;
			cout << "Phuong trinh co 1 nghiem kep: x = " << *x1;
			
		}
		else {
			*x1 = (-b + sqrt(delta)) / (2 * a);
			*x2 = (-b + sqrt(delta)) / (2 * a);
			cout << "Phuong trinh co 2 nghiem: x1 = " <<*x1 << ", x2 = " << *x2;
			
		}
	}
	delete x1;
	delete x2;
	return 0;
}
