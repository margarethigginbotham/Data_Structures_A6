#include "assignment5.h"
#include "assignment6.h"

//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 6                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   March 22, 2018                                     //
//                                                                  //
//   FUNCTION:   Implements a derived class to represent a          //
//               binary search tree                                 //
//******************************************************************//

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////
//                          PUBLIC                            //
////////////////////////////////////////////////////////////////

/***************************************************************
void BST::insert(int x){
Use: Inserts an item in the tree
Parameters: 1. int x- Node's item
Returns: Nothing
***************************************************************/
void BST::insert(int x){
  insert(root, x);
}

/***************************************************************
bool BST::search(int x){
Use: Searches for an item in the tree
Parameters: 1. int x- Node's item
Returns: True if value is found, false if not found
***************************************************************/
bool BST::search(int x){
  return search(root, x);
}

/***************************************************************
bool BST::remove(int x){
Use: Removes an item in the tree
Parameters: 1. int x- Node's item
Returns: True if value is removed, false if not removed
***************************************************************/
bool BST::remove(int x){
  return remove(root, x);
}

/***************************************************************
int BST::sumLeftLeaves(){
Use: Returns the sum of values of left leaves
Parameters: None
Returns: int- Sum of the left leaves
***************************************************************/
int BST::sumLeftLeaves(){
  return sumLeftLeaves(root);
}

////////////////////////////////////////////////////////////////
//                          PRIVATE                           //
////////////////////////////////////////////////////////////////

/***************************************************************
void BST::insert(Node*& n, int x){
Use: Inserts an item in the tree
Parameters: 1. Node*& n- Binary tree node
            2. int x- Node's item
Returns: Nothing
***************************************************************/
void BST::insert(Node*& n, int x){
  if(n == NULL)
    n = new Node(x);

  else if (x < n -> data)
    insert(n -> left, x);

  else if (x > n -> data)
    insert(n -> right, x);

}

/***************************************************************
bool BST::search(Node*& n, int x){
Use: Searches for an item in the tree
Parameters: 1. Node*& n- Binary tree node
            2. int x- Node's item
Returns: True if value is found, false if not found
***************************************************************/
bool BST::search(Node*& n, int x){
  if(n == NULL)
    return false;

  else if(n -> data == x)
    return true;

  else if(n -> data > x)
    return search(n -> left, x);

  else if(n -> data < x)
    return search(n -> right, x);

  else
    return false;
}

/***************************************************************
bool BST::remove(Node*& n, int x){
Use: Removes an item in the tree
Parameters: 1. Node*& n- Binary tree node
            2. int x- Node's item
Returns: True if value is removed, false if value is not removed
***************************************************************/
bool BST::remove(Node*& n, int x){
  if(n == NULL)					//If n is empty
    return false;				//Stop

  else if(n -> data > x)			//If n's data is greater than x
    return remove(n -> left, x);		//Recursive call remove left

  else if(n -> data < x)			//If n's data is less than x
    return remove(n -> right, x);		//Recursive call remove right

  if(n -> left != NULL && n -> right != NULL){	//If n has two non empty children
    Node* pred = n -> left;			//Pred set to immediate predecessor

    while(pred -> right != NULL){
      Node* temp;
      temp = pred;
      pred = temp -> right;
    }

    n -> data = pred -> data;			//Copy pred's data to n
    return remove(n -> left, pred -> data);	//Recursive call to remove tree's left link, pred's data
  }
						//Else if n is a leaf
  else if(n -> left == NULL && n -> right == NULL){
    delete n;					//Delete n
    n = NULL;					//n = NULL
    return true;
  }
						//Else if n only has one child
  else if(n -> left != NULL || n->right != NULL){
    Node* temp = n;

    n = ((temp -> right == NULL) ? temp -> left : temp -> right);

    delete temp;

    return true;
  }

  return false;
}

/***************************************************************
int BST::sumLeftLeaves(Node*& n){
Use: Returns the sum of values of left leaves
Parameters: 1. Node*& n- Binary tree
Returns: int- Sum of the left leaves
***************************************************************/
int BST::sumLeftLeaves(Node*& n){
  int count = 0;

  if(n != NULL){
    count += sumLeftLeaves(n -> left);
    count += sumLeftLeaves(n -> right);

    if(n -> left != NULL && n -> right == NULL)
      count += n -> left -> data;
  }

  return count;
}
