#include "deck.h"

int _strcmp(const char *p1, const char *p2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Function to compares two strings
 * @p1: First string
 * @p2: Second string
 *
 * Return: The positive byte difference if p1 > p2
 *   0 if p1 == p2
 *  and negative byte difference if p1 < p2
 */
int _strcmp(const char *p1, const char *p2)
{
	while (*p1 && *p2 && *p1 == *p2)
	{
		p1++;
		p2++;
	}

	if (*p1 != *p2)
		return (*p1 - *p2);
	return (0);
}

/**
 * get_value - Function to get the numerical value of a card
 * @card: Pointer to a deck_node_t card
 * Return: The numerical value of the card
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - A Function to sort a deck
 *   of cards from spades to diamonds
 * @deck: Doubly-linked list head of a deck_node_t pointer
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *repeat, *insert, *tmp;

	for (repeat = (*deck)->next; repeat != NULL; repeat = tmp)
	{
		tmp = repeat->next;
		insert = repeat->prev;
		while (insert != NULL && insert->card->kind > repeat->card->kind)
		{
			insert->next = repeat->next;
			if (repeat->next != NULL)
				repeat->next->prev = insert;
			repeat->prev = insert->prev;
			repeat->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = repeat;
			else
				*deck = repeat;
			insert->prev = repeat;
			insert = repeat->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - A function to sort a deck of cards sorted
 *      from spades to diamonds from ace to king
 * @deck: Doubly-linked list head of a deck_node_t pointer
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *repeat, *insert, *tmp;

	for (repeat = (*deck)->next; repeat != NULL; repeat = tmp)
	{
		tmp = repeat->next;
		insert = repeat->prev;
		while (insert != NULL &&
		       insert->card->kind == repeat->card->kind &&
		       get_value(insert) > get_value(repeat))
		{
			insert->next = repeat->next;
			if (repeat->next != NULL)
				repeat->next->prev = insert;
			repeat->prev = insert->prev;
			repeat->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = repeat;
			else
				*deck = repeat;
			insert->prev = repeat;
			insert = repeat->prev;
		}
	}
}

/**
 * sort_deck - A function that sorts a deck of cards
 * @deck: Doubly-linked list head of a deck_node_t pointer
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
