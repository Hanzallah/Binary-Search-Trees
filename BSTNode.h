/**
* Title: Binary Search Trees
* Author: Hanzallah Azim Burney
* ID: 21701829
* Section: 1
* Assignment: 2
* Description: BSTNode function prototypes.
*/
#pragma once

typedef int key;
class BSTNode {
    public:
        BSTNode();
        BSTNode(const key & nodeItem, BSTNode *left = nullptr, BSTNode *right = nullptr);
        void setItem(const key & anItem);
        key getItem() const;
    private:
        bool isLeaf() const;
        void setLeftChildPtr(BSTNode *leftPtr);
        void setRightChildPtr(BSTNode *rightPtr);

        key item;
        BSTNode *leftChildPtr;
        BSTNode *rightChildPtr;

        friend class BST;
};