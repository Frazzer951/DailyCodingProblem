/* MEDIUM
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or
ancestors are not locked.

Design a binary tree node class with the following methods:

is_locked, which returns whether the node is locked

lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it
and return true.

unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it
and return true. You may augment the node to add parent pointers or any other property you would like.

You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each
method should run in O(h), where h is the height of the tree.
*/

#include <iostream>

struct lbtNode
{
  int       value;
  int       lockedSubNodes;
  bool      locked;
  lbtNode * parent;
  lbtNode * left;
  lbtNode * right;

  lbtNode( int val )
  {
    value          = val;
    lockedSubNodes = 0;
    locked         = false;
    parent         = nullptr;
    left           = nullptr;
    right          = nullptr;
  }

  void setLeft( lbtNode * node )
  {
    left         = node;
    node->parent = this;
  }

  void setRight( lbtNode * node )
  {
    right        = node;
    node->parent = this;
  }

  [[nodiscard]] bool canLockUnlock() const
  {
    if( lockedSubNodes > 0 ) return false;

    auto * cur = parent;
    while( cur != nullptr )
    {
      if( cur->locked ) return false;
      cur = cur->parent;
    }
    return true;
  }

  bool lock()
  {
    if( canLockUnlock() )
    {
      locked = true;

      auto * cur = parent;
      while( cur != nullptr )
      {
        cur->lockedSubNodes++;
        cur = cur->parent;
      }

      return true;
    }
    return false;
  }

  bool unlock()
  {
    if( canLockUnlock() )
    {
      locked = false;

      auto * cur = parent;
      while( cur != nullptr )
      {
        cur->lockedSubNodes--;
        cur = cur->parent;
      }

      return true;
    }
    return false;
  }

  [[nodiscard]] bool isLocked() const { return locked; }
};