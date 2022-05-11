#include "btree.h"
#include <stdlib.h>
#include "fatal.h"

struct TreeNode{
    ElementType Element;
    BTree  Left;
    BTree  Right;
};


BTree MakeEmpty( BTree T ){
	if (T != NULL){
		MakeEmpty( T->Left );
		MakeEmpty( T->Right );
		free T;
	}
	return NULL;
}


BTree SetTree( ElementType X, BTree Left, BTree Right ){
    BTree T;
    T->Element = X;
    T->Left = Left;
    T->Right = Right;
    
    return T;
}

BTree GetRight( BTree T ){
	if (T == NULL)
		return NULL;
	return T->Right;
}

BTree GetLeft( BTree T ){
	if (T == NULL)
		return NULL;
	return T->Left;
}

Position Find( ElementType X, BTree T ){
    while(T->Right != NULL)
        if(T->Element == X) { return T; }

    while(T->Left != NULL)
        if(T->Element == X) { return T; }

    return NULL;
   
}


ElementType Retrieve( Position P ){
	return T->Element;
}
