#include <iostream>
using namespace std;

// implementacija BST-a koje sadrži pozitivne cijele brojeve
// za negativne brojeve potrebno je promijeniti error-checking
// od prosle godine odnosno 2021./22. godine

struct Node
{
	int key;
	Node *left, *right, *parent;
};

class BST
{
	Node *root;
	
	Node* insert(int key, Node *node)
	{
		if (node == NULL) {
			node = new Node;
			node->key = key;
			node->left = node->right = node->parent = NULL;
		} else if (key > node->key) {
			node->right = insert(key, node->right);
			node->right->parent = node;
		} else {
			node->left = insert(key, node->left);
			node->left->parent = node;
		}
		return node;
			
	}

	void inorder(Node *node)
	{
		if (node == NULL)
			return;
		inorder(node->left);
		cout << node->key << ' ';
		inorder(node->right);
	}

	Node* search(int key, Node *node)
	{
		if (node == NULL || key == node->key)
			return node;
		if (key > node->key)
			return search(key, node->right);
		return search(key, node->left);
	}

	Node* find_min(Node *node)
	{
		if (node == NULL)
			return NULL;
		if (node->left == NULL)
			return node;
		return find_min(node->left);
	}

	Node* find_max(Node *node)
	{
		if (node == NULL)
			return NULL;
		if (node->right == NULL)
			return node;
		return find_min(node->right);
	}

	Node* successor(Node *node)
	{
		if (node->right != NULL)
			return find_min(node->right);

		Node *parent = node->parent;
		while (parent != NULL && node == parent->right) {
			node = parent;
			parent = node->parent;
		}

		return parent;
	}

	Node* predecessor(Node *node)
	{
		if (node->left != NULL)
			return find_max(node->left);

		Node *parent = node->parent;
		while (parent != NULL && node == parent->left) {
			node = parent;
			parent = node->parent;
		}

		return parent;
	}

public:
	BST() : root(NULL) {}
	
	void print()
	{
		inorder(root);
	}

	void insert(int key)
	{
		root = insert(key, root);
	}

	bool search(int key)
	{
		return search(key, root);
	}

	int find_min()
	{
		Node *node = find_min(root);
		if (node != NULL)
			return node->key;
		return -1;
	}

	int find_max()
	{
		Node *node = find_max(root);
		if (node != NULL)
			return node->key;
		return -1;
	}

	int successor(int key)
	{
		Node *node = search(key, root);
		if (node == NULL)
			return -1;
		node = successor(node);
		if (node == NULL)
			return -1;
		return node->key;
	}

	int predecessor(int key)
	{
		Node *node = search(key, root);
		if (node == NULL)
			return -1;
		node = predecessor(node);
		if (node == NULL)
			return -1;
		return node->key;
	}
};

int main()
{
	BST tree;
	tree.insert(5);
	tree.insert(10);
	tree.insert(4);
	tree.insert(8);
	tree.insert(9);
	tree.insert(1);
	tree.insert(11);
	tree.insert(15);
	tree.insert(3);

}