// 3013. Divide an Array Into Subarrays With Minimum Cost II

// You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.

// The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

// You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.

// Return the minimum possible sum of the cost of these subarrays.

// two multisets maintain the first k smallest values
class Container {
public:
    Container(int k) : k(k), sm(0) {}

    // adjust the size of the ordered set to ensure that the first k smallest
    // values are all in st1
    void adjust() {
        while (st1.size() < k && st2.size() > 0) {
            int x = *(st2.begin());
            st1.emplace(x);
            sm += x;
            st2.erase(st2.begin());
        }
        while (st1.size() > k) {
            int x = *prev(st1.end());
            st2.emplace(x);
            st1.erase(prev(st1.end()));
            sm -= x;
        }
    }

    // insert element x
    void add(int x) {
        if (!st2.empty() && x >= *(st2.begin())) {
            st2.emplace(x);
        } else {
            st1.emplace(x);
            sm += x;
        }
        adjust();
    }

    // delete element x
    void erase(int x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            st1.erase(it), sm -= x;
        } else {
            st2.erase(st2.find(x));
        }
        adjust();
    }

    // sum of the first k smallest elements
    long long sum() { return sm; }

private:
    int k;
    // st1 saves the k smallest values, st2 saves the other values
    multiset<int> st1, st2;
    // sm represents the sum of the first k smallest elements
    long long sm;
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // sliding window initialization
        Container cnt(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        long long ans = cnt.sum() + nums[k - 1];
        // enumerate the beginning of the last array
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.erase(nums[j]);
            }
            cnt.add(nums[i - 1]);
            ans = min(ans, cnt.sum() + nums[i]);
        }

        return ans + nums[0];
    }
};