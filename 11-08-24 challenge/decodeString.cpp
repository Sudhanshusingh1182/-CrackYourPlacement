class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> num;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int number = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    number = number * 10 + (s[i] - '0');
                    i++;
                }
                num.push(number);
                i--;  // decrement to counter the extra increment at the end of the loop
            } else if (s[i] == '[') {
                st.push("[");
            } else if (s[i] == ']') {
                string res = "";
                while (!st.empty() && st.top() != "[") {
                    res = st.top() + res; // accumulate the result in reverse order
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop the '['

                // Repeat the string res num.top() times
                int times = num.top();
                num.pop();
                string temp = "";
                for (int j = 0; j < times; j++) {
                    temp += res;
                }
                st.push(temp);
            } else {
                st.push(string(1, s[i])); // convert char to string and push
            }
        }

        // Accumulate all elements in the stack to form the final result
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
