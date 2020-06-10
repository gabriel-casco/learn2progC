#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  size_t i=0;
  card_t c={2, NUM_SUITS};
  for(i=0; i< hand->n_cards; i++){
    c.value = hand-> cards[i]->value;
    c.suit = hand->cards[i]->suit;
    print_card(c);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  size_t i;
  for(i=0; i<(d->n_cards); i++){
    if((d->cards[i]->value ==c.value)&&(d->cards[i]->suit==c.suit)){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  int i;
  for(i=0; i< (*d).n_cards; i++){
    size_t j = i + rand()/(RAND_MAX/((*d).n_cards - 1) + 1);
    if(j< (*d).n_cards){
      card_t * temp = (*d).cards[j];
      (*d).cards[j] = (*d).cards[i];
      (*d).cards[i] = temp;
    }
    else{
      j = j%((*d).n_cards);
      card_t * temp = (*d).cards[j];
      (*d).cards[j] = (*d).cards[i];
      (*d).cards[i] = temp;
    }
  }
}

void assert_full_deck(deck_t * d) {
  int i=0;
  for(i=0; i< (*d).n_cards; i++){
    if( deck_contains(d, *(d->cards[i])) != 1){
      exit(EXIT_FAILURE);
    }
    int j;
    for(j=0; j<(d->n_cards); j++){
      if( (j!=i)&&( ((d->cards[j]->value) == (d->cards[i]->value))&&((d->cards[j]->suit) == (d->cards[i]->suit)))){
	exit(EXIT_FAILURE);
      }
    }
  }
}
