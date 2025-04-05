#include <iostream>

using namespace std;
bool ktsnt(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void sap_xep(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    int snt[10000], count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (ktsnt(x)) {
            snt[count++] = x;
        }
    }
    sap_xep(snt, count);
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << snt[i] << " ";
    }
    cout << endl;
    return 0;
}

