#include<bits/stdc++.h>
using namespace std;
class SegTree{
    vector<int> seg;
    int parent(int i){return i/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    int combineSegs(int v1, int v2){
        return v1+v2;
        //or max:
        return max(v1,v2);
    }
    int combId = 0;// = INT_MIN for max. = INT_MAX for min.
    void build(int i, int l, int r,vector<int> &a){
        if(l==r){
            seg[i] = a[l];
        }
        else{
            int del = (r-l)/2, li, ri;
            li = left(i);
            ri = right(i);
            build(li,l,l+del,a);
            build(ri,l+del+1,r,a);
            seg[i] = seg[li]+seg[ri];
        }
    }
    SegTree(vector<int> &a){
        int n = a.size();
        seg = vector<int>(4*n,0);
        build(0,0,n-1,a);
    }
    int query(int i, int s, int e, int l, int r){
        if(r<s || l>e){
            //l,r completely out of s,e
            return combId;//identity of merge.
        }
        else if(l<=s && r>=e){
            return seg[i];
        }
        else{
            int vl, vr, li, ri,del;
            li = left(i);
            ri = right(i);
            del = (e-s)/2;
            vl = query(li,s,s+del,l,r);
            vr = query(ri,s+del+1,e,l,r);
            return combineSegs(vl,vr);
        }
    }
    int findRange(int l, int r){
        return query(0,0,(seg.size()/4)-1,l,r);
    }
};

//alternatively:
class SegmentTree{
    int n;
    vector<int> segs;
    void build(vector<int> &nums) {  // build the tree
        n = nums.size();
        segs = vector<int>(2*n,0);
        for(int i=0;i<n;i++){
            segs[n+i] = nums[i];
        }
        for (int i = n - 1; i > 0; --i){
            segs[i] = segs[i<<1] + segs[i<<1|1];
        }
    }

    void modify(int p, int value) {  // set value at position p
        p += n;
        segs[p] = value;
        for (; p > 1; p >>= 1){
            segs[p>>1] = segs[p] + segs[p^1];//parent val = combine current p and sibling of p.
        }
    }

    int query(int l, int r) {  // sum on interval [l, r)
        int res = 0;
        l+=n;
        r+=n;
        // if inclusive r, r+=1;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += segs[l++];
            if (r&1) res += segs[--r];
        }
        return res;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main(){
    vector<int> nums = {-28,-39,53,65,11,-56,-65,-39,-43,97};
}