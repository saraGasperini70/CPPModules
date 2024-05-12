int	main()
{
	ClapTrap hank("Hank");

	hank::attack("Mark")
	hank::takeDamage(3);
	hank::beRepaired(3);
	hank::takeDamage(10);
	hank::attack("Mark");
	return (0);
}
