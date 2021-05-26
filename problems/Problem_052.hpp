#pragma once

/* HARD
Implement an LRU (Least Recently Used) cache.
It should be able to be initialized with a cache size n,
and contain the following methods:

  set(key, value): sets key to value. If there are already n items in
    the cache and we are adding a new item, then it should also remove
    the least recently used item.

  get(key): gets the value at key. If no such key exists, return null.

Each operation should run in O(1) time.
*/

#include <map>
#include <string>

struct LLNode
{
  std::string key;
  std::string val;
  LLNode *    prev;
  LLNode *    next;

  LLNode( std::string _key, std::string _val )
  {
    key  = _key;
    val  = _val;
    prev = NULL;
    next = NULL;
  }
};

struct LinkedList
{
  LLNode * head;
  LLNode * tail;

  LinkedList()
  {
    // dummy nodes
    head       = new LLNode( "", "head" );
    tail       = new LLNode( "", "tail" );
    // set up head <-> tail
    head->next = tail;
    tail->prev = head;
  }

  LLNode * get_head() { return head->next; }

  LLNode * get_tail() { return tail->prev; }

  void add( LLNode * node )
  {
    LLNode * prev = tail->prev;
    prev->next    = node;
    node->prev    = prev;
    node->next    = tail;
    tail->prev    = node;
  }

  void remove( LLNode * node )
  {
    LLNode * prev = node->prev;
    LLNode * nxt  = node->next;
    prev->next    = nxt;
    nxt->prev     = prev;
  }
};

struct LRUCache
{
  int                             n;
  std::map<std::string, LLNode *> dict;
  LinkedList                      list;

  LRUCache( int _n ) { n = _n; }

  void set( std::string key, std::string val )
  {
    if( dict.find( key ) != dict.end() ) { dict.erase( key ); }

    LLNode * node = new LLNode( key, val );
    list.add( node );
    dict[key] = node;
    if( dict.size() > n )
    {
      LLNode * head = list.get_head();
      list.remove( head );
      dict.erase( head->key );
    }
  }

  std::string get( std::string key )
  {
    if( dict.find( key ) != dict.end() )
    {
      LLNode * node = dict[key];
      // bump to the back of the list by removing and adding the node
      list.remove( node );
      list.add( node );
      return node->val;
    }
    return "";
  }
};