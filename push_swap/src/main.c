#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

t_stack *push(t_stack *stack, int value)
{
    t_stack *new_node = malloc(sizeof(t_stack));
    if (new_node == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = stack;
    return new_node;
}

void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void free_stack(t_stack *stack)
{
    t_stack *temp;
    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

t_stack *quicksort(t_stack *stack)
{
    if (stack == NULL || stack->next == NULL)
        return stack;

    int pivot = stack->value;
    t_stack *smaller_head = NULL;
    t_stack *larger_head = NULL;
    t_stack *smaller_tail = NULL;
    t_stack *larger_tail = NULL;

    t_stack *current = stack->next;
    while (current != NULL)
    {
        t_stack *next = current->next;
        if (current->value <= pivot)
        {
            if (smaller_head == NULL)
                smaller_head = smaller_tail = current;
            else
            {
                smaller_tail->next = current;
                smaller_tail = current;
            }
        }
        else
        {
            if (larger_head == NULL)
                larger_head = larger_tail = current;
            else
            {
                larger_tail->next = current;
                larger_tail = current;
            }
        }
        current->next = NULL;
        current = next;
    }

    smaller_head = quicksort(smaller_head);
    larger_head = quicksort(larger_head);

    if (smaller_head != NULL)
    {
        stack = smaller_head;
        smaller_tail->next = NULL;
        while (smaller_tail->next != NULL)
            smaller_tail = smaller_tail->next;
        smaller_tail->next = push(larger_head, pivot);
    }
    else
    {
        stack = push(larger_head, pivot);
    }

    return stack;
}

int main(int argc, char **argv)
{
    t_stack *stack = NULL;

    if (argc < 2)
    {
        printf("Usage: %s <numbers to sort>\n", argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        int value = atoi(argv[i]);
        stack = push(stack, value);
    }

    printf("Before sorting: ");
    print_stack(stack);

    stack = quicksort(stack);

    printf("After sorting: ");
    print_stack(stack);

    free_stack(stack);

    return 0;
}
