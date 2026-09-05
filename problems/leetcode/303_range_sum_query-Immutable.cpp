// CAN BE MORE OPTIMIZED
#include <vector>
#include <iostream>

using namespace std;

class NumArray {
public:
    vector<int> anums;

    NumArray(vector<int>& nums) {
        anums = nums;
    }
    
    int sumRange(int left, int right) { 
        vector<long long> b = psum(anums);
        return b[right + 1] - b[left];
    }

private:
    vector<long long> psum(vector<int> a) { 
        vector<long long> psum(a.size() + 1);

        for (int i = 0; i < a.size(); ++i) {
            psum[i + 1] = psum[i] + a[i];
        }

        return psum;
    }
};
