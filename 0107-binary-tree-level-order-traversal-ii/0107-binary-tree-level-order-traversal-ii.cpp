/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void LevelOrderrr( vector<vector<int>>& L , TreeNode* Root ){
       
       vector<int>Result;
       queue<TreeNode*>q;
       q.push(Root);
       q.push(nullptr);

       while( !q.empty()){
           
            TreeNode* node = q.front();
            q.pop();

            if( node == nullptr ){
                 L.push_back(Result);
                 Result.clear();
                 if( !q.empty()){
                     q.push(nullptr);
                 }
            }
            else{
                 Result.push_back(node->val);

                 if( node -> left ) q.push(node->left);
                 if( node -> right ) q.push(node->right);
            }
       }
  }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>LevelOrder;
        if( root == nullptr ) return LevelOrder;
        LevelOrderrr( LevelOrder , root );
        reverse( LevelOrder.begin() , LevelOrder.end());
        return LevelOrder;
    }
};