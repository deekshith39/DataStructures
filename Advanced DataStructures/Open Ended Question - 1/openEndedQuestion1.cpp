#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--){
        cout << "Enter the number of elements : " ;
        int n;
        cin >> n;
        int a[n];
        cout << "Enter the elements : " << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        sort(a, a+n);   
        cout << "Output is : " << endl;
        for (int j = 0; j < n-2; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;             
    }
    
}