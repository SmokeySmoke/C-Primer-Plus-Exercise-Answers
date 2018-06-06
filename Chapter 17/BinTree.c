/* BinTree.c -- implementation of binary search tree */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "BinTree.h"

static void AddNode(Node * pn, Node * root);
static void DeleteNode(Node * pn);
static void ShowAllNodes(Node * pn);
static Node * SearchNodes(Item * pi, Node * root);
static Node * MakeNode(Item * pi);
static Node * SearchTree(Item * pi, Tree * pt);

void InitializeTree(Tree * pt)
{
	pt->root = NULL;
	pt->size = 0;
}

bool TreeIsEmpty(Tree * pt)
{
	return pt->size == 0 ? true : false;
}

unsigned TreeItemCount(Tree * pt)
{
	return pt->size;
}

bool AddItem(Item * pi, Tree * pt)
{
	Node * new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		return false;
	}

	pt->size++;

	if (pt->root == NULL)
		pt->root = new_node;
	else
		AddNode(new_node, pt->root);

	return true;
}

void ShowTree(Tree * pt)
{
	ShowAllNodes(pt->root);
}

void ShowItem(Item * pi, Tree * pt)
{
	Node * target = SearchTree(pi, pt);
	if (target == NULL)
		puts("Item not found!");
	else
		printf("%s - %u\n", target->item.string, target->count);
}

void EmptyTree(Tree * pt)
{
	if (pt != NULL)
		DeleteNode(pt->root);
}

/* local functions */
static Node * MakeNode(Item * pi)
{
	Node * new_node;
        if ((new_node = (Node *) malloc(sizeof(Node))) == NULL)
		return new_node;

	new_node->item = *pi;
	new_node->count = 1;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

static void AddNode(Node * pn, Node * root)
{
	int compare = strcmp(pn->item.string, root->item.string);
	if (compare < 0)
	{
		if (root->left == NULL)
			root->left = pn;
		else
			AddNode(pn, root->left);
	}
	else if (compare > 0)
	{
		if (root->right == NULL)
			root->right = pn;
		else
			AddNode(pn, root->right);
	}
	else
		root->count++;
}

static void DeleteNode(Node * pn)
{
	if (pn->left != NULL)
		DeleteNode(pn->left);
	if (pn->right != NULL)
		DeleteNode(pn->right);
	free(pn);
}

static Node * SearchTree(Item * pi, Tree * pt)
{
	return SearchNodes(pi, pt->root);
}

static Node * SearchNodes(Item * pi, Node * root)
{
	int compare;
	compare = strcmp(pi->string, root->item.string);

	if (compare < 0)
	{
		if (root->left == NULL)
			return NULL;
		else
			SearchNodes(pi, root->left);
	}
	else if (compare > 0)
	{
		if (root->right == NULL)
			return NULL;
		else
			SearchNodes(pi, root->right);
	}
	else
		return root;
}

static void ShowAllNodes(Node * pn)
{
	if (pn->left != NULL)
		ShowAllNodes(pn->left);
	if (pn->right != NULL)
		ShowAllNodes(pn->right);
	
	printf("%s - %u\n", pn->item.string, pn->count);
}
