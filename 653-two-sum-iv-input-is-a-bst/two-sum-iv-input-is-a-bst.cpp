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

class BSTIterator{
    stack<TreeNode*> mystack;
    bool reverse; //true->before(), false->next()

    public:
       BSTIterator(TreeNode* root, bool isReverse){
         reverse = isReverse;
         pushAll(root);
       }   

       bool hasNext(){
        return !mystack.empty();
       }

       int next(){
        TreeNode* temp = mystack.top();
        mystack.pop();

        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
       }

    
    private:
       void pushAll(TreeNode* node){
        while(node != nullptr){
            mystack.push(node);
            if(reverse){
                node = node->right; //before
            } else{
                node = node->left; //next
            }
        }
       }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;

        BSTIterator l(root, false); //next()
        BSTIterator r(root, true);  //before()

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};


// class BSTIterator {
//     stack<TreeNode*> mystack;
//     bool reverse; // true->before(), false->next()

// public:
//     BSTIterator(TreeNode* root, bool isReverse) {
//         reverse = isReverse;
//         pushAll(root);
//     }   

//     bool hasNext() {
//         return !mystack.empty();
//     }

//     int next() {
//         TreeNode* temp = mystack.top();
//         mystack.pop();

//         if(!reverse) pushAll(temp->right);
//         else pushAll(temp->left);
//         return temp->val;
//     }

// private:
//     void pushAll(TreeNode* node) {
//         while(node != nullptr) {
//             mystack.push(node);
//             if(reverse) {
//                 node = node->right; // before
//             } else {
//                 node = node->left; // next
//             }
//         }
//     }
// };

// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         if(root == nullptr) return false;

//         BSTIterator l(root, false); // next()
//         BSTIterator r(root, true);  // before()

//         int i = l.next();
//         int j = r.next();
        
//         while(i < j) {
//             if(i + j == k) return true;
//             else if(i + j < k) i = l.next();
//             else j = r.next();
//         }
//         return false;
//     }
// };