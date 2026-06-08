#include <bits/stdc++.h>
using namespace std;

void merage(vector<int>&arr,int st,int mid,int ed)
{
    vector<int>temp;
    int i=st;
    int j=mid+1;
    while(i<=mid && j<=ed)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid)  temp.push_back(arr[i++]);
    while(j<=ed)  temp.push_back(arr[j++]);


    for(int idx=0; idx<temp.size(); idx++)
    {
        arr[st+idx]=temp[idx];
    }
}


void margeSort(vector<int>&arr,int st, int ed)
{
    if(st<ed)
    {
        int mid = st + (ed-st)/2;
        margeSort(arr,st,mid);
        margeSort(arr,mid+1,ed);

        merage(arr,st,mid,ed);
    }
}

double findMedian(vector<int>&arr){
    int s = arr.size();
    if(s % 2 == 1) {
        return arr[s/2];
    } else {
        return (arr[s/2 - 1] + arr[s/2]) / 2.0;
    }
}

int main()
{
    int n, m;
    cout << "first array size: ";
    cin>>n;

    vector<int> A(n);
    for(int i=0; i<n; i++) cin>>A[i];

    cout << "Second array size: ";
    cin>>m;

    vector<int> B(m);
    for(int i=0; i<m; i++) cin>>B[i];

    vector<int> merged;
    for(int x : A) merged.push_back(x);
    for(int x : B) merged.push_back(x);

    margeSort(merged, 0, merged.size()-1);
    for(int x : merged) cout << x << " ";
    cout << endl;

    double ans = findMedian(merged);
    cout << "Median: " << ans << endl;

    return 0;
}
