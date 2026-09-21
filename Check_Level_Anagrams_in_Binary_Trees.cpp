/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        if (root1 == nullptr || root2 == nullptr)
                return root1 == root2;
            queue<Node *> q1;
            queue<Node *> q2;

            q1.push(root1);
            q2.push(root2);

            while (!q1.empty() && !q2.empty())
            {
                int n1 = q1.size();
                int n2 = q2.size();
                if (n1 != n2)
                    return false;

                vector<int> level1;
                vector<int> level2;

                // Store the values of the current level of both trees.
                for (int i = 0; i < n1; i++)
                {
                    Node *node1 = q1.front();
                    Node *node2 = q2.front();

                    q1.pop();
                    q2.pop();

                    level1.push_back(node1->data);
                    level2.push_back(node2->data);

                    // Add children for processing the next level.
                    if (node1->left != nullptr)
                        q1.push(node1->left);

                    if (node1->right != nullptr)
                        q1.push(node1->right);

                    if (node2->left != nullptr)
                        q2.push(node2->left);

                    if (node2->right != nullptr)
                        q2.push(node2->right);
                }

                // Sort the values so that their order does not matter.
                sort(level1.begin(), level1.end());
                sort(level2.begin(), level2.end());

                // If sorted levels differ, they are not anagrams.
                if (level1 != level2)
                    return false;
            }

            // All corresponding levels matched.
            return q1.empty() && q2.empty();
    }
};
