/**
* Title: Binary Search Trees
* Author: Hanzallah Azim Burney
* ID: 21701829
* Section: 1
* Assignment: 2
* Description: Implementation of BST functions.
*/

#include <iostream>
#include <cmath>
#include "BST.h"

/*
* Finds the maximum of two integer values and returns it.
*/
int max(int a, int b) {
    return (a < b) ? b : a;
}

/*
* Finds the minimum of two integer values and returns it.
*/
int min(int a, int b) {
    return (a < b) ? a : b;
}

BST::BST(): rootPtr(nullptr), totalNodes(0)
{
}

BST::BST(const BST & treeToCopy): totalNodes(treeToCopy.totalNodes)
{
    copyTree(treeToCopy.rootPtr, rootPtr);
}

BST & BST::operator=(const BST & right)
{
    totalNodes = right.totalNodes;
    destroyTree(rootPtr);
    copyTree(right.rootPtr, rootPtr);
    return *this;
}

BST::~BST()
{
    destroyTree(rootPtr);
    totalNodes = 0;
}

/*
* Checks if tree is empty and returns the corresponding boolean.
*/
bool BST::isEmpty() const
{
    return rootPtr == nullptr;
}

/*
* Finds the height of a BST and returns it.
*/
int BST::getHeight(BSTNode *treePtr) const
{
    if (treePtr == nullptr)
        return 0;
    return getHeightHelper(treePtr);
}

/*
* Calculates BST height by recursively going into right and left subtrees adding 1 at each step.
*/
int BST::getHeightHelper(BSTNode * nodePtr) const
{
    if (nodePtr == nullptr) {
        return 0;
    }
    return 1 + max(getHeightHelper(nodePtr->leftChildPtr), getHeightHelper(nodePtr->rightChildPtr));
}

/*
* Inserts the key into the BST.
*/
void BST::insertItem(int key)
{
    insertItemAux(rootPtr, key);
}

/*
* Delets node containing the key from BST.
*/
void BST::deleteItem(int key)
{
    deleteItemAux(rootPtr, key);
}

/*
* Retrieves the node containing the key.
*/
BSTNode* BST::retrieveItem(int key)
{    
    BSTNode* retNode = retrieveItemAux(rootPtr, key);
    if (retNode != nullptr && retNode->getItem() != key) {
        std::cout << "404 - Node Not Found!" << std::endl;
        return nullptr;
    }
    return retNode;
}

/*
* Recursively traverses the tree in inorder fashion and returns the sorted values in an array.
*/
void BST::inorder(BSTNode * treePtr, int *arr, int & index) const
{
    if (treePtr != nullptr) {
        int item = treePtr->getItem();

        inorder(treePtr->leftChildPtr, arr, index);
        arr[index++] = item;
        inorder(treePtr->rightChildPtr, arr, index);
    }
}

/*
* Initializes return array and calls the inorder function to perform the traversal.
*/
int * BST::inorderTraversal(int & length)
{
    length = totalNodes;
    int *arr = new int[length];
    int index = 0;
    inorder(rootPtr, arr, index);
    return arr;
}

/*
* Recursively goes to the minimum number of nodes that span the sequence and adds them to an array.
*/
void BST::inorderContain(BSTNode * treePtr, int *arr, int *seq, int length, int & index) const
{
    if (treePtr != nullptr) {
        int item = treePtr->getItem();
        std::cout << item << " ";
        
        if (seq[0] < treePtr->getItem())
            inorderContain(treePtr->leftChildPtr, arr, seq, length, index);

        if (item >= seq[0] && item <= seq[length-1])
            arr[index++] = item;

        if (treePtr->getItem() < seq[length - 1]) {
            inorderContain(treePtr->rightChildPtr, arr, seq, length, index);
        }
    }
}

/*
* Checks if the given sequence is contained in an inorder fashion in the BST.
*/
bool BST::containsSequence(int * seq, int length)
{
    int *arr = new int[totalNodes];
    int index = 0;
    inorderContain(rootPtr, arr, seq, length, index);
    std::cout << std::endl;

    bool ret = true;
    for (int i = 0; i < length; i++) {
        if (arr[i] != seq[i]) {
            ret = false;
            break;
        }
    }

    delete[] arr;
    return ret;
}

/*
* Recursively counts the number of nodes till the given BST level.
*/
void BST::countNodesHelper(BSTNode* treePtr, int level, int currLevel, int & numberOfNodes) {
    if (treePtr != nullptr && level != 1) {
        if (currLevel < level){
            ++numberOfNodes;
            ++currLevel;
            countNodesHelper(treePtr->leftChildPtr, level, currLevel, numberOfNodes);
            countNodesHelper(treePtr->rightChildPtr, level, currLevel, numberOfNodes);
        }
    }
}

