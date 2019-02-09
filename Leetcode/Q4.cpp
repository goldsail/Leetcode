class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) {
            return this->getMedian(nums2.data(), 0, nums2.size());
        }
        
        if (nums2.size() == 0) {
            return this->getMedian(nums1.data(), 0, nums1.size());
        }
        
        if ((nums1.size() + nums2.size()) % 2) {
            return this->findMedianOdd(nums1, nums2);
        } else {
            return this->findMedianEven(nums1, nums2);
        }
    }
    
private:
    
    double getMedian(int *arr, int low, int high) {
        int mid = (low + high) / 2;
        if ((low + high) % 2) {
            return arr[mid];
        } else {
            return (arr[mid - 1] + arr[mid]) / 2.0;
        }
    }
    
    double findMedianOdd(vector<int> &nums1, vector<int>& nums2) {
        return findMedian_(nums1, nums2, 0);
    }
    
    double findMedianEven(vector<int> &nums1, vector<int>& nums2) {
        int lowerMedian = findMedian_(nums1, nums2, 1);
        int higherMedian = findMedian_(nums1, nums2, 0);
        return (lowerMedian + higherMedian) / 2.0;
    }
    
    double findMedian_(vector<int> &nums1, vector<int>& nums2, int offset) {
        
        int low, high, pos;
        
        // assume the median is in nums1
        
        low = 0;
        high = nums1.size();
        pos = (low + high) / 2;
        while (high - low > 0) {
            
            int cut = (nums1.size() + nums2.size()) / 2 - (pos + offset);
            
            if (cut < 0) {
                high = pos;
                pos = (low + high) / 2;
            } else if (cut > nums2.size()) {
                low = pos + 1;
                pos = (low + high) / 2;
            } else if (cut > 0 && nums1[pos] < nums2[cut - 1]) {
                low = pos + 1;
                pos = (low + high) / 2;
            } else if (cut < nums2.size() && nums1[pos] > nums2[cut]) {
                high = pos;
                pos = (low + high) / 2;
            } else {
                return nums1[pos];
            }
        }
        
        // assume the median is in nums2
        
        low = 0;
        high = nums2.size();
        pos = (low + high) / 2;
        while (high - low > 0) {
            
            int cut = (nums1.size() + nums2.size()) / 2 - (pos + offset);
            
            if (cut < 0) {
                high = pos;
                pos = (low + high) / 2;
            } else if (cut > nums1.size()) {
                low = pos + 1;
                pos = (low + high) / 2;
            } else if (cut > 0 && nums2[pos] < nums1[cut - 1]) {
                low = pos + 1;
                pos = (low + high) / 2;
            } else if (cut < nums1.size() && nums2[pos] > nums1[cut]) {
                high = pos;
                pos = (low + high) / 2;
            } else {
                return nums2[pos];
            }
        }
        
        // error
        return 0;
    }
    
};