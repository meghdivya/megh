#include<iostream>

#define MAX_NODES 20;

struct trieNode {
	char a;
	struct *trieNode[MAX_NODES];
}
