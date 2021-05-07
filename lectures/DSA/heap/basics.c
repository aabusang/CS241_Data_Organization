#include <stdio.h>

typedef struct Node
{
    char *word;
    int count;
    struct Node *left;
    struct Node *right;
}treeNode;


int main(void)
{
}

treeNode *addTree(treeNode *new_node, char *new_word)
{
    int cond;
    if (new_node == NULL)
    {
	new_node = talloc(); /* make a new node */
	new_node->word = strup(new_word);
	new_node->count = 1;
	new_node->left = new_node->right = NULL;
    }
    else if ((cond = strcmp(new_word, new_node->word)) == 0)
    {
	new_node->count++;
    }
    else if (cond < 0)
    {
	new_node->left = addTree(new_node->left, new_word);
    }
    else
    {
	new_node->right = addTree(new_node->right, new_word);
    }
    return new_node;
}
