//https://leetcode.com/problems/find-in-mountain-array/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
private:
    
    int peak(MountainArray v, int low, int high)
    {
        if(low + 1 == high)
            return low;
        int mid = low + (high - low)/2;
        if(v.get(mid) > v.get(mid-1) && v.get(mid) > v.get(mid+1))
            return mid;
        else if(v.get(mid - 1) > v.get(mid))
            return peak(v, low, mid);
        else
            return peak(v, mid + 1, high);
    }
    
    
    int search(MountainArray nums, int target, int start, int end, bool reverse) {
        while(start<=end){
            int mid = (start+end)/2;
            if(target == nums.get(mid)) {return mid;}
            else if (reverse==false && target < nums.get(mid)) {end = mid-1;}
            else if (reverse==true && target > nums.get(mid)) {end = mid-1;}
            else {start = mid+1;}
        }
        return -1;
    }
    
    
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l=mountainArr.length();
        int p=peak(mountainArr,0,l); //find peak index
        int ans=search(mountainArr,target,0,p,false); //search index in left side of index
        if(ans==-1)
            ans=search(mountainArr,target,p+1,l-1,true);//if not found, then search in right side
        
        
        
        return ans;
    }
};
