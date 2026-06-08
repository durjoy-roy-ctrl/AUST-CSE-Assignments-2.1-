#include<bits/stdc++.h>
using namespace std;

bool isBest(int a,int b,vector<int>&year,vector<string>&author,vector<string>&title)
{
    if(year[a]!=year[b])
    {
        return year[a]>year[b];
    }
    else if(author[a]!=author[b])
    {
        return author[a]<author[b];
    }
    else
    {
        return title[a]<title[b];
    }
}


int main()
{
    int N;
    cin>>N;
    cin.ignore();

    vector<string>title(N),author(N);
    vector<int>year(N);

    for(int i=0; i<N; i++)
    {
        string pubYear;

        getline(cin,title[i],',');
        getline(cin,author[i],',');
        getline(cin,pubYear);
        year[i]=stoi(pubYear);
    }

    for(int i=0; i<N; i++)
    {
        int best=i;
        for(int j=i+1; j<N; j++)
        {
            if(isBest(j,best,year,author,title))
            {
                best = j;
            }
        }
        swap(year[i],year[best]);
        swap(author[i],author[best]);
        swap(title[i],title[best]);
    }

    for(int i=0; i<N; i++)
    {
        cout << title[i] << "," << author[i] << "," << year[i] << endl;
    }

    return 0;
}
