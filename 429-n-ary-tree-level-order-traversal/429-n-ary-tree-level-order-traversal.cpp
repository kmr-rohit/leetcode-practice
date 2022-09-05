/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if(root == NULL){
            return res;}
        vector<int> v;
        q.push(root);
        v.push_back(root->val);
        res.push_back(v);
        while(!q.empty()){
            v.clear();
            int size = q.size();
            while(size--){
                 Node* temp = q.front();
                 q.pop();
                vector<Node*> childArr = temp->children;
                int N = childArr.size();
                for(int i = 0;i<N;i++){
                    q.push(childArr[i]);
                    v.push_back(childArr[i]->val);
                }
                }
            if(!q.empty()){
           res.push_back(v);
            }
           
  
        }
       
        return res;
        
    }
};