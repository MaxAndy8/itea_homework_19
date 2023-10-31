#pragma once
namespace MY {

    template <typename T>
    class BinaryTree {
    private:
        struct TreeNode {
            T value;
            TreeNode* left;
            TreeNode* right;

            TreeNode(const T& val) : value(val), left(nullptr), right(nullptr) {}
        };

        TreeNode* root;

        void deleteTree(TreeNode* node) {
            if (node) {
                deleteTree(node->left);
                deleteTree(node->right);
                delete node;
            }
        }

        TreeNode* insertRec(TreeNode* p_root, const T& value) {
            if (p_root == nullptr) {
                return new TreeNode(value);
            }

            if (value < p_root->value) {
                p_root->left = insertRec(p_root->left, value);
            }
            else if (value > p_root->value) {
                p_root->right = insertRec(p_root->right, value);
            }

            return p_root;
        }

        void inorderTraversal(TreeNode* node) const {
            if (node != nullptr) {
                inorderTraversal(node->left);
                std::cout << node->value << std::endl;
                inorderTraversal(node->right);
            }
        }

    public:
        BinaryTree() : root(nullptr) {}
        ~BinaryTree() {
            deleteTree(root);
        }

        void insert(const T& value) {
            root = insertRec(root, value);
        }
        
        friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& tree) {
            tree.inorderTraversal(tree.root);
            return os;
        }
    };
}
































