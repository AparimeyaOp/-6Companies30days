/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
Output: 16
 

Constraints:

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

/*
 1) MY FIRST ATTEMPT
        TIME COMPLEXITY-> O(LOGN(N+1))
        SPACE COMPLEXITY-> O(1)
        LOGIC-> SORT THE ARRAY
             -> THE MIDDLE ELEMENT WILL BE THE CLOSEST TO ALL THE ELEMENTS
             -> FIND THE MIDDLE
             -> RUN THROUGH THE ARRAY, FIND DIFF
             -> ADD DIFFERENCE TO THE OUTPUT
*/
sort(nums.begin(),nums.end());
int mid = nums.size()/2;
int moves = 0;
for(auto n:nums){
      moves += abs(nums[mid]-n);
}
return moves;
