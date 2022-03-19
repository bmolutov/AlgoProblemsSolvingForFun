link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue <int, vector <int>, greater <int>> minHeap;
    int temp;
    KthLargest(int k, vector<int>& nums) {
        temp = k;
        for (auto num: nums) {
            add (num);
        }
    }
    
    int add(int val) {
        if (minHeap.size () < temp) {
            minHeap.push (val);
        } else {
            if (val > minHeap.top ()) {
                minHeap.pop ();
                minHeap.push (val);
            }
        }
        return minHeap.top ();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */