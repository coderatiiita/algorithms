#include<bits/stdc++.h>
using namespace std;
int partition(int a[], int start, int end) {
    int pivot, pindex;
    pindex = rand() % (end-start+1) + start;
    pivot = a[pindex];
    swap(a[end], a[pindex]);
    pindex = start;
    for(int i = start; i < end; i++) {
        if(a[i] < pivot) {
            swap(a[i], a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex], a[end]);
    cout << "\npivot = " << pivot;
    cout << " Elements are :\n";
    for(int i = start; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return pindex;
}
void qsort(int a[], int start, int end) {
    if(start < end) {
        int p_index = partition(a, start, end);
        qsort(a, start, p_index-1);
        qsort(a, p_index+1, end);
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
            cout << i << " "; 
        }
    }
    cout << "\n";
    return 0;
}
