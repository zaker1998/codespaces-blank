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

// Function to free memory allocated for the stack
void free_stack(t_stack *stack) {
    t_stack *temp;
    while (stack != NULL) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

// Function to execute an instruction
void execute_instruction(char *instruction, t_stack **stack_a) {
    // Implement the logic to execute the instruction
}

// Function to check if the stack is sorted
int is_sorted(t_stack *stack) {
    // Implement the logic to check if the stack is sorted
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

    // Read instructions from standard input and execute them
    char instruction[4];
    while (scanf("%3s", instruction) != EOF) {
        execute_instruction(instruction, &stack_a);
    }

    // Check if the stack is sorted
    if (is_sorted(stack_a)) {
        printf("OK\n");
    } else {
        printf("KO\n");
    }

    // Free the memory allocated for the stack
    free_stack(stack_a);

    return EXIT_SUCCESS;
}
