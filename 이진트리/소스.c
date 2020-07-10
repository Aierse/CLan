#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root) {
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}

void main() {
	TreeNode n1 = { 1, NULL, NULL };
	TreeNode added = { 7, NULL, NULL };
	TreeNode n2 = { 4, &n1, &added };
	TreeNode n3 = { 16, NULL, NULL };
	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode* root = &n6;

	printf("중순위 탐색 결과 :\t");
	inorder(root);
	printf("\n");
	printf("선순위 탐색 결과 :\t");
	preorder(root);
	printf("\n");
	printf("후순위 탐색 결과 :\t");
	postorder(root);
	printf("\n");
}