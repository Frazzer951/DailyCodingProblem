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
#include <utility>

struct LLNode
{
  std::string key;
  std::string val;
  LLNode *    prev;
  LLNode *    next;

  LLNode( std::string _key, std::string _val )
  {
    key  = std::move( _key );
    val  = std::move( _val );
    prev = nullptr;
    next = nullptr;
  }
};

struct LinkedList
{
  LLNode * head;
  LLNode * tail;

  LinkedList()
  {
    // dummy nodes
    head = new LLNode( "", "head" );
    tail = new LLNode( "", "tail" );
    // set up head <-> tail
    head->next = tail;
    tail->prev = head;
  }

  [[nodiscard]] LLNode * get_head() const { return head->next; }

  [[nodiscard]] LLNode * get_tail() const { return tail->prev; }

  void add( LLNode * node ) const
  {
    LLNode * prev = tail->prev;
    prev->next    = node;
    node->prev    = prev;
    node->next    = tail;
    tail->prev    = node;
  }

  static void remove( LLNode * node )
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

  void set( const std::string & key, std::string val )
  {
    if( dict.find( key ) != dict.end() ) { dict.erase( key ); }

    auto * node = new LLNode( key, std::move( val ) );
    list.add( node );
    dict[key] = node;
    if( dict.size() > n )
    {
      LLNode * head = list.get_head();
      LinkedList::remove( head );
      dict.erase( head->key );
    }
  }

  std::string get( const std::string & key )
  {
    if( dict.find( key ) != dict.end() )
    {
      LLNode * node = dict[key];
      // bump to the back of the list by removing and adding the node
      LinkedList::remove( node );
      list.add( node );
      return node->val;
    }
    return "";
  }
};