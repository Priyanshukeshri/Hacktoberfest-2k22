===>>Pascals Triangle 1

class Solution {
public:
   
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i(0);i<numRows;i++){
            vector<int>v(i+1,1);
            for(int j(1);j<i;j++){
                v[j]= ans[i-1][j]+ ans[i-1][j-1];
            }
            ans.push_back(v);
            
        }
   return ans;
    }
};

===>PAscals Triangle 2

class Solution {
public:
    vector<int> getRow(int r) {
        vector<int>v(r+1);
        long temp=1;
        v[0]=v[r]=1;
        for(int i=1,up=r,down=1;i<r;i++,up--,down++){
            temp = temp*up/down;
            v[i]=temp;
        }
        return v;
    }
};