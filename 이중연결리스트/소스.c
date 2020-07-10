#include <stdio.h>

typedef int element;

typedef struct DlistNode {
	struct DlistNode* llink;
	element data;
	struct DlistNode* rlink;
} DlistNode;

void dinsert_node(DlistNode* before, DlistNode* added) {
	added->llink = before;
	added->rlink = before->llink;

	before->rlink->llink = added;
	before->rlink = added;
}

void dremove_node(DlistNode* phead_node, DlistNode* removed) {
	if (removed == phead_node)
		return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;

	free(removed);
}