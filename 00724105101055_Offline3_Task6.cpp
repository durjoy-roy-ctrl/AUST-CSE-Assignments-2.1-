#include <bits/stdc++.h>
using namespace std;

int partions(vector<int>& arr, int st, int ed)
{
    int pivot = arr[ed];
    int idx = st - 1;
    int c = 0;

    for(int j = st; j < ed; j++)
    {
        if(arr[j] <= pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
            c++;
        }
    }

    idx++;
    swap(arr[idx], arr[ed]);

    cout << "Pivot: " << pivot << " less than ele: " << c << endl;
    return idx;
}


void quickSort(vector<int>& arr, int st, int ed) {
    if(st < ed) {
        int pi = partions(arr, st, ed);
        quickSort(arr, st, pi - 1);
        quickSort(arr, pi + 1, ed);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

}
