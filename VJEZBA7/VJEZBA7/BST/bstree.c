#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	return NULL;
}
void AddNode(BSTree* bst, char* word)
{
	if (*bst == NULL)
	{
		BSTree temp = (Node*)malloc(sizeof(Node));
		temp->word = word;
		temp->left = NULL;
		temp->right = NULL;
		*bst = temp;
	}
	if (strcmp(word, (*bst)->word) > 0)
	{
		AddNode(&((*bst)->right), word);
	}
	else if (strcmp((*bst)->word, word) > 0)
	{
		AddNode(&((*bst)->left), word);
	}
}
int BSTHeight(BSTree bst)
{
	if (bst == NULL) {
		return 0;
	}
	int lijevo = BSTHeight((bst->left));
	int desno= BSTHeight((bst->right));
	if (lijevo > desno) {
		return 1 + lijevo;
	}
	return 1 + desno;
}
void PrintBSTree(BSTree bst)
{
	if (bst == NULL)
		return;
	PrintBSTree(bst->left);
	printf("%s \n", bst->word);
	PrintBSTree(bst->right);

}
void SaveBSTree(BSTree bst, FILE *fd)
{


	if (bst == NULL)
		return;
	fprintf(fd,"%s \n", bst->word);
	SaveBSTree(bst->left,fd);
	SaveBSTree(bst->right,fd);
}
void DeleteBSTree(BSTree bst)
{
	if (bst == NULL)
		return;
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}
BSTree LoadBSTree(FILE *fd)
{
	BSTree bs = NewBSTree();
	char buffer[1024];
	while (fgets(buffer, 1024, fd)!=NULL) {
		char* word = _strdup(buffer);
		AddNode(&bs, word);
	}

	return bs;
}