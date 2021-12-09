#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    cout<<"enter size of the array: ";
    int n;cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    unordered_map<int,int> freq;

    for(int i=0; i<n; i++)
        freq[arr[i]]++;

    cout<<"\nfrequency of elements\n";
    for(auto ele: freq)
    {
        cout<<ele.first<<":"<<ele.second<<endl;
    }
    return 0;
}
