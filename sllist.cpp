/******************************************************************************
\File sllist.cpp
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
   
  - create_node
      Creates a node on heap and initializes it with data and pointer to 
      successor. Returns a newly created node. This function is defined in
      an anonymous namespace.
   
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

    struct node {
        int value;  //data portion
        node *next; //pointer portion
    };

    struct sllist {
        node *head;
    };

    /*************************************************************************/
    /*! 
    \brief
        Takes a pointer to the structure node and returns an int of the member
        named value in the node.

    \param p
        Pointer to the structure node. Used to point to and return the int 
        of the member named value in the node.
    */    
    /*************************************************************************/
    int data(node const *p) { 
        return p->value; 
    }

    /*************************************************************************/
    /*! 
    \brief
        Takes a pointer to the structure node and a new value to modify an int 
        of the member named value in the node. This function does not return 
        anything.

    \param p
        Pointer to the structure node. Used to point to and modify the int 
        of the member named value in the node.
    */    
    /*************************************************************************/
    void data(node *p, int newval) { 
        p->value = newval; 
    }

    /*************************************************************************/
    /*! 
    \brief
        Takes a pointer to the structure node and returns a pointer to the 
        next structure node.

    \param p
        Pointer to the structure node. Used to point to and return a pointer 
        to the next structure node.
    */    
    /*************************************************************************/
    node* next(node *p) { 
        return p->next; 
    }

    /*************************************************************************/
    /*! 
    \brief
        Takes a const pointer to the structure node and returns a pointer to 
        the next structure node.

    \param p
        Pointer to the structure node. Used to point to and return a pointer 
        to the next structure node.
    */    
    /*************************************************************************/
    node const* next(node const *p) { 
        return p->next; 
    }

    
    namespace {

    /*************************************************************************/
    /*! 
    \brief
        Creates a node on heap and initializes it with data and pointer to 
        successor. Returns a newly created node.

    \param value
        An int to be assigned to the member of the node named value.

    \param next
        Pointer to the structure node. Used to point to the the given next node
        and dynamically allocate memory using new.
    */    
    /*************************************************************************/
        hlp2::node* create_node(int value, hlp2::node* next) {
            return new hlp2::node {value, next};
        }
    }

    /*************************************************************************/
    /*! 
    \brief
        Used to construct and return a new pointer to the structure sllist.
    */    
    /*************************************************************************/
    sllist* construct() {
        return new sllist {nullptr};
    }

    /*************************************************************************/
    /*! 
    \brief
        To create a new node by calling create_node function and setting the 
        new node as the starting node.

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 

    \param value
        An int to be assigned to the member of the node named value.
    */    
    /*************************************************************************/
    void push_front(sllist *ptr_sll, int value) {
        ptr_sll->head = create_node(value, ptr_sll->head);
        //data(ptr_sll->head, value);
    }

    /*************************************************************************/
    /*! 
    \brief
        Counts the size of the sllist structure pointer and returns the count.

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 
    
    \param cnt
        The counter of the number of elements present int the pointer. 
        Essentially counts the number of nodes present. The data inside this 
        variable is to be returned.

    \param head
        A pointer to the member head in the ptr_sll pointer for ease of
        reference and to reduce width of code.
    */    
    /*************************************************************************/
    size_t size(sllist const *ptr_sll) {
        size_t cnt {};
        for (node *head = ptr_sll->head; head; head = next(head)) {
            ++cnt;
        }
        return cnt;
    }

    /*************************************************************************/
    /*! 
    \brief
        Deletes the nodes present in the pointer to the struct sllist before
        deleting the pointer itself. This frees up memory and prevents memory
        leaks.

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 
    
    \param current
        A pointer to the member head in the ptr_sll pointer for ease of
        reference and to reduce width of code.

    \param next1
        A pointer to the next member head in the ptr_sll pointer for ease of
        reference and to reduce width of code. Allows for a reference point 
        such that the current node can be deleted.
    */    
    /*************************************************************************/
    void destruct(sllist *ptr_sll) {

        node *current = ptr_sll->head;
        node *next1 = nullptr;

        if (current == nullptr) {
            delete current;
            delete ptr_sll;
            return;
        }

        while (current) {
            next1 = next(current);
            delete current;
            current = next1; 
        }
        delete ptr_sll;
    }

    /*************************************************************************/
    /*! 
    \brief
        A boolean expression that returns true if the pointer to the struct
        sllist is empty, else false.

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 
    */    
    /*************************************************************************/
    bool empty(sllist const *ptr_sll) {
        return size(ptr_sll) ? false : true;
    }

    /*************************************************************************/
    /*! 
    \brief
        Deletes the nodes present in the pointer to the struct sllist if the
        element is the same as the param value. After deletion, the node 
        member next needs to point to the next available node, else it points
        the nullptr. If struct pointer is empty or none of the elements match
        the param value, no deletion is required.

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 

    \param value
        An int to be checked against to the member of the node named value.

    \param temp
        A pointer to the member head in the ptr_sll pointer for ease of
        reference and to reduce width of code. This pointer is to point
        to the next node after the first node has been checked to not 
        contain the param value. Allows for a reference point such that this 
        node can be deleted.

    \param prev
        A pointer to the previous member head in the ptr_sll pointer for ease 
        of reference and to reduce width of code. 
    */    
    /*************************************************************************/
    void remove_first(sllist *ptr_sll, int value) {
        if (empty(ptr_sll)) 
            return;

        node *temp = ptr_sll->head;
        node *prev = nullptr;
        if (data(temp) == value) {
            ptr_sll->head = next(temp);
            delete temp;
            return;
        }
        
        while (temp != nullptr && (data(temp) != value) ) {
            prev = temp;
            temp = next(temp);
        }
        
        if (temp == nullptr) 
            return;

        prev->next = next(temp);

        delete temp;
    }

    /*************************************************************************/
    /*! 
    \brief
        To create a new node by calling create_node function and setting the 
        new node as the last node. This is done by first checking if there are
        nodes present. If there are none, use create_node and have the pointer
        param of the sllist struct node member point to it. If there are 
        existing nodes, use create_node and have the last node point to it.

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 

    \param value
        An int to be assigned to the member of the node named value.

    \param lastnode
        A pointer initialized to point to the member head in the ptr_sll 
        pointer for ease of reference and to reduce width of code. This 
        pointer is to point to the last node and then to the new node after
        its creation.
    */    
    /*************************************************************************/
    void push_back(sllist *ptr_sll, int value) {
        //if ptr_sll is empty
        if (ptr_sll->head == nullptr) {
            ptr_sll->head = create_node(value, nullptr);
            //data(ptr_sll->head, value);
            return;
        } 
        
        node *lastnode {ptr_sll->head};
        while (lastnode->next) {
            lastnode = next(lastnode);
        }
        lastnode->next = create_node(value, nullptr);
        //data(lastnode, value);
    }

    /*************************************************************************/
    /*! 
    \brief
        To return a pointer to the first element of the list or nullptr if the 
        list has zero elements. 

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 
    */    
    /*************************************************************************/
    node* front(sllist *ptr_sll) {
        if (empty(ptr_sll)) {
            return nullptr;
        }
        return ptr_sll->head;
    }

    /*************************************************************************/
    /*! 
    \brief
        To return a pointer to the first element of the list or nullptr if the 
        list has zero elements. An overload of the function front.

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 
    */    
    /*************************************************************************/
    node const* front(sllist const *ptr_sll) {
        if (empty(ptr_sll)) {
            return nullptr;
        }
        return ptr_sll->head;
    }

    /*************************************************************************/
    /*! 
    \brief
        Returns a pointer to the first element in the list pointed to by 
        parameter ptr_sll whose data is equal to the second parameter value.
        Returns a nullptr if none are found.

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 

    \param value
        An int to be checked against the member of the node named value.
    */    
    /*************************************************************************/
    node* find(sllist const *ptr_sll, int value) {
        for (node *current = ptr_sll->head; current; current = next(current)) {
            if (data(current) == value)
                return current;
        }
        return nullptr;
    }

    /*************************************************************************/
    /*! 
    \brief
        Inserts a node with the data equal to the parameter value at the 
        index as denoted by the parameter position. Insertion to be made to 
        the list. If the position is outside the number of nodes present, a
        new node is to be created and added to the back of the list.
        E.g. 0 2 97 85 ; insert 5 to position 2
             0 2  5 97 85 ; insert 89 to position 99
             0 2  5 97 85 89

    \param ptr_sll
        Pointer to the structure sllist. sllist contains a pointer to the 
        structure node. 

    \param value
        An int to be assigned to the member of the node named value.

    \param position
        The index for which the new node is to be placed in the list.

    \param cnt
        The counter of the number of elements present int the pointer. 
        Essentially counts the number of nodes present. The data inside this 
        variable is to be returned.

    \param prevnode
        A pointer to the previous member head in the ptr_sll pointer for ease 
        of reference and to reduce width of code. To eventually point to the 
        new node.
    */    
    /*************************************************************************/
    void insert(sllist *ptr_sll, int value, size_t position) {
        size_t cnt = size(ptr_sll);
        if (position == 0) {
            //front
           push_front(ptr_sll, value);
        }
        else if (position > cnt) {
            //last
            push_back(ptr_sll, value);
        }
        else {
            //inbetween
            node *prevnode = ptr_sll->head;
            for (size_t i{1}; i < position; i++) {
                prevnode = next(prevnode); 
            }
            node *newnode = create_node(value, next(prevnode));
            prevnode->next = newnode;
        }
    }
}