#include <bits/stdc++.h>
using namespace std;

bool backtrack(int index, int current_sum, int k, const vector<int> &nums, vector<int> &path) {
    if (current_sum == k) {
        return true;
    }
    if (current_sum > k || index == nums.size()) {
        return false;
    }
    path.push_back(nums[index]);
    if (backtrack(index + 1, current_sum + nums[index], k, nums, path)) {
        return true;
    }
    path.pop_back();
    if (backtrack(index + 1, current_sum, k, nums, path)) {
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(auto &num : nums){
            cin >> num;
        }
        vector<int> path;
        bool found = backtrack(0, 0, k, nums, path);
        if(found){
            cout << "YES\n";
            bool first = true;
            for(int num : path){
                if(num == 0) continue;
                if(!first) cout << " ";
                cout << num;
                first = false;
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}
