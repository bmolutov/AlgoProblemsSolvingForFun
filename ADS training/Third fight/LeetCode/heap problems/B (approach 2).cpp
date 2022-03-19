link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue <int, vector <int>, greater <int>> minHeap;
    int temp;
    KthLargest(int k, vector<int>& nums) {
        temp = k;
        for (auto num: nums) {
            add (num);
            if ((int) minHeap.size () > temp) {
                minHeap.pop ();
            }
        }
    }
    
    int add(int val) {
        minHeap.push (val);
        if ((int) minHeap.size () > temp) {
            minHeap.pop ();
        }
        return minHeap.top ();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
