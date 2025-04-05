#include<iostream>
using namespace std;
int main() {
	int n, k ;
	cin >> n >> k;
	int arr[n];
	for(int i = 0 ; i < n ;i++) {
		cin >> arr[i];
		
	}
	bool found = false;
	for(int i = 0; i < n -1 ; i++){
		for(int j = i + 1 ; j < n ;j++) {
			if (arr[i] + arr[j] == k) {
				cout << arr[i] << " " << arr[j] << endl;
				found = true;
			}
		}
	}
	if(!found ) {
		cout <<"0" << endl;
	}
	return 0;
}





