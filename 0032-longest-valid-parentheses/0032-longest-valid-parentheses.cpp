class Solution {
public:
    int longestValidParentheses(string str)
{
    // create an empty stack
    stack<int> stk;

    // push -1 onto the stack to mark the end
    stk.push(-1);

    // length of the longest valid parentheses substring
    int maxLen = 0;

    // traverse the string
    for (int i = 0; i < str.length(); i++)
    {
        // if the current character is '('
        if (str[i] == '(')
        {
            // push the index of '(' onto the stack
            stk.push(i);
        }
        else
        {
            // pop the topmost element from the stack
            stk.pop();

            // if the stack is empty, we push the current index to the stack
            if (stk.empty())
            {
                stk.push(i);
            }
            else
            {
                // otherwise update the length of the longest
                // valid substring ending at the current index
                maxLen = max(maxLen, i - stk.top());
            }
        }
    }

    return maxLen;
}
};