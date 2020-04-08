#ifndef ORDERED_MAP_H
#define ORDERED_MAP_H

#include <iostream>
using namespace std;       

// OrderedMap class
template <class Key, class Value>
class OrderedMap
{
  public:
    /**
     * Default constructor for the map
     */
    OrderedMap( ) : root_key{ new KeyNode(-1, nullptr, nullptr) }
    { }

    OrderedMap( int map_size) : root_key{ new KeyNode(-1, nullptr, nullptr) }, MAP_MAX_SIZE{ map_size }
    { }
    
    /**
     * Destructor for the map
     */
    ~OrderedMap( )
    { makeEmpty( ); }

    /**
     * Copy assignment
     */
    OrderedMap & operator=( const OrderedMap & rhs )
    {
        OrderedMap copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move assignment
     */
    OrderedMap & operator=( OrderedMap && rhs )
    {
        std::swap( root_key, rhs.root_key );       
        return *this;
    }

    /**
     * Insert a key value pair in the map.
     */
    void insert( const Key & key, const Value & value )
    { 
        int key_hash = hashFunction(key);
        return insert( key_hash, key, value, root_key ); 
    }

    /**
     * Print the map content in sorted order.
     */
    void printMap( ostream & out = cout ) const
    {
        printMap( root_key, out );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    { makeEmpty( root_key ); }



  private:
    
    struct ValueNode
    {
        Key key;
        Value value;
        ValueNode* right;

        ValueNode
            ( const Key & theKey, const Value & theValue, ValueNode *rt)
          : key{ theKey }, value{ theValue }, right{ rt } { }

        ValueNode
            ( Key && theKey, Value && theValue, ValueNode *rt)
          : key{ std::move( theKey ) }, value{ std::move( theValue ) }, right{ rt } { }
    };

    struct KeyNode
    {
        int hash_key;
        ValueNode* right;
        KeyNode* down;

        KeyNode
            (int hash, ValueNode *rt, KeyNode* dn)
          : hash_key{ hash }, right{ rt }, down{ dn } { }
    };

    KeyNode *root_key;
    int MAP_MAX_SIZE;

    /** Q 4.1
     *
     * Implement your own hash function that will convert the Key into an integer.
     * 
     * Note: Return value of this function should be between 0 than MAP_MAX_SIZE - 1.
     */
    int hashFunction( const Key & key ) {
		int number =0;
		
		for(int i=0; i<key.size(); ++i){
			number=number + int(key[i])*7;
		}
		
		return number%MAP_MAX_SIZE;
    }

    /** Q 4.2
     *
     * Implement method to insert a key, value pair in a map.
     * 
     * Note: Since this is ordered map, insert key in sorted order of hash_key.
     *       In case there is already a key node with given hash_key, insert the 
     *       value node in the end.
     */
    void insert( int hash_key, const Key & key, const Value & value, KeyNode* t )
    {
		
		
		if(t->down==NULL){
			//cout << "Firys" << key << " " << value <<endl;
			KeyNode* keyDown = new KeyNode(hash_key, NULL, NULL);
			t->down = keyDown;
			keyDown->down = NULL;
			
			ValueNode* Node = new ValueNode(key, value, NULL);
			t->down->right = Node;
			
			Node->right = NULL;
			
		}
		else{
			KeyNode* temp = t->down;
			KeyNode* prev = t;
			while(temp !=NULL){
				if(temp->hash_key==hash_key){
					
					ValueNode* tempVal;
					
					//cout << temp->right->value << endl;
					while(temp->right != NULL){
						//cout << temp->right->value << endl;
						if (temp->right->right == NULL){
							tempVal = temp->right;
							break;
						}
						temp->right = temp->right->right;
						//cout << "1" << endl;
					}
					
					ValueNode* Node = new ValueNode(key, value, NULL);
					tempVal->right = Node;
					Node->right = NULL;
					return;
					//cout << tempVal->value << temp->right->value << endl;
				}
				else{
					
					//cout << hash_key;
					//cout << " temp hash key " << temp->hash_key << endl;
					
						
						if (hash_key < temp->hash_key){
							
							KeyNode* NewNode = new KeyNode(hash_key, NULL, NULL);
							//cout << temp->hash_key << endl;
							NewNode->down = temp;
							prev->down = NewNode;
							//cout << temp->hash_key << endl;
							
							ValueNode* NewValueNode = new ValueNode(key, value, NULL);
							NewNode->right = NewValueNode;
							NewValueNode->right = NULL;
							return;
							
		
						}
					
						
						if (temp->down == NULL) {
				//cout << "adding a new key node at the end " << hash_key << endl;
							//cout << temp->hash_key << endl;
							
							KeyNode* NewNode = new KeyNode(hash_key, NULL, NULL);
							temp->down = NewNode;
							NewNode->down = NULL;
									
							ValueNode* NewValueNode = new ValueNode(key, value, NULL);
							temp->down->right = NewValueNode;
							NewValueNode->right = NULL;
							return;
						}
						else {
							//cout << temp->hash_key << endl;
							prev = temp;
							temp = temp->down;
							
							//cout << "after moving down key node " << temp->hash_key << endl;
						}
					
				}
				
			  //temp = temp->down;
			}
			
		}
		
		//cout << "hash key " << hash_key << endl;
		
    }


    /**
     * Internal method to make a map empty.
     */
    void makeEmpty( KeyNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty_row( t->right );
            makeEmpty( t->down );
            delete t;
        }
        t = nullptr;
    }

    void makeEmpty_row( ValueNode * & v )
    {
        if( v != nullptr )
        {
            makeEmpty_row( v->right );
            delete v;
        }
        v = nullptr;
    }

    /**
     * Internal method to print the map.
     */
    void printMap( KeyNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            out << t->hash_key << "\t->";
            if(t->hash_key == -1) {
                out << " Root KeyNode of Map";
            } else {
                printMap_row( t->right, out );
            }
            out << endl;
            printMap( t->down, out );
        }
    }

    void printMap_row( ValueNode *v, ostream & out ) const
    {
        if( v != nullptr )
        {
            out << " ( " <<v->key << " , " << v->value << " ) ";
            printMap_row( v->right, out );
        }
    }
};

#endif
