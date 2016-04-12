const char* and char* cant be initialized in the same line like the following:
	const char* a;
	char* b;

	a = b = NULL; 
