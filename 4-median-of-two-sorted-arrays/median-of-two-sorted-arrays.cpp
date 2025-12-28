class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()) return findMedianSortedArrays(b,a);
        int n=a.size(),m=b.size(),l=0,r=n;
        while(l<=r){
            int i=(l+r)/2;
            int j=(n+m+1)/2-i;
            int l1=i? a[i-1]:INT_MIN;
            int r1=i<n? a[i]:INT_MAX;
            int l2=j? b[j-1]:INT_MIN;
            int r2=j<m? b[j]:INT_MAX;
            if(l1<=r2&&l2<=r1){
                if((n+m)%2) return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            if(l1>r2) r=i-1;
            else l=i+1;
        }
        return 0;
    }
};
