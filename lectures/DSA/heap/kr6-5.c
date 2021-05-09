#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFFSIZE 100

struct tnode /* the tree node */
{
    char *word; /* points to the text */
    int count; /* number of occurence */
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
};

struct tnode *addTree(struct tnode  *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);

char buffer[BUFFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buffer */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp > BUFFSIZE)
    {
	printf("ungetch: too many characters\n");
    }
    else
    {
	buffer[bufp++] = c;
    }
}

/* addTree: add a node with w, at or below p */
struct tnode *addTree(struct tnode *p, char *new_word)
{
    int cond;
    if (p == NULL)
    {
	p = talloc(); /* make new node */
	p->word = strdup(new_word);
	p->count = 1;
	p->left = p->right = NULL;
    }
    else if ((cond = strcmp(new_word, p->word)) == 0)
    {
	p->count++; /* repeated word */
    }
    else if (cond < 0)
    {
	p->left = addTree(p->left, new_word);
    }
    else
    {
	p->right = addTree(p->right, new_word);
    }
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
	treeprint(p->left);
	printf("%4d %s\n", p->count, p->word);
	treeprint(p->right);
    }
}

/* get next word of character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
	;
    if (c != EOF)
    {
	*w++ = c;
    }
    if (!isalpha(c))
    {
	*w = '\0';
	return c;
    }

    for ( ; --lim > 0; w++)
    {
	if (isalnum(*w = getch()))
	{
	    ungetch(*w);
	    break;
	}
    }

    *w = '\0';
    return word[0];
}

/*talloc: make a new tnode*/
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* word frequency count */
int main(void)
{
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;

    while(getword(word, MAXWORD) != EOF)
    {
	if (isalpha(word[0]))
	{
	    root = addTree(root, word);
	}
    }

    treeprint(root)
}
