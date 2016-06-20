const char* and char* cant be initialized in the same line like the following:
	const char* a;
	char* b;

	a = b = NULL;


implementation-defined— The compiler-writer chooses what happens, and has to document it.
Example: whether the sign bit is propagated, when shifting an int right.

unspecified— The behavior for something correct, on which the standard does not impose any
requirements.
Example: the order of argument evaluation.
