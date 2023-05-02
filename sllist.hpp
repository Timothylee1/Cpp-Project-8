/******************************************************************************
\File sllist.hpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Interface/Implementation Methodology with Linked Lists
\Par Programming Lab #4
\Date 06-02-2022

  \Brief
   The aim of this lab is to apply class lectures on linked lists, abstraction, 
   encapsulation, and interface/implementation methodology to implement a 
   singly-linked list Abstraction Data Type (ADT) sllist. A singly-linked list 
   is a group of dynamically allocated elements, each of type node , that are 
   connected to each other through pointers. Although the ultimate goal of an 
   ADT such as sllist is to allow clients to encapsulate any kind of data in a 
   node , type node for this lab will encapsulate only an int value. This 
   program performs to how certain functions in the list headers where a node 
   is created and data is assigned to it. That node then points to the next
   node and so on so forth till the last node contains data and points to a 
   nullptr. This list is dynamically allocated with new and deleted once deemed
   unnecessary. It can append a node at the front, back or else where in the 
   list of nodes. This program can also be used to find certain values or 
   remove nodes.
  
  - data(param1)
      Takes a pointer to the structure node and returns an int of the member
      named value in the node.
   
  - data(param1, param2)
      Takes a pointer to the structure node and a new value to modify an int of
      the member named value in the node. This function does not return 
      anything.
   
  - next
      Takes a pointer to the structure node and returns a pointer to the 
      next structure node.
   
  - const* next
      Takes a const pointer to the structure node and returns a pointer to the 
      next structure node. An overload of the function next.
   
  - construct
      Used to construct and return a new pointer to the structure sllist.
   
  - push_front
      To create a new node by calling create_node function and setting the 
      new node as the starting node.
   
  - size
      Counts the size of the sllist structure pointer and returns the count.
  
  - destruct
      Deletes the nodes present in the pointer to the struct sllist before
      deleting the pointer itself. This frees up memory and prevents memory
      leaks.

  - empty
      A boolean expression that returns true if the pointer to the struct
      sllist is empty, else false.
      
  - remove_first
      Deletes the nodes present in the pointer to the struct sllist if the
      element is the same as the param value. After deletion, the node 
      member next needs to point to the next available node, else it points
      the nullptr. If struct pointer is empty or none of the elements match
      the param value, no deletion is required.

  - push_back
      To create a new node by calling create_node function and setting the 
      new node as the last node. This is done by first checking if there are
      nodes present. If there are none, use create_node and have the pointer
      param of the sllist struct node member point to it. If there are 
      existing nodes, use create_node and have the last node point to it.

  - front
      To return a pointer to the first element of the list or nullptr if the 
      list has zero elements. 
 
  - const* front
      To return a pointer to the first element of the list or nullptr if the 
      list has zero elements. An overload of the function front.
 
  - find
      Returns a pointer to the first element in the list pointed to by 
      parameter ptr_sll whose data is equal to the second parameter value.
      Returns a nullptr if none are found.
 
  - insert
      Inserts a node with the data equal to the parameter value at the 
      index as denoted by the parameter position. Insertion to be made to 
      the list. If the position is outside the number of nodes present, a
      new node is to be created and added to the back of the list.
      E.g. 0 2 97 85 ; insert 5 to position 2
           0 2  5 97 85 ; insert 89 to position 99
           0 2  5 97 85 89

******************************************************************************/
#include <cstddef>

namespace hlp2 {
    // forward declaration of
    struct node;
    struct sllist;

    // interface to individual elements of singly-linked list
    int data(node const *p); // accessor to node's data
    void data(node *p, int newval); // mutator to node's data
    node* next(node *p); // pointer to successor node
    node const* next(node const *p); // pointer to successor node

    // interface declarations for singly-linked list...
    sllist* construct();
    void destruct(sllist *ptr_sll);
    bool empty(sllist const *ptr_sll);
    size_t size(sllist const *ptr_sll);
    void push_front(sllist *ptr_sll, int value);
    void push_back(sllist *ptr_sll, int value);
    void remove_first(sllist *ptr_sll, int value);
    void insert(sllist *ptr_sll, int value, size_t position);
    node* front(sllist *ptr_sll);
    node const* front(sllist const *ptr_sll);
    node* find(sllist const *ptr_sll, int value);
}