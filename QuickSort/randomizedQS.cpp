#include<bits/stdc++.h>
using namespace std;
int part(int a[], int str, int end) {
    int pivot, pindex;
    pindex = rand() % (end-str+1) + str;
    swap(a[end], a[pindex]);
    pindex = str;
    pivot = a[end];
    for(int i = str; i < end; i++) {
        if(a[i] <= pivot) {
            swap(a[i], a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex], a[end]);
    return pindex;
}
void qsort(int a[], int str, int en) {
    if(str < en) {
        int o = part(a, str, en);
        qsort(a, str, o-1);
        qsort(a, o+1, en);
    }
}
int main() { 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        qsort(a, 0, n-1);
        for(int i : a) {
            cout << *a << " "; 
        }
    }
    cout << "\n";
    return 0;
}
