#include "lists.h"

/**
 * add_nodeint - adds a new node at beginning of a linked list
 * @head: pointer to first node
 * @n: data to insert in new node
 * Return: a pointer to new  node on success, else NULL
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
