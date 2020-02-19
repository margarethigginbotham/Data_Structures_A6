#ifndef ASSIGNMENT5
#define ASSIGNMENT5

//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 5                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   March 5, 2018                                      //
//                                                                  //
//   FUNCTION:   Implements classes to represent a binary tree      //
//               of integers                                        //
//******************************************************************//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

class binTree;
class BST;

class Node {
  friend class binTree;
  friend class BST;

  public:
    Node(int& data1, Node* left1 = NULL, Node* right1 = NULL){
      left = left1;
      right = right1;
      data = data1;
    }

  private:
    Node* left;
    Node* right;
    int data;
};

class binTree {
  public:
    binTree();				//default constructor
    virtual void insert(int);		//inserts a node in tree
    int height() const;			//returns height of tree
    unsigned size() const;		//returns size of tree
    void inorder(void(*)(int));		//inorder traversal
    void preorder(void(*)(int));	//preorder traversal
    void postorder(void(*)(int));	//postorder traversal

  protected:
    Node* root;				//root of tree

  private:				//private versions
    void insert(Node*&, int);
    int height(Node*) const;
    unsigned size(Node*) const;
    void inorder(Node*, void(*)(int));
    void preorder(Node*, void(*)(int));
    void postorder(Node*, void(*)(int));
};

#endif
