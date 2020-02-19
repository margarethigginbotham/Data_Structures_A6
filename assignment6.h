#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assignment5.h"

//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 6                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   March 22, 2018                                     //
//                                                                  //
//   FUNCTION:   Implements a derived class to represent a          //
//               binary search tree                                 //
//******************************************************************//

class BST : public binTree {
  public:
    BST() : binTree() {}
    void insert( int );
    bool search( int );
    bool remove( int );
    int sumLeftLeaves();

  private:
    void insert( Node*&, int );
    bool search( Node*&, int );
    bool remove( Node*&, int );
    int sumLeftLeaves(Node*&);
};

#endif
