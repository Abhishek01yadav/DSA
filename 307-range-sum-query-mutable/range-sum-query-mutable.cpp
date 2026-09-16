class NumArray {
public:
    int n;
    vector<int> segtree;

    void buildSegtree(int i, int l, int r, 
                      vector<int>& nums) {
        if (l == r) {
            segtree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegtree(2 * i + 1, l, mid,  nums);
        buildSegtree(2 * i + 2, mid + 1, r,nums);

        segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
    }

    void updateSegtree(int i, int l, int r, int idx, int val) {
        if (l == r) {
            segtree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            updateSegtree(2 * i + 1, l, mid, idx, val);
        } 
        else 
        {
            updateSegtree(2 * i + 2, mid + 1, r, idx, val);
        }
        segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
    }


    int rangeQuerysum(int i, int l, int r, int start, int end) {
        if (start > r || end < l) {
            return 0;
        }

        if (l>=start && r <=end) {
            return segtree[i];
        }

        int mid = l + (r - l) / 2;

      return   rangeQuerysum(2 * i + 1, l, mid, start, end)+
        rangeQuerysum(2 * i + 2, mid + 1, r, start, end);

    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4 * n);
        buildSegtree(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        updateSegtree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return rangeQuerysum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */