class Solution {
        public:
                int evalRPN(vector<string>& tokens) {
                        vector<int> stack;

                        for (string& token : tokens) {
                                if (token == "+") {
                                        int second = stack.back(); stack.pop_back();
                                        int first = stack.back(); stack.pop_back();
                                        stack.push_back(first + second);
                                } else if (token == "-") {
                                        int second = stack.back(); stack.pop_back();
                                        int first = stack.back(); stack.pop_back();
                                        stack.push_back(first - second);
                                } else if (token == "/") {
                                        int second = stack.back(); stack.pop_back();
                                        int first = stack.back(); stack.pop_back();
                                        stack.push_back(first / second);
                                } else if (token == "*") {
                                        int second = stack.back(); stack.pop_back();
                                        int first = stack.back(); stack.pop_back();
                                        stack.push_back(first * second);
                                } else {
                                        stack.push_back(stoi(token));
                                }
                        }

                        return stack.back();
                }
};
