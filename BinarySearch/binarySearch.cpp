#include<bits/stdc++.h>
#define max_ele 1000
using namespace std;
int binarySearch(int a[], int n, int k) {
    int left = 0, right = n-1;
    while(left <= right) {
        int mid = left + (right-left)/2;
        if(a[mid] == k) {
            return mid+1;
        } else if(k < a[mid]) {
           right = mid-1;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    srand(time(0));
    for(int i = 0; i < n; i++) {
        a[i] = rand() % max_ele;
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        if((k=binarySearch(a, n, k))) {
            cout << "Found at: " << k << " position\n";
        } else {
            cout << "Not found.\n";
        }
    }
    return 0;
}
