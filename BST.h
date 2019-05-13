/**
* Title: Binary Search Trees
* Author: Hanzallah Azim Burney
* ID: 21701829
* Section: 1
* Assignment: 2
* Description: BST function prototypes.
*/

#pragma once
#include "BSTNode.h"

class BST {
    public:
        BST();
        BST(const BST & treeToCopy);
        BST & operator=(const BST & right);
        ~BST();

        bool isEmpty() const;
        int getHeight(BSTNode * treePtr) const;
        int getHeightHelper(BSTNode * nodePtr) const;

        void insertItem(int key);
        void deleteItem(int key);
        BSTNode* retrieveItem(int key);
        void inorder(BSTNode * treePtr, int *arr, int & index) const;
        int* inorderTraversal(int & length);
        void inorderContain(BSTNode * treePtr, int * arr, int * seq, int length, int & index) const;
        bool containsSequence(int* seq, int length);
        void countNodesHelper(BSTNode * treePtr, int level, int currLevel, int & numberOfNodes);
        int countNodesDeeperThan(int level);
        bool isBalanced(BSTNode * treePtr);
        void maxBalancedHeightHelper(BSTNode * treePtr, int & height);
        int maxBalancedHeight();

    protected:
        BSTNode * retrieveItemAux(BSTNode * treePtr, int key);
        void insertItemAux(BSTNode *&treePtr, const int & key);
        void deleteItemAux(BSTNode *&treePtr, int searchKey);
        void deleteNodeItem(BSTNode *&treePtr);
        void processLeftMost(BSTNode *&treePtr, key & item);

    private:
        void copyTree(BSTNode *treePtr, BSTNode *&newTreePtr) const;
        void destroyTree(BSTNode *&treePtr);
        BSTNode *rootPtr;
        int totalNodes;
};