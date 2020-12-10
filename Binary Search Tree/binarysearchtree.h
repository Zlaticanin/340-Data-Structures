/* Milena Zlaticanin
   Z1847022
   CIS 340.1
   
   I certify that this is my own work and where appropriate an extension
   of the starter code provided for the assignment.
*/

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "binarytree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>

{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

// Public
// The Insert() function inserts a node with the data value x in the tree.
template <class T> void BinarySearchTree<T>::Insert(const T &x)
{
  return _Insert(this->root, x);
}

// Search() function, x is the data value of a leaf to be searched for. If the search is successful, the Search() function returns true; otherwise, it returns false.
template <class T> bool BinarySearchTree<T>::Search(const T &x) const
{
  return _Search(this->root, x);
}

// Remove() function first calls the Search() function to determine the result of the search for a leaf with the data value x, and if the search is successful, then it calls _Remove()
template <class T> bool BinarySearchTree<T>::Remove(const T &x)
{
  if(Search(x)) // call the search to determine the leaf result with data value x
    {
      _Remove(this->root, x); // if successful, remove
      return true;
    }
  else return false; // if not successful, false
}

// Private
template <class T> void BinarySearchTree<T>::_Insert(Node<T> *&No, const T& x)
{
  if(No != nullptr)
    {
      if(x > No->data)
	_Insert(No->right, x); // insert x into the right subtree
      else if(x < No->data)
	_Insert(No->left, x); // insert x into the left subtree
    }
  else
    {
      No = new Node<T>(x); // create a new node
      return;
    }
}

template <class T> bool BinarySearchTree<T>::_Search(Node<T> *No, const T& x) const
{
  if(No != nullptr)
    {
      if(x > No->data)
	return _Search(No->right, x); // check right subtree, and return the search
      else if(x < No->data)
	return _Search(No->left, x); // check left subtree, and return the search

      if(_Leaf(No) == true) return true; // check if the node is a leaf
      return false;
    }
  else return false;
}

template <class T> void BinarySearchTree<T>::_Remove(Node<T> *&No, const T& x)
{
  if(x > No->data)
    _Remove(No->right, x); // if x is located on the right subtree, then remove
  else if(x < No->data)
    _Remove(No->left, x); // if x is located on the left subtree, then remove
  else
    No = nullptr; // else tree is empty
}

template <class T> bool BinarySearchTree<T>::_Leaf(Node<T> *node) const
{
  // in order for a node to be a leaf, it can't have children
  if(node->right != nullptr) return false; // if right node is not a leaf, return false
  else if(node->left != nullptr) return false; // if left node is not a leaf, return false
  else return true; // if node is a leaf, return true
}

#endif // End of BINARYSEARCHTREE_H_
