class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if(m*n != l) {
            return {};
        }

       /* int idx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[idx];
                idx++;
                
            }*/
            for(int i =0; i<l; i++){
                result[i/n][i%n]=original[i];
            
        }

        return result;
    }
};


//T.C : O(m*n)
//S.C : O(1) //no including space of result
// FOR Both

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m =rolls.size();
        int sum=mean*(n+m);
        for(int i=0; i<m; i++){
        sum-=rolls[i];
        }
        if(sum<n ||sum>6*n){
            return {};
        }
        int avg=sum/n;
        int rem=sum%n;
        vector<int>res(n,avg);
        for(int i=0; i<n; i++){
            res[i]=avg;
            if(rem>0){
                res[i]++;
                rem--;
            }
        }
        return res;
        

    }
}; 
//TC= O(M+N)
// SC= CONSTANT SPACE
