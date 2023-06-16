#include "main.h"

/**
 * print_dlistint - prints a doubly list
 * @h: pointer to the list
 * Return: number of nodes in the linked list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}

	return (nodes);
}
