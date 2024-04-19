/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:08:21 by mdussali          #+#    #+#             */
/*   Updated: 2024/04/13 14:08:22 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function to check if the stack is sorted
int is_sorted(t_stack *stack) {
    while (stack && stack->next) {
        if (stack->value > stack->next->value)
            return 0; // Stack is not sorted
        stack = stack->next;
    }
    return 1; // Stack is sorted
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

// Function to perform the 'sa' operation (swap the first two elements of stack 'a')
void sa_operation(t_stack **stack_a) {
    if (*stack_a && (*stack_a)->next) {
        int temp = (*stack_a)->value;
        (*stack_a)->value = (*stack_a)->next->value;
        (*stack_a)->next->value = temp;
    }
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
    if (is_sorted(*stack_a)) {
        printf("Stack is already sorted!\n");
        return;
    }

    // Determine the optimal sequence of operations to sort the stack
    // For simplicity, let's implement a basic sorting algorithm
    while (!is_sorted(*stack_a)) {
        // Find the index of the minimum value in the stack
        int min_index = find_min_index(*stack_a);
        // Calculate the number of steps to move the minimum value to the top
        int steps_to_top = min_index;
        if (min_index > (stack_size(*stack_a) / 2)) {
            steps_to_top = stack_size(*stack_a) - min_index;
            while (steps_to_top--)
                rra_operation(stack_a); // Rotate the stack in the reverse direction
        } else {
            while (steps_to_top--)
                ra_operation(stack_a); // Rotate the stack in the forward direction
        }
        // Perform the 'pa' operation to push the minimum value to stack 'b'
        pa_operation(stack_a, &stack_b);
    }
}
