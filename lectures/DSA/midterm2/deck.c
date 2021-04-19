#include <stdio.h>
#include <stdlib.h>

typedef struct Card
{
    int value;
    char *suit;
}card;

void shuffle(card *c1, card *c2, card c3, card c4);

int main(void)
{
    card card1, card2, card3, card4;
    card1.value = 2;
    card1.suit = "hearts";

    card2.value = 10;
    card2.suit = "diamonds";
    
    card3.value= 9;
    card3.suit = "clubs";
    
    card4.value = 7;
    card4.suit = "spades";
    
    printf("Old Hand\n");
    printf("%d %s\n", card1.value, card1.suit);
    printf("%d %s\n", card2.value, card2.suit);
    printf("%d %s\n", card3.value, card3.suit);
    printf("%d %s\n", card4.value, card4.suit);
    
    shuffle(&card1, &card2, card3, card4);

    printf("New Hand\n");
    printf("%d %s\n", card1.value, card1.suit);
    printf("%d %s\n", card2.value, card2.suit);
    printf("%d %s\n", card3.value, card3.suit);
    printf("%d %s\n", card4.value, card4.suit);
}

void shuffle(card *c1, card *c2, card c3, card c4)
{
    c1->value = c2->value;
    c2->suit = c3.suit;
    c3.suit = c4.suit;
    c4.value = c2->value;
}
