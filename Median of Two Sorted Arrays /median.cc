class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        
        // check if one of the arrays is empty
        if (m == 0) {
            return (m + n) % 2 == 1 ? nums2[n / 2] : (double) (nums2[n / 2 - 1] + nums2[n / 2]) / 2;
        } else if (n == 0) {
            return (m + n) % 2 == 1 ? nums1[m / 2] : (double) (nums1[m / 2 - 1] + nums1[m / 2]) / 2;
        } 
        
        return m < n ? findMedian(n, m, nums2, nums1) : findMedian(m, n, nums1, nums2);
    }
    
    // return the median of the two sorted arrays n1 and n2
    //      requires: n1.length >= n2.length
    double findMedian(int &m, int &n, vector<int>& n1, vector<int>& n2) {
        int target = (m + n) / 2;
        int low = 0;
        int high = m + n - 1;
            
        // perform binary search on the amount of number taken from n1
        while (low <= high) {
            int size1 = (low + high + 1) / 2;  // amount of numbers taken from n1
            int size2 = target - size1; // amount of numbers taken from n2
            
            // let the lower bound (the maximum number in the left block)
            int lower_bound = 0;
            if (size1 > 0) {
                if (size2 <= n) {
                    lower_bound = size2 > 0 ? max(n1[size1 - 1], n2[size2 - 1]) : n1[size1 - 1];
                } else {
                    low = size1 + 1;
                    continue;
                }     
            } else {
                lower_bound = n2[size2 - 1];
            }
            
            // let the upper_bound bound (the maximum number in the right block)
            int upper_bound = 0;
            if (size1 < m) {
                upper_bound = size2 < n ? min(n1[size1], n2[size2]) : n1[size1];
            } else {
                upper_bound = n2[0];
            }
            
            // check if we have already found the right partition
            if (lower_bound <= upper_bound) {
                return (m + n) % 2 == 1 ? upper_bound : (double) (lower_bound + upper_bound) / 2;
            }
        
            if (size2 > 0 && n2[size2 - 1] >= n1[size1]) {
                low = size1 + 1;
            } else {
                high = size1 - 1;
            }
        }
        return -1;
    }
};