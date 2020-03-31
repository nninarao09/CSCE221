#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexceptions.h"
#include"queueheader.h"
#include <algorithm>
#include <iostream>
using namespace std;       

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( ) : root{ nullptr }
    { }

    /**
     * Copy constructor
     */
    BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
    { root = clone( rhs.root );  }

    /**
     * Move constructor
     */
    BinarySearchTree( BinarySearchTree && rhs ) : root{ rhs.root }
    { rhs.root = nullptr; }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    { makeEmpty( );  }

    /**
     * Copy assignment
     */
    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move assignment
     */
    BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        std::swap( root, rhs.root );       
        return *this;
    }
    
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    { return contains( x, root );   }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    void preorder ( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            preorder( root, out );
    }


    int max_depth () const
    {
        if( isEmpty( ) )
            return 0;
        else
            max_depth( root);
    }

    int min_depth () const
    {
        if( isEmpty( ) )
            return 0;
        else
            min_depth( root);
    }

    int diameter () const
    {
        if( isEmpty( ) )
            return 0;
        else
            diameter( root);
    }

    void levelorder ( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            levelorder( root, out );
    }

    void LCA(int x, int y, ostream & out = cout) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            LCA( root, x, y, out );
    }


    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    { makeEmpty( root ); }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {  insert( x, root );  }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {  insert( std::move( x ), root ); }
    
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    { remove( x, root );  }

    void remove_left( const Comparable & x )
    { remove_left( x, root ); }



  private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode
            ( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
          : element{ theElement }, left{ lt }, right{ rt } { }
        
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
          : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
    };

    BinaryNode *root;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        else
            ;  // Duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Q 2.6
     * Add the code in below function that performs remove right 
     * operation on the Binary tree.
     */
    void remove_left( const Comparable & x, BinaryNode * & t )
    {
       if( t == nullptr )
            return;   // Item not found; do nothing
        if( x > t->element )
            remove( x, t->right );
        else if( t->element < x )
            remove( x, t->left );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMax( t->left )->element;
            remove( t->element, t->left );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->right != nullptr ) ? t->right : t->left;
            delete oldNode;
        }
    }


    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
    }



    /**
     * Q 2.2
     * Add the code in below function that will perform the 
     * preorder traversal on the Binary tree and print it.
     */
    void preorder ( BinaryNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
			out << t->element << endl;
            preorder( t->left, out );
            preorder( t->right, out );
        }
    }

    /**
     * Q 2.4
     * Add the code in below function that will evaluate the 
     * maximum depth of the Binary tree and return the integer value.
     */
    int max_depth (BinaryNode *t ) const{
		

        if(t == NULL){
			return 0;
		}
	
		int countLeft = max_depth(t->left);
		int countRight = max_depth(t->right); 
		int maximum=0;
		
		if(countLeft>countRight){
			maximum = countLeft+1;
		}
		else{
			maximum = countRight+1;
		}
		return maximum;
    }

    /**
     * Q 2.4
     * Add the code in below function that will evaluate the 
     * minimum depth of the Binary tree and return the integer value.
     */
    int min_depth (BinaryNode *t ) const{
       
		if(t == NULL){
			return 0;
		}
		if(t->left == NULL && t->right==NULL){
			return 1;
		}
	
		int countLeft = min_depth(t->left);
		int countRight = min_depth(t->right); 
		int minimum=0;
		
		if(countLeft<countRight){
			minimum = countLeft+1;
		}
		else{
			minimum = countRight+1;
		}
		return minimum;
		
    }

    /**
     * Q 3
     * Add the code in below function that will evaluate the 
     * diameter of the Binary tree and return the integer value.
     */
    int diameter (BinaryNode *t ) const
    {
        if(t==NULL){
			return 0;
		}
		
		int leftHeight = max_depth(t->left);
		int rightHeight = max_depth(t->right);
		
		int leftdiameter = diameter(t->left);
		int rightdiameter = diameter(t->right);
		
		int max1 =  leftHeight + rightHeight + 1; // if root is a part of diameter
		int max2;
		
		if (leftdiameter > rightdiameter){
			max2 = leftdiameter;
		}
		else{
			max2 = rightdiameter;
		} 
		
		if(max1>max2){
			return max1;
		}
		else{
			return max2;
		}

		
    }

    /**
     * Q 4
     * Add the code in below function that will perform level order 
     * traversal on the Binary tree and print it.
     * 
     * Note: Do not use STL Queue library. Create your own implementaion
     * of queue data structure and use it here.
     */
    void levelorder ( BinaryNode *t, ostream & out ) const
    {
		
		int move;
		int deleted;
		queue myq;
		queue temp;
		
		myq.enqueue(t->element);
		
		while(myq.size() != 0){

			move = myq.top();
			cout << "value of move " << move << endl;
			if(t->left !=NULL && t->right != NULL){
				
				myq.enqueue(t->left->element);
				myq.enqueue(t->right->element);
				
			}
	
			else if(t->left != NULL && t->right == NULL){
				myq.enqueue(t->left->element);
			}
			else if(t->left == NULL && t->right != NULL){
				myq.enqueue(t->right->element);
		
			}
			
			
			temp.enqueue(myq.dequeue());
			t->element = myq.top();
			

		}
		
		temp.display();
		
    }


    /**
     * Q 5
     * Add the code in below function that will find the 
     * lowest common ancestor of 2 nodes with values x & y in the
     * Binary tree and print the value to lowest common ancestor.
     */
    void LCA(BinaryNode *t, int x, int y, ostream & out) const{
		
		if(t==NULL){
			out << "NULL" << endl;
		}
		
		if(t->element > x && t->element > y ){
			LCA(t->left, x, y, out);
			

		}
		if(t->element < x && t->element < y ){
			LCA(t->right, x, y, out);
		}
	
		out << "LCA of " << x << " and " << y << " is " <<t->element << endl;
		
    }


    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new 
                BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
    }
};

#endif
