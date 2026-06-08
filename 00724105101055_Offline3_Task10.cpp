#include <bits/stdc++.h>
using namespace std;

int recursiveCalls = 0;

void merage(vector<int>&arr,int st,int mid,int ed) {
    vector<int>temp;
    int i=st;
    int j=mid+1;
    while(i<=mid && j<=ed) {
        if(arr[i]<=arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=ed) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0;idx<temp.size();idx++){
        arr[st+idx]=temp[idx];
    }
}


void margearr(vector<int>&arr,int st, int ed) {
    recursiveCalls++;
    if(st<ed) {
        int mid = st + (ed-st)/2;
        margearr(arr,st,mid);
        margearr(arr,mid+1,ed);

        merage(arr,st,mid,ed);
    }
}

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int &p:arr) cin>>p;

    margearr(arr,0,arr.size()-1);
    for(int val:arr){
         cout << val << " ";
    }
    cout << "\nTotal recursive calls: " << recursiveCalls << endl;


    return 0;
}
