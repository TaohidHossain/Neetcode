/*
    Leetcode: 875. Koko Eating Bananas
    https://leetcode.com/problems/koko-eating-bananas/description/
    Time: O(n*log(m)) n -> length of piles and m -> max of piles
    Space: O(1)
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =  1, high = *max_element(piles.begin(), piles.end());
        int result = high;
        while(low <= high){
            int k = (low + high) / 2;
            long long hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += ceil((double) piles[i] / k);
            }
            if(hours <= h){
                high = k - 1;
                result = k;
            }
            else low = k + 1;
        }
        return result;
    }
};
