#include <vector>

using namespace std;

class Solution {
        public:
                vector<int> productExceptSelf(vector<int>& nums) {
                        int n = nums.size();
                        vector<int> result;


                        // prefix product
                        vector<int> preProd(n + 1);
                        preProd[0] = 1;
                        for (int i = 0; i < n; i++) {
                                preProd[i + 1] = preProd[i] * nums[i];
                        }

                        // suffix product
                        vector<int> sufProd(n + 1);
                        sufProd[n] = 1;
                        for (int i = n - 1; i >= 0; i--) {
                                sufProd[i] = sufProd[i + 1] * nums[i];
                        }

                        // product except self vector
                        for (int i = 0; i < n; i++) {
                                int product = preProd[i] * sufProd[i + 1];
                                result.push_back(product);
                        }

                        return result;
                }
};
