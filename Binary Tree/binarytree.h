/* Milena Zlaticanin
   Z1847022
   CIS 340.1
   
   I certify that this is my own work and where appropriate an extension
   of the starter code provided for the assignment.
*/

#ifndef H_BINARYTREE
#define H_BINARYTREE

#include "node.h"

template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

typedef enum {left_side, right_side } SIDE;

SIDE rnd(){ 
    return rand()%2 ? right_side : left_side;
}// End of rnd()

// Public
template <class T> BinaryTree<T>::BinaryTree()
{
  root = nullptr;
}

// Recursive call into private of size
template <class T> unsigned BinaryTree<T>::getSize() const
{
  return _getSize(root);
}

// Recursive call into private of height
template <class T> unsigned BinaryTree<T>::getHeight() const
{
  return _getHeight(root);
}

// Recursive call into private of insert
template <class T> void BinaryTree<T>::Insert(const T& j)
{
  return _Insert(root, j);
}

// Recursive call into private of inorder
template <class T> void BinaryTree<T>::Inorder(void(*k)(const T&))
{
  return _Inorder(root, k);
}


// Private
// Calling itself so it can count each node in the tree
template <class T> unsigned BinaryTree<T>::_getSize(Node<T> *N) const 
{
  if(N != nullptr)
    {
      int leftCount = _getSize(N->left);
      int rightCount = _getSize(N->right) + 1;

      return(leftCount + rightCount);
    }
  else
    return 0;
} 

// Returning the height of the tree by calling the subtree that is longer
template <class T> unsigned BinaryTree<T>::_getHeight(Node<T> *N) const
{
  if(N != nullptr)
    {
      int leftDepth = _getHeight(N->left) + 1;
      int rightDepth = _getHeight(N->right) + 1;

      if(rightDepth < leftDepth) return(leftDepth);
	  return(rightDepth);
    }
  else
    return 0;
}

// Inserting the node j in the tree
template <class T> void BinaryTree<T>::_Insert(Node<T> *&N, const T& j)
{
  if(N != nullptr) // if the tree is not empty, insert the node j in the tree
    {
      SIDE whichSide = rnd();
      if(whichSide != left_side)
	_Insert(N->right, j);
      else
	_Insert(N->left, j);
    }
  else // if the tree is empty, create a new node that will be the root
    {
      N = new Node<T>(j);
      return;
    }
}

// Sorting a tree using recursion and using inorder traversal (left, node, right)
template <class T> void BinaryTree<T>::_Inorder(Node<T> *N, void (*order)(const T&))
{
  if(N != nullptr) 
    {
      _Inorder(N->left, order);
      order(N->data);
      _Inorder(N->right, order);
    }
  else
    return;
}

#endif // End of H_BINARYTREE
