auto isodd_func = [](auto elem) {return elem % 2 != 0;};

auto isprime_funct = [](auto elem){ 
	// limit case, 1 is a prime
	if (elem == 1)
		return true;

	// going through numbers less then elem and seaching for the possible factor
	for (int i = 2; i < elem; i++){
		if (elem % i == 0)
			return false; 
	}
	return true;
};
