class Solution {
public:

    void merge(vector<int>& arr, int start, int mid, int end) {
        vector<int> temp(end - start + 1);  // Temporary array to store merged values

        int left = start, right = mid + 1, index = 0;

        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
            }
        }

        // Merge remaining elements from left half
        while (left <= mid) {
            temp[index++] = arr[left++];
        }

        // Merge remaining elements from right half
        while (right <= end) {
            temp[index++] = arr[right++];
        }

        // Copy back to original array
        for (int i = 0; i < temp.size(); ++i) {
            arr[start + i] = temp[i];
        }
    }

    void mergesort(vector<int>& arr, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
