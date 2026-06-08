#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>arr, int key)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int lowerBound(vector<int>arr, int key)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= key)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int upperBound(vector<int>arr, int key)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > key)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> books(n);
    for (int i = 0; i < n; i++) cin >> books[i];

    int key;
    cin >> key;

    if (binarySearch(books, key))
        cout << "Book Found" << endl;
    else
        cout << "Book Not Found" << endl;

    cout << "Lower Bound Index: " << lowerBound(books, key) << endl;
    cout << "Upper Bound Index: " << upperBound(books, key) << endl;

    return 0;
}



