#include <bits/stdc++.h>
using namespace std;

int partPi(vector<int>& arr, int st, int ed)
{
    int pivot = arr[ed];
    int idx = st - 1;

    for(int j = st; j < ed; j++)
    {
        if(arr[j] < pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[ed], arr[idx]);

    return idx;
}

void rearrangeArr(vector<int>& arr, int pivot)
{
    int n = arr.size();
    int pitIdx = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == pivot)
        {
            pitIdx = i;
            break;
        }
    }
    swap(arr[pitIdx], arr[n - 1]);
    partPi(arr, 0, n - 1);
}


int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pivot;
    cin >> pivot;

    rearrangeArr(arr,pivot);


    for(int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
