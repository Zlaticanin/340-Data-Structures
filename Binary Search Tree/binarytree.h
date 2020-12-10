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
template <class T> unsigned BinaryTree<T>::_getSize(Node<T> *No) const 
{
  if(No != nullptr)
    {
      int leftCount = _getSize(No->left);
      int rightCount = _getSize(No->right) + 1;

      return(leftCount + rightCount);
    }
  else
    return 0;
} 

// Returning the height of the tree by calling the subtree that is longer
template <class T> unsigned BinaryTree<T>::_getHeight(Node<T> *No) const
{
  if(No != nullptr)
    {
      int leftDepth = _getHeight(No->left) + 1;
      int rightDepth = _getHeight(No->right) + 1;

      if(rightDepth < leftDepth) return(leftDepth);
	  return(rightDepth);
    }
  else
    return 0;
}

// Inserting the node j in the tree
template <class T> void BinaryTree<T>::_Insert(Node<T> *&No, const T& j)
{
  if(No != nullptr) // if the tree is not empty, insert the node j in the tree
    {
      SIDE whichSide = rnd();
      if(whichSide != left_side)
	_Insert(No->right, j);
      else
	_Insert(No->left, j);
    }
  else // if the tree is empty, create a new node that will be the root
    {
      No = new Node<T>(j);
      return;
    }
}

// Sorting a tree using recursion and using inorder traversal (left, node, right)
template <class T> void BinaryTree<T>::_Inorder(Node<T> *No, void (*order)(const T&))
{
  if(No != nullptr) 
    {
      _Inorder(No->left, order);
      order(No->data);
      _Inorder(No->right, order);
    }
  else
    return;
}

#endif // End of H_BINARYTREE
