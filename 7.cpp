#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

bool hasThreeConsecutive(int n){
    int digits[6];
    int temp = n;
    for(int i=5; i>=0; i--){
        digits[i] = temp %10;
        temp /=10;
    }
    for(int i=0; i<=3; i++){
        if(digits[i] == digits[i+1] && digits[i] == digits[i+2]){
            return true;
        }
    }
    return false;
}

bool hasValidAdjacentDifference(int n){
    int digits[6];
    int temp = n;
    for(int i=5; i>=0; i--){
        digits[i] = temp %10;
        temp /=10;
    }
    for(int i=0; i<=4; i++){
        if(abs(digits[i] - digits[i+1]) >4 ){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> valid_tickets;
    for(int num=0; num<=666666; num++){
        int temp = num;
        bool valid_digits = true;
        for(int i=0; i<6; i++){
            int digit = temp %10;
            if(digit <0 || digit >6){
                valid_digits = false;
                break;
            }
            temp /=10;
        }
        if(!valid_digits) continue;
        if(hasThreeConsecutive(num)) continue;
        if(!hasValidAdjacentDifference(num)) continue;
        valid_tickets.push_back(num);
    }
    
    int n;
    cin >> n; 
    
    while(n--){
        int x, y;
        cin >> x >> y; 
        
        auto start_it = lower_bound(valid_tickets.begin(), valid_tickets.end(), x);
        auto end_it = upper_bound(valid_tickets.begin(), valid_tickets.end(), y);
        
        int count = distance(start_it, end_it);
        
        if(count ==0){
            cout << "NO\n";
        }
        else{
            for(auto it = start_it; it != end_it; it++){
                cout << setw(6) << setfill('0') << *it << '\n';
            }
        }
        
        cout << '\n';
    }
    
    return 0;
}
