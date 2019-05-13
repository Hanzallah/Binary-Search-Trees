/**
* Title: Binary Search Trees
* Author: Hanzallah Azim Burney
* ID: 21701829
* Section: 1
* Assignment: 2
* Description: Creates 3 BST's and calls their functions for testing.
*/

#include <iostream>
#include "BSTNode.h"
#include "BST.h"

int main() {

    std::cout << "------------------------First Tree----------------------------" << std::endl;
    BST bst;
    bst.insertItem(5);
    bst.insertItem(12);
    bst.insertItem(7);
    bst.insertItem(1);
    bst.insertItem(6);
    bst.insertItem(3);
    bst.insertItem(13);
    bst.insertItem(2);
    bst.insertItem(10);
    bst.insertItem(11);
    
    std::cout << "--> After Inserting All Elements (Inorder traversal)" << std::endl;
    int length;
    int* arr = bst.inorderTraversal(length);
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {1,2,3,5,6,7,13} Exists In Tree" << std::endl;
    int seq[] = {1,2,3,5,6,7,13};
    length = 7;
    int returnNum = bst.containsSequence(seq, length);
    if (returnNum == 0) {
        std::cout <<  "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {1,2,3,5,6,7,10} Exists In Tree" << std::endl;
    int seqa[] = { 1,2,3,5,6,7,10 };
    length = 7;
    returnNum = bst.containsSequence(seqa, length);
    if (returnNum == 0) {
        std::cout << "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }
    
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Max Balanced Height Of Tree: ";
    std::cout << bst.maxBalancedHeight() << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> After Deleting 2 Then 7 Then 12 (Inorder traversal)" << std::endl;
    bst.deleteItem(2);
    delete[] arr;
    arr = bst.inorderTraversal(length);
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bst.deleteItem(7);
    delete[] arr;
    arr = bst.inorderTraversal(length);
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bst.deleteItem(12);
    delete[] arr;
    arr = bst.inorderTraversal(length);
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    std::cout << "------------------------Second Tree----------------------------" << std::endl;
    BST bst2;
    bst2.insertItem(8);
    bst2.insertItem(4);
    bst2.insertItem(3);
    bst2.insertItem(1);
    bst2.insertItem(2);
    bst2.insertItem(7);
    bst2.insertItem(6);
    bst2.insertItem(5);
    bst2.insertItem(13);
    bst2.insertItem(12);
    bst2.insertItem(10);
    bst2.insertItem(15);
    bst2.insertItem(14);

    std::cout << "--> After Inserting All Elements (Inorder traversal)" << std::endl;
    int length2;
    int* arr2 = bst2.inorderTraversal(length2);
    for (int i = 0; i < length2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {4,5,6,8,10,12,13} Exists In Tree" << std::endl;
    int seq2[] = {4,5,6,8,10,12,13};
    length = 7;
    returnNum = bst2.containsSequence(seq2, length);
    if (returnNum == 0) {
        std::cout << "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {1,2,3,4,5,6} Exists In Tree" << std::endl;
    int seq3[] = {1,2,3,4,5,6};
    length = 6;
    returnNum = bst2.containsSequence(seq3, length);
    if (returnNum == 0) {
        std::cout << "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {10,12,13,15} Exists In Tree" << std::endl;
    int seq4[] = {10,12,13,15};
    length = 4;
    returnNum = bst2.containsSequence(seq4, length);
    if (returnNum == 0) {
        std::cout << "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {10,11,12} Exists In Tree" << std::endl;
    int seq5[] = {10,11,12};
    length = 3;
    returnNum = bst2.containsSequence(seq5, length);
    if (returnNum == 0) {
        std::cout << "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {1,2,3,4,5,6,7,8,10,12,13,14,15} Exists In Tree" << std::endl;
    int seq6[] = {1,2,3,4,5,6, 7, 8,10,12,13,14,15};
    length = 13;
    returnNum = bst2.containsSequence(seq6, length);
    if (returnNum == 0) {
        std::cout << "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {5,6,8} Exists In Tree" << std::endl;
    int seq7[] = {5,6,8};
    length = 3;
    returnNum = bst2.containsSequence(seq7, length);
    if (returnNum == 0) {
        std::cout << "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Check If Sequence {1,5,6,8,10} Exists In Tree" << std::endl;
    int seq8[] = {1,5,6,8,10};
    length = 5;
    returnNum = bst2.containsSequence(seq8, length);
    if (returnNum == 0) {
        std::cout << "The sequence does not exist!" << std::endl;
    }
    else {
        std::cout << "The sequence exists!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Number Of Nodes Equal or Deeper than Level 1: ";
    std::cout << bst2.countNodesDeeperThan(1) << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Number Of Nodes Equal or Deeper than Level 2: ";
    std::cout << bst2.countNodesDeeperThan(2) << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Number Of Nodes Equal or Deeper than Level 3: ";
    std::cout << bst2.countNodesDeeperThan(3) << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Number Of Nodes Equal or Deeper than Level 4: ";
    std::cout << bst2.countNodesDeeperThan(4) << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Max Balanced Height Of Tree: ";
    std::cout << bst2.maxBalancedHeight() << std::endl;

    std::cout << "------------------------Third Tree----------------------------" << std::endl;
    BST bst3;
    bst3.insertItem(42);
    bst3.insertItem(43);
    bst3.insertItem(35);
    bst3.insertItem(19);
    bst3.insertItem(14);
    bst3.insertItem(10);
    bst3.insertItem(27);
    bst3.insertItem(31);

    std::cout << "--> Max Balanced Height Of Tree: ";
    std::cout << bst3.maxBalancedHeight() << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "--> Retrieve 27: ";
    BSTNode* node = bst3.retrieveItem(27);
    if (node != nullptr)
        std::cout << node->getItem() << std::endl;

    delete[] arr;
    delete[] arr2;
    return 0;
}