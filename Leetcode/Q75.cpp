class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto it0 = nums.begin();
        auto it1 = nums.begin();
        auto it2 = nums.begin();
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            switch (*it) {
                case 0:
                    it2[0] = (it2 == nums.begin()) ? 0 : it2[-1];
                    it1[0] = (it1 == nums.begin()) ? 0 : it1[-1];
                    it0[0] = 0;
                    ++it0; ++it1; ++it2;
                    break;
                case 1:
                    it2[0] = (it2 == nums.begin()) ? 1 : it2[-1];
                    it1[0] = 1;
                    ++it1; ++it2;
                    break;
                case 2:
                    it2[0] = 2;
                    ++it2;
                    break;
                default:
                    assert(false);
            }
        }
    }
};

