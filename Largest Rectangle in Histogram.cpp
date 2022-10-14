class Solution {
public:
   int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        stack<int> s;
        int i=0,area=INT_MIN;
        while(i<n)
        {
            if(s.empty()||arr[s.top()]<=arr[i])
            {
                s.push(i);i++;
            }
            else
            {
                int num=s.top();s.pop();
                int l=s.empty()?-1:s.top();
                area=max(area,arr[num]*(i-l-1));
            }
        }
        while(!s.empty())
        {
            int num=s.top();s.pop();
                int l=s.empty()?-1:s.top();
                area=max(area,arr[num]*(i-l-1));
        }
        return area;
    }

};
