#include <bits/stdc++.h>
using namespace std;

int comparisons = 0;

int partitions(vector<int>& arr, int st, int ed) {
    int pivot = arr[ed];
    int idx = st - 1;

    for(int j = st; j < ed; j++) {
        comparisons++;
        if(arr[j] <= pivot) {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[ed]);
    return idx;
}

void quickSort(vector<int>& arr, int st, int ed) {
    if(st < ed) {
        int pi = partitions(arr, st, ed);
        quickSort(arr, st, pi - 1);
        quickSort(arr, pi + 1, ed);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) cin >> arr[i];

    quickSort(arr, 0, N - 1);

    cout << "Sorted Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\nTotal Comparisons: " << comparisons << endl;
}
