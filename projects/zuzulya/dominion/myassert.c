#include <stdlib.h>
#include <stdio.h>

//#define MYASSERT(boolExpr){  
void myassert(boolExpr){
	if(!boolExpr){
		fprintf(stderr,"FAILED: file %s: line %d (%s):%s ",__FILE__,__LINE__,boolExpr);
	}
	return 0;
}
#define MYASSERT(boolExpr){\
	if(!boolExpr){\
		fprintf(stderr,"FAILED: file %s: line %d :%s ",__FILE__,__LINE__,boolExpr);\
	}\
}



