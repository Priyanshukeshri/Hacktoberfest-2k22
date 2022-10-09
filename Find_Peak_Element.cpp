class Solution {
public:
    int findPeakElement(vector<int>& arr) {
       
      int s=0,e=arr.size()-1,ans;
        int m=(s+ (e-s)/2);
        while(s<e)
        {
         if(arr[m]<arr[m+1])
             s=m+1;
          else
              e=m; 
          
            m=(s+(e-s)/2);
       }
        return s;
    }
};
