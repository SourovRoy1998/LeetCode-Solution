//https://leetcode.com/problems/online-majority-element-in-subarray/



class MajorityChecker {
public:
    unordered_map<int,vector<int>> hmap;
    vector<int> arr;
    
    MajorityChecker(vector<int>& A) {
        for(int i=0;i<A.size();i++){
            hmap[A[i]].push_back(i);
            arr.push_back(A[i]);
        }
    }
    
    int query(int left, int right, int threshold) {
        for(int i=0;i<10;i++){
            int x=arr[left+rand()%(max(right-left,1))];
            int k=upper_bound(hmap[x].begin(), hmap[x].end(),right)-lower_bound(hmap[x].begin(), hmap[x].end(),left);
            if(k>=threshold)
                return x;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
