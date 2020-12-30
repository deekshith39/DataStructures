#include <bits/stdc++.h>

using namespace std;

void printUnique(int L, int R) {
    for (int i = L; i <= R; i++)
    {
        int n = i;
        int rem;
        bool again[10] = {false};
        while (n) {
            rem = n % 10;
            if (again[rem])
                break;
            again[rem] = true;
            n /= 10; 
        }
        if (n == 0)
            cout << i << " ";
    }    
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int L, R;
        cout << "Enter the limits : "; 
        cin >> L >> R;
        cout << "Output is : " << endl;
        printUnique(L, R);
        cout << endl;
    }
}