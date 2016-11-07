#include<bits/stdc++.h>
using namespace std;
void merge(int A[], int left, int mid, int right) {
    int n1 = mid-left+1, n2 = right - mid;
    int B[n1], C[n2];
    for(int i = 0; i < n1; i++) {
        B[i] = A[i + left];
    }
    for(int i = 0; i < n2; i++) {
        C[i] = A[i + left + mid];
    }
    int ii = 0, jj = 0, k = left;
    while(ii < n1 && jj < n2) {
        if(B[ii] <= C[jj]) {
            A[k++] = B[ii++];
        } else {
            A[k++] = C[jj++];
        }
    }
    while(ii < n1) {
        A[k++] = B[ii++];
    }
    while(jj < n2) {
        A[k++] = C[jj++];
    }
    for(int i = left; i <= right; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}
void mergeSort(int A[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, right);
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }
        mergeSort(A, 0, n-1);
        for(int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
