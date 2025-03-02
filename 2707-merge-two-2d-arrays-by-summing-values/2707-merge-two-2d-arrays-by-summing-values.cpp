class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ret;
        int i1 = 0, i2 = 0;
        const int len1 = nums1.size();
        const int len2 = nums2.size();
        
        while(i1 < len1 && i2 < len2){
            int id1 = nums1[i1].front();
            int id2 = nums2[i2].front();
            if(id1 < id2){
                ret.push_back(nums1[i1]);
                i1++;
            }
            else if (id2 < id1){
                ret.push_back(nums2[i2]);
                i2++;
            }
            else{
                ret.push_back(nums1[i1]);
                ret.back().back() += nums2[i2].back();
                i1++;
                i2++;
            }
        }
        while(i1 < len1){
            ret.push_back(nums1[i1]);
            i1++;
        }
        while(i2 < len2){
            ret.push_back(nums2[i2]);
            i2++;
        }

        return ret;
    }
};