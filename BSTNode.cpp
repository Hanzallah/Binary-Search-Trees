/**
* Title: Binary Search Trees
* Author: Hanzallah Azim Burney
* ID: 21701829
* Section: 1
* Assignment: 2
* Description: Implementation of BSTNode functions.
*/
#include "BSTNode.h"

BSTNode::BSTNode() {
    item = 0;
    setLeftChildPtr(nullptr);
    setRightChildPtr(nullptr);
}

BSTNode::BSTNode(const key & nodeItem, BSTNode *left, BSTNode *right)
    : item(nodeItem), leftChildPtr(left), rightChildPtr(right) {}

void BSTNode::setItem(const key & anItem) {
    item = anItem;
}

key BSTNode::getItem() const {
    return item;
}

bool BSTNode::isLeaf() const {
    return leftChildPtr == nullptr && rightChildPtr == nullptr;
}

void BSTNode::setLeftChildPtr(BSTNode *leftPtr) {
    this->leftChildPtr = leftPtr;
}

void BSTNode::setRightChildPtr(BSTNode *rightPtr) {
    this->rightChildPtr = rightPtr;
}