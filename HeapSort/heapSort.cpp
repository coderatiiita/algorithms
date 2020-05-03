#include<bits/stdc++.h>
#define max_ele 1000
using namespace std;

void heapify(int a[], int n, int i) {
    int lchild = 2*i+1;
    int rchild = lchild+1;
    int largest = i;

    if(lchild < n && a[lchild] > a[largest]) {
        largest = lchild;
    }
    if(rchild < n && a[rchild] > a[largest]) {
        largest = rchild;
    }
    if(largest!=i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void hsort(int a[], int n) {
    for(int i=n/2-1; i>=0; i--) {
        heapify(a, n, i);
    }
    for(int i=n-1; i>0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main() { 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        srand(time(0));
        for(int i = 0; i < n; i++) {
            a[i] = rand() % max_ele;
        }
        hsort(a, n);
        for(int i : a) {
            cout << i << " "; 
        }
    }
    cout << "\n";
    return 0;
}