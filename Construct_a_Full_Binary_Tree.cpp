/* Structure of Binary Tree Node
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	Node* constructFBT(vector<int> &pre, int &idx, int l, int h, vector<int> &preMirror) {
		if (idx >= pre.size() || l>h)
			return nullptr;
		Node* root = new Node(pre[idx++]);
		if (l == h)
			return root;
		int i;
		for (i = l; i <= h; i++) {
			if (preMirror[i] == pre[idx])
				break;
		}
		if (i <= h) {
			root->left = constructFBT(pre, idx, i, h, preMirror);
			root->right = constructFBT(pre, idx, l + 1, i - 1, preMirror);
		}
		return root;
	}
	Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
		// code here
		int idx = 0;
		int n = pre.size();
		return constructFBT(pre, idx, 0, n - 1, preMirror);
	}
};
