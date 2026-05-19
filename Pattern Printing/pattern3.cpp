/*

************
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
************

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;

    // upper symmetry
    
    for(int i = 0; i < n; i++){
        // stars
        for(int j = 0; j < (n - i); j++){
            cout << '*';
        }
        
        // space
        for(int j = 0; j < (2 * i); j++){
            cout << ' ';
        }
        
        // stars
        for(int j = 0; j < (n - i); j++){
            cout << '*';
        }
        
        cout << endl;
    }

    // lower symmetry
    
    for(int i = 0; i < n; i++){
        // stars
        for(int j = 0; j <= i; j++){
            cout << '*';
        }
        
        // space
        for(int j = (2 * n - 2) - (2 * i); j > 0; j--){
            cout << ' ';
        }
        
        // stars
        for(int j = 0; j <= i; j++){
            cout << '*';
        }
        
        cout << endl;
    }
    
    return 0;
}