/*
* Counts the number of nodes at or below the given BST level.
*/
int BST::countNodesDeeperThan(int level)
{
    int nodesBeforeLevel = 0;
    countNodesHelper(rootPtr, level, 1, nodesBeforeLevel);
    return totalNodes - nodesBeforeLevel;
}

/*
* Helper function to recursively return the height of the BST if it was made balanced by deleting the min no of nodes.
*/
void BST::maxBalancedHeightHelper(BSTNode *treePtr, int & height)
{
    if (treePtr->leftChildPtr != nullptr && treePtr->rightChildPtr != nullptr) {
        int left = getHeight(treePtr->leftChildPtr);
        int right = getHeight(treePtr->rightChildPtr);
        int diff = left - right;

        if (std::abs(diff) > 1) {
            int higher = max(left,right);
            int lower = min(left, right);
            while (higher - lower > 1) {
                higher--;
            }
            height += higher;
        }
        else if (diff >= 0) {
            ++height;
            maxBalancedHeightHelper(treePtr->leftChildPtr, height);
        }
        else {
            ++height;
            maxBalancedHeightHelper(treePtr->rightChildPtr, height);
        }
    }
    else {
        ++height;
    }
}

/*
* Returns wha would be the height of the BST if it was made balanced by deleting the min no of nodes.
*/
int BST::maxBalancedHeight()
{
    int height = 1;
    maxBalancedHeightHelper(rootPtr, height);
    return height;
}


/*
* Retrieves the node corresponding to the key using binary search.
*/
BSTNode* BST::retrieveItemAux(BSTNode * treePtr, int key)
{
    BSTNode* retNode = nullptr;
    if (treePtr == nullptr)
        retNode = nullptr;
    else if (key == treePtr->getItem()) {
        retNode = treePtr;
    }
    else if (key < treePtr->getItem()) {
        retNode = retrieveItemAux(treePtr->leftChildPtr, key);
    }
    else {
        retNode = retrieveItemAux(treePtr->rightChildPtr, key);
    }
    return retNode;
}

/*
* Inserts the key by finding the place to insert using binary search.
*/
void BST::insertItemAux(BSTNode *& treePtr, const int & key)
{
    if (treePtr == nullptr) {
        treePtr = new BSTNode(key, nullptr, nullptr);
        ++totalNodes;
    }
    else if (key < treePtr->getItem()) {
        insertItemAux(treePtr->leftChildPtr, key);
    }
    else {
        insertItemAux(treePtr->rightChildPtr, key);
    }
}

/*
* Finds the node to delete if it exists and then calls the deleteNodeItemMethod.
*/
void BST::deleteItemAux(BSTNode *& treePtr, int searchKey)
{
    if (treePtr == nullptr)
        std::cout << "Node doesn't exist!" << std::endl;
    else if (treePtr->getItem() == searchKey) {
        deleteNodeItem(treePtr);
        --totalNodes;
    }
    else if (treePtr->getItem() > searchKey)
        deleteItemAux(treePtr->leftChildPtr, searchKey);
    else
        deleteItemAux(treePtr->rightChildPtr, searchKey);
}

/*
* Deletes the given BST node from the BST.
*/
void BST::deleteNodeItem(BSTNode *& treePtr)
{
    BSTNode* delPtr;
    key replacementItem;

    if (treePtr->leftChildPtr == nullptr && treePtr->rightChildPtr == nullptr) {
        delete treePtr;
        treePtr = nullptr;
    }
    else if (treePtr->leftChildPtr == nullptr) {
        delPtr = treePtr;
        treePtr = treePtr->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }
    else if (treePtr->rightChildPtr == nullptr) {
        delPtr = treePtr;
        treePtr = treePtr->leftChildPtr;
        delPtr->leftChildPtr = nullptr;
        delete delPtr;
    }
    else {
        processLeftMost(treePtr->rightChildPtr, replacementItem);
        treePtr->item = replacementItem;
    }
}

/*
* Finds the leftmost key of the right subtree of the node to delete.
*/
void BST::processLeftMost(BSTNode *& treePtr, key & item)
{
    if (treePtr->leftChildPtr == nullptr) {
        item = treePtr->getItem();
        BSTNode *delPtr = treePtr;
        treePtr = treePtr->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
        delPtr = nullptr;
    }
    else {
        processLeftMost(treePtr->leftChildPtr, item);
    }
}

/*
* Copies the nodes of the given tree to create a new tree.
*/
void BST::copyTree(BSTNode * treePtr, BSTNode *& newTreePtr) const
{
    if (treePtr != nullptr) {
        newTreePtr = new BSTNode(treePtr->getItem(), nullptr, nullptr);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
    else {
        newTreePtr = nullptr;
    }
}
/*
* Deletes all tree nodes.
*/
void BST::destroyTree(BSTNode *& treePtr)
{
    if (treePtr != nullptr) {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = nullptr;
    }
}