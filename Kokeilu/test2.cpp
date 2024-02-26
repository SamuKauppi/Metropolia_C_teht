#include "algorithm"
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

public:

	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = getHeight(root->left);
		int rightHeight = getHeight(root->right);

		if(abs(leftHeight - rightHeight) <= 1 &&
			isBalanced(root->left) &&
			isBalanced(root->right))
		{
			return true;
		}
		return false;
	}

	int getHeight(TreeNode* node)
	{

		if (node == nullptr)
			return 0;

		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);

		return 1 + max(leftHeight, rightHeight);
	}

	TreeNode* searchBST(TreeNode* root, int val) 
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (root->val == val)
		{
			return root;
		}

		if (root->val > val)
		{
			return searchBST(root->left, val);
		}
		else
		{
			return searchBST(root->right, val);
		}
	}

};


int main()
{

}