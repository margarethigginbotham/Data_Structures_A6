#include "assignment5.h"

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

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 12;

int mcount = 0;
int rcount = 0;

////////////////////////////////////////////////////////////////
//                          PUBLIC                            //
////////////////////////////////////////////////////////////////

/***************************************************************
binTree::binTree(){
Use: Default constructor
Parameters: None
Returns: Nothing
***************************************************************/
binTree::binTree(){
  root = NULL;
}

/***************************************************************
void binTree::insert(int x){
Use: Public version that inserts values when called
Parameters: 1. int x- Value to be inserted
Returns: Nothing
***************************************************************/
void binTree::insert(int x){
  insert(root, x);
}

/***************************************************************
int binTree::height() const{
Use: Public version that calculates the height when called
Parameters: None
Returns: 1. int- Height from the root
***************************************************************/
int binTree::height() const{
  return (height(root) + 1);
}

/***************************************************************
unsigned binTree::size() const{
Use: Public version that calculates the size when called
Parameters: None
Returns: 1. unsigned- Size of the root
***************************************************************/
unsigned binTree::size() const{
  return size(root);
}

/***************************************************************
void binTree::inorder(void(*p)(int)){
Use: Public version that calls the private version of inorder
     when called
Parameters: 1. void(*p)(int)- Current value
Returns: Nothing
***************************************************************/
void binTree::inorder(void(*p)(int)){
  inorder(root, p);
}

/***************************************************************
void binTree::preorder(void(*p)(int)){
Use: Public version that calls the private version of preorder
     when called
Parameters: 1. void(*p)(int)- Current value
Returns: Nothing
***************************************************************/
void binTree::preorder(void(*p)(int)){
  preorder(root, p);
}

/***************************************************************
void binTree::postorder(void(*p)(int)){
Use: Public version that calls the private version of postorder
     when called
Parameters: 1. void(*p)(int)- Current value
Returns: Nothing
***************************************************************/
void binTree::postorder(void(*p)(int)){
  postorder(root, p);
}

////////////////////////////////////////////////////////////////
//                          PRIVATE                           //
////////////////////////////////////////////////////////////////

/***************************************************************
void binTree::insert(Node*& r, int x){
Use: Private version that inserts Node r with the value x in
     a binary tree
Parameters: 1. Node*& r- Pointer reference to a node
            2. int x- Value to be inserted
Returns: Nothing
***************************************************************/
void binTree::insert(Node*& r, int x){
  if(r == NULL)
    r = new Node(x);

  else{
    int leftHeight = height(r->left);
    int rightHeight = height(r->right);

    if(rightHeight < leftHeight)
      insert(r->right, x);

    else
      insert(r->left, x);
  }

}

/***************************************************************
int binTree::height(Node* r) const{
Use: Private version that calculates the heights of the left and
     right sub trees and treturns the greater value
Parameters: 1. Node* r- Pointer to a node
Returns: 1. int- Height of the right subtree
         2. int- Height of the left subtree
***************************************************************/
int binTree::height(Node* r) const{
  if(r == NULL)
    return -1;

  else{
    int leftHeight = height(r->left);
    int rightHeight = height(r->right);

    if(rightHeight > leftHeight)
      return 1 + rightHeight;

    else
      return 1 + leftHeight;
  }

}

/***************************************************************
unsigned binTree::size(Node* r) const{
Use: Private version that calculates the size of the binary tree
Parameters: 1. Node* r- Pointer to a node
Returns: 1. Size of the tree
         2. If empty, return 0
***************************************************************/
unsigned binTree::size(Node* r) const{
  if(r != NULL)
    return 1 + size(r->left) + size(r->right);

  else
    return 0;
}

/***************************************************************
void binTree::inorder(Node* r, void(*p)(int)){
Use: Public version that traverses the tree using inorder
Parameters: 1. Node* r- Pointer to a node
            2. void(*p)(int) - Function pointer to int value p
Returns: Nothing
***************************************************************/
void binTree::inorder(Node* r, void(*p)(int)){
  if(r != NULL){
    inorder(r->left, p);
    p(r->data);
    inorder(r->right, p);
  }

}

/***************************************************************
void binTree::preorder(Node* r, void(*p)(int)){
Use: Public version that traverses the tree using preorder
Parameters: 1. Node* r- Pointer to a node
            2. void(*p)(int)- Function pointer to int value p
Returns: Nothing
***************************************************************/
void binTree::preorder(Node* r, void(*p)(int)){
  if(r != NULL){
    p(r->data);
    preorder(r->left, p);
    preorder(r->right, p);
  }

}

/***************************************************************
void binTree::postorder(Node* r, void(*p)(int)){
Use: Public version that traverses the tree using preorder
Parameters: 1. Node* r- Pointer to a node
            2. void(*p)(int)- Function pointer to int value p
Returns: Nothing
***************************************************************/
void binTree::postorder(Node* r, void(*p)(int)){
  if(r != NULL){
    postorder(r->left, p);
    postorder(r->right, p);
    p(r->data);
  }

}

void display(int d){
  if(mcount < MAX_COUNT){
    cout << setw(WIDTH) << d;
    mcount++;
    rcount++;

    if(rcount == ROW_SIZE){
      cout << endl;
      rcount = 0;
    }

  }

}

//#define BINTREE_MAIN
#ifdef BINTREE_MAIN

//MAIN
int main() {
  vector<int> v(MAX_SIZE);
  for (int i=1; i<MAX_SIZE; i++)
    v[i] = i;

  random_shuffle( v.begin(), v.end() );

  binTree bt;
  vector<int>::iterator it;
  for (it=v.begin(); it!=v.end(); it++)
    bt.insert( *it );

  cout << "Height: " << bt.height() << endl;
  cout << "Size: " << bt.size() << endl;
  cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
  mcount = rcount = 0;
  bt.inorder( display );
  cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
  mcount = rcount = 0;
  bt.preorder( display );
  cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
  mcount = rcount = 0;
  bt.postorder( display );

  cout << endl;
  return 0;
}

#endif

