/**Function Types:
 * 
 * So funtion types are derived types. In this case, the type is DERIVED from
 * the return type can the number and types of its parameters. The return type of
 * a function CANNOT BE AN ARRAY TYPE. 🤔🤔🤔🤔🤔 Why is that important i wonder.
 * 
 * So I guess a derived type means simply an object that doesn't have its OWN type
 * persay but gets its type from somewhere else. In a function's case from what is 
 * returned and its parameters.
 * 
 * When declaring a function I will use a function declarator to specify the name
 * of the function an the return type. If the declarator includes a parameter type
 * list and a definition, the declaration of each parameter must include an
 * identifier, except parameter lists with only a single parameter of type void.
 * 
 * So this explains what I've been seeing with declarations of functions in .h files
 * for params that only have type func_name(type,type,type); for example. But when shoud
 * we use these???
 * 
 */

// Some examples of function declarators:
int f(void);
int *fip(); // the infamous function ptr 🙀
void g(int i, int j); // we can use identifiers if I want to
void h(int,int); // but if these was a definition i couldn't do this

/**
 * IN A FUNCTION DECLARATION SPECIFYING PARAMETERS IS OPTIONAL, BUT FAILING TO DO
 * SO CAN BE PROBLEMATIC. IF WE WERRE TO WRITE A FUNCTION DECLARATION IN C++ FOR
 * EXAMPLE int *fip() WOULD MEAN A FUNCTION THAT TAKES NO ARGUMENTS. BUT IN C THIS
 * MEANS A FUNCTION THAT CAN TAKE ANY NUMBER OF ARGUMENTS. 
 * 
 * I CAN SEE HOW THIS WOULD BE POWERFUL AND USEFUL IN CERTAIN CASES, BUT ACCORDING
 * TO SEACORD I SHOULD NEVER DECLARE FUNCTIONS WITH AN EMPTY PARAM LIST. FIRST ITS
 * DEPRECATED AND MAY BE REMOVED IN THE FUTURE, AND SECOND IF PORTED TO C++ IT WOULD
 * HAVE A DIFFERENT BEHAVIOR. SO MAKES SENSE NOT TO USE IT.
 * 
 * A function type with a param type list is known as a function prototype (I've 
 * also heard this term in this book previously)  A function stereotype informs the
 * compiler about the number and types of parameters a function accepts. So here I'm 
 * learning about the why and when of these declarations. 
 * 
 * Compilers use this info to verify that the correct number and type of parameters
 * are used in the function definition and any calls to the function. 
 * 
 * The function definition provides the actual implementation of the function. 
 * for example:
 */
int max(int a, int b)
{
    return a > b ? a : b;
}

/**
 * The return type specifier here is 'int'; the function declarator is 'max(int a, int b);
 * and the function body is {return a > b ? a:b;} The speciication of a function type
 * must not include any type qualifiers ??? (not sure that is but its on page 32)
 * 
 * The function body itself uses the condition operator (ternary) ?: which was 
 * explained previously and will be explained more in chap 4. 
 */
