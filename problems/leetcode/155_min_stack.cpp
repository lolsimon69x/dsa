class MinStack {
        private:
                vector<int> stack;
                int min_value;
        public:
                MinStack() {
                }

                void push(int value) {
                        if (stack.empty()) {
                                min_value = value;
                        }
                        stack.push_back(value);
                        if (min_value > value) {
                                min_value = value;
                        }
                }

                void pop() {
                        stack.pop_back();
                        min_value = *min_element(stack.begin(), stack.end());
                }

                int top() {
                        return stack.back();
                }

                int getMin() {
                        return min_value;
                }
};
