#include <iostream>
#include <vector>
using namespace std;

// O(n^2) time | O(n) space
vector<vector<int>> threeNumberSum(vector<int> &array, int &targetSum) {
   sort(array.begin(), array.end());// O(nLog(n)) time
   vector<vector<int>> results;// O(n) space
   for(int i = 0; i < array.size() - 2; i++) {// O(n) time
       int left = i + 1;// O(1) space
       int right = array.size() - 1;// O(1) space
       while(left < right) {// O(n) time NESTED
           int currentSum = array[i] + array[left] + array[right];// O(1) time
           if(currentSum < targetSum) {// O(1) time
               left++;
           } else if(currentSum > targetSum) {// O(1) time
               right--;
           } else {
               vector<int> set = {array[i], array[left], array[right]};// O(1) time | O(1) space
               results.push_back(set);// O(1) time | O(1) space
               left++;// O(1) time
               right--;// O(1) time
           }
       }
   }
   return results;// O(1) time
}

int main() {
    vector<int> input = {12, 3, 1, 2, -6, 5, -8, 6};
    int targetSum = 0;
    vector<vector<int>> result = threeNumberSum(input, targetSum);
    for(const vector<int>& set : result) {
        for(int element : set) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}
