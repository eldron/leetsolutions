/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode ** par, TreeNode * node){
    	if(!node->left && !node->right){
    		// no children
    		*par = NULL;
    	} else if(!node->left || !node->right){
    		// one child
    		*par = node->left ? node->left : node->right;
    	} else {
    		// two children
    		TreeNode * p = node->right;
    		TreeNode * pre = p;
    		while(p->left){
    			pre = p;
    			p = p->left;
    		}
    		if(p == node->right){
    			// use node->right to replace node
    			node->right->left = node->left;
    			*par = node->right;
    		} else {
    			// use p to replace node
    			pre->left = p->right;
    			p->left = node->left;
    			p->right = node->right;
    			*par = p;
    		}
    	}
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
    	if(root){
    		if(root->val == key){
    			TreeNode * par = root;
    			helper(&par, root);
    			return par;
    		} else {
    			TreeNode ** par;
    			TreeNode * node = root;
    			while(node){
    				if(node->val == key){
    					break;
    				} else if(node->val > key){
    					par = &(node->left);
    					node = node->left;
    				} else {
    					par = &(node->right);
    					node = node->right;
    				}
    			}

    			if(node){
    				helper(par, node);
    			}
    			return root;
    		}
    	} else {
    		return NULL;
    	}
    }
};