#include <bits/stdc++.h>
using namespace std;

// For each cell (i, j), the code finds the minimum distance from the four boundaries 
// (top, left, bottom, right) and subtracts it from n to print number layers

/*

4444444
4333334
4322234
4321234
4322234
4333334
4444444

*/

int main()
{
    int n = 4;
    
    for(int i = 0; i < (2 * n) - 1; i++){
        for(int j = 0; j < (2 * n) - 1; j++){
            int top = i;
            int left = j;
            int bottom = (2 * n - 2) - i;
            int right = (2 * n - 2) - j;
            
            cout << n - min(min(left, right), min(bottom, top));
        }
        
        cout << endl;
    }

    return 0;
}
