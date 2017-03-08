#include <iostream>

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
	int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode* parent = root;
        TreeLinkNode* pSon = NULL, *pNode = parent;
        while (parent || parent->next) {
            pSon = NULL, pNode = parent;
            while (pNode) {
                if (pNode->left && pNode->right) pNode->left->next = pNode->right;
                pNode = pNode->next;
            }
            pNode = parent;
            while (!pSon) {
                pSon = pNode->left == NULL ? pNode->right : pNode->left;
                if (!pSon && !pNode->next) return;
                else if (!pSon) pNode = pNode->next;
            }//pNode 指向第一个有子节点的节点
            if (!pNode) return;
            while (pNode->next) {
                TreeLinkNode* first = pNode->right ? pNode->right : pNode->left;
                TreeLinkNode* nextparent = pNode->next;
                while (!nextparent->left && !nextparent->right) {
                    nextparent = nextparent->next;
                    if (!nextparent) break;
                }
                if (nextparent) {
                    TreeLinkNode* next = nextparent->left ? nextparent->left : nextparent->right;
                    first->next = next;
                    pNode = nextparent;
                } else break;
            }
            parent = pSon;
        }
    }
};
