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
    Node* findLCA(Node* root, int p, int q) {
        if (!root || root->data == p || root->data == q) {
            return root;
        }

        Node* leftLCA = findLCA(root->left, p, q);
        Node* rightLCA = findLCA(root->right, p, q);

        if (leftLCA && rightLCA) return root;
        return leftLCA ? leftLCA : rightLCA;
    }
    bool countTurns(Node* root, int target, bool isLeft, int &turns) {
        if (!root) return false;
        if (root->data == target) return true;
        if (countTurns(root->left, target, true, turns)) {
            if (!isLeft) turns++;
            return true;
        }
        if (countTurns(root->right, target, false, turns)) {
            if (isLeft) turns++;
            return true;
        }

        return false;
    }
  public:
    int numberOfTurns(Node* root, int p, int q) {
        Node* lca = findLCA(root, p, q);
        if (!lca) return -1;
        int turns = 0;
        if (lca->data == p) {
            countTurns(lca->left, q, true, turns);
            countTurns(lca->right, q, false, turns);
            return (turns == 0) ? -1 : turns;
        }

        if (lca->data == q) {
            countTurns(lca->left, p, true, turns);
            countTurns(lca->right, p, false, turns);
            return (turns == 0) ? -1 : turns;
        }
        countTurns(lca->left, p, true, turns);
        countTurns(lca->right, p, false, turns);
        
        countTurns(lca->left, q, true, turns);
        countTurns(lca->right, q, false, turns);

        // Add 1 turn for the transition at the LCA hook (moving up from p, turning down to q)
        return turns + 1;
        
    }
};
