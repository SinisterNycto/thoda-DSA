/*

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *


*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int breakpoint = (2 * n - 1) / 2;
    
    for(int i = 0; i < (2 * n) - 1; i++){
        if(i <= breakpoint){
            // stars
            for(int j = 0; j <= i; j++){
                cout << '*';
            }
            // spaces
            for(int j = (2 * n - 2) - (2 * i); j > 0; j--){
                cout << ' ';
            }
            
            // stars
            for(int j = 0; j <= i; j++){
                cout << '*';
            }
        }
        
        else{
            // stars
            for(int j = (2 * n - 1) - i; j > 0; j--){
                cout << '*';
            }
            // spaces
            for(int j = 0; j < 2 * (i - n + 1); j++){
                cout << ' ';
            }
            
            // stars
            for(int j = (2 * n - 1) - i; j > 0; j--){
                cout << '*';
            }
        }
        
        cout << endl;
    }

    return 0;
}
