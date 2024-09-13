#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index from a list.
 *
 * @head: A pointer to the pointer to the first element of the list.
 * @index: The index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    dlistint_t *node_to_delete;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    // Traverse to the node at index
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    // If index is greater than the number of nodes
    if (current == NULL)
        return (-1);

    node_to_delete = current;

    // If deleting the first node
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        // Update the previous node's next pointer
        if (current->prev != NULL)
            current->prev->next = current->next;

        // Update the next node's previous pointer
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    // Free the memory of the node to delete
    free(node_to_delete);

    return (1);
}
