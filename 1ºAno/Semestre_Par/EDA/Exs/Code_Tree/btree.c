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

}


ElementType Retrieve( Position P ){
	return T->Element;
}
