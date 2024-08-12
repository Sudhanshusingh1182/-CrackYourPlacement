class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> nums; 
        char lastOp = '+'; 
        int currentNum = 0; 

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                currentNum = currentNum * 10 + (s[i] - '0'); 
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
                if (lastOp == '+') {
                    nums.push(currentNum);
                }
                else if (lastOp == '-') {
                    nums.push(-currentNum);
                } 
                else if (lastOp == '*') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * currentNum);
                } 
                else if (lastOp == '/') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / currentNum);
                }
                lastOp = s[i]; 
                currentNum = 0; 
            }
        }

        
        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }

        return result;
    }
};
