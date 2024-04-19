#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack element
typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;

// Function to push a new element onto the stack
void push(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Function to print the list of instructions
void print_instructions(char *instruction) {
    printf("%s\n", instruction);
}

// Function to free memory allocated for the stack
void free_stack(t_stack *stack) {
    t_stack *temp;
    while (stack != NULL) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

// Function to find the index of the minimum value in the stack
int find_min_index(t_stack *stack) {
    int min_index = 0;
    int min_value = stack->value;
    int index = 0;

    while (stack) {
        if (stack->value < min_value) {
            min_index = index;
            min_value = stack->value;
        }
        stack = stack->next;
        index++;
    }
    return min_index;
}

// Function to perform the 'ra' operation (rotate up all elements of stack 'a')
void ra_operation(t_stack **stack_a) {
    if (*stack_a && (*stack_a)->next) {
        t_stack *last_node = *stack_a;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = *stack_a;
        *stack_a = (*stack_a)->next;
        last_node->next->next = NULL;
    }
}

// Function to perform the 'rra' operation (reverse rotate down all elements of stack 'a')
void rra_operation(t_stack **stack_a) {
    if (*stack_a && (*stack_a)->next) {
        t_stack *current = *stack_a;
        t_stack *previous = NULL;

        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        current->next = *stack_a;
        *stack_a = current;
    }
}

// Function to implement the push_swap algorithm
void push_swap(t_stack **stack_a) {
    if (*stack_a == NULL)
        return;

    // Determine the optimal sequence of operations to sort the stack
    while ((*stack_a)->next) {
        // Find the index of the minimum value in the stack
        int min_index = find_min_index(*stack_a);
        // Calculate the number of steps to move the minimum value to the top
        int steps_to_top = min_index;
        if (min_index > 0) {
            steps_to_top = min_index;
            while (steps_to_top--)
                ra_operation(stack_a); // Rotate the stack in the forward direction
        } else {
            while (steps_to_top--)
                rra_operation(stack_a); // Rotate the stack in the reverse direction
        }
        // Perform the 'pb' operation to push the minimum value to stack 'b'
        print_instructions("pb");
    }

    // Now, stack 'a' has only one element, which is the maximum value
    // Push all elements back to stack 'a' from stack 'b'
    while (*stack_b) {
        print_instructions("pa");
        *stack_b = (*stack_b)->next;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Not enough arguments\n");
        return EXIT_FAILURE;
    }

    // Create the initial stack 'a' from the input arguments
    t_stack *stack_a = NULL;
    for (int i = argc - 1; i > 0; i--) {
        int value = atoi(argv[i]);
        push(&stack_a, value);
    }

    // Call the push_swap algorithm to generate the list of instructions
    push_swap(&stack_a);

    // Free the memory allocated for the stack
    free_stack(stack_a);

    return EXIT_SUCCESS;
}
