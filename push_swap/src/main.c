int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);

    stack_a = malloc(sizeof(stack_a));
	stack_b = malloc(sizeof(stack_b));
	if(stack_a == NULL)
	{
		return (0);
	}

	stack_a->value = argv[1];
	stack_a = stack_a->next;
	stack_a = stack_a->value[2];
}