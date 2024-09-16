
/*Problem Statement:  Introduction To Dynamic Programming
Memoization: Known as the “top-down” dynamic programming, usually the problem is solved in the direction of the main problem to the base cases.
Tabulation: Known as the “bottom-up '' dynamic programming, usually the problem is solved in the direction of solving the base cases to the main problem
Note: The base case does not always mean smaller input. It depends upon the implementation of the algorithm.

We will be using the example of Fibonacci numbers here. The following series is called the Fibonacci series:

0,1,1,2,3,5,8,13,21,...

We need to find the nth Fibonacci number, where n is based on a 0-based index.

Part - 1: Memoizaton*/
#include <bits/stdc++.h>

using namespace std;

int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}
int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  cout<<f(n,dp);
  return 0;
}/*

Time Complexity: O(N)
Reason: The overlapping subproblems will return the answer in constant time O(1). 
Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).

Space Complexity: O(N)

Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)

Part -2: Tabulation

Tabulation is a ‘bottom-up’ approach where we start from the base case and reach the final answer that we want.*/

#include <bits/stdc++.h>

using namespace std;
int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}
Output: 5

/*Time Complexity: O(N)

Reason: We are running a simple iterative loop

Space Complexity: O(N)

Reason: We are using an external array of size ‘n+1’.

Part 3: Space Optimization

If we closely look at the relation,

dp[i] =  dp[i-1] + dp[i-2]

we see that for any i, we do need only the last two values in the array. So is there a need to maintain a whole array for it? 
The answer is ‘No’. Let us call dp[i-1] as prev and dp[i-2] as prev2. Now understand the following illustration.

Each iteration’s cur_i and prev becomes the next iteration’s prev and prev2 respectively.
Therefore after calculating cur_i, if we update prev and prev2 according to the next step, we will always get the answer. 
After the iterative loop has ended we can simply return prev as our answer.*/

#include <bits/stdc++.h>
using namespace std;
int main() {

  int n=5;
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
     prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}
/*Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(1)
Reason: We are not using any extra space*/

