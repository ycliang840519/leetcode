// Binary Search
// some small adjustment on the index

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int left = 1, right = n;
        while (right - left > 1) {
            long long int test = (left + right) / 2;
            if (isBadVersion(test) == false)
                left = test;
            else if (isBadVersion(test) == true)
                right = test;
        }
        if (isBadVersion(left))
            return left;
        else
            return right;
    }
};



// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (right >= left) {
            int mid = left + (right - left) / 2;  // to avoid overflow
            if (isBadVersion(mid) == false)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
