/** Tags
 * 
 * This is the first time I'm hearing about Tags. Tags are a special
 * naming mechanism for structs, unions, and enums. This is probably
 * what we use after the typedefs createing the {}name_t; 
 *      struct s {
 *          // ---- snip -----
 *      };
 * the identifiers appearing in the above is a tag.
 *  
 * By itself, a tag isn't a type name and cann't be used to declare
 * a variable. Instead you must declare variables of this type as
 * follows:
 * 
 * struct s v;  // an instance of struct s
 * struct s *p;  // pointer to struct  s
 * 
 * So this is the way I've been creating instances of these structs
 * up until now. So even though we are creating types, we have to
 * use 'struct' to actually create an instance of that user-defined
 * type.
 * 
 * The names of unions and enums are also tags and not technically
 * types, which is way we need to use addition semantics to 
 * delare those variables as well. Like:
 *      enum day {sun,mon,tue,wed,fri,sat};
 *      day today; // this will give us an error
 *      enum day tomorrow; // this is how we need to declare this instance
 * 
 * The tags of structures, unions, and enums are defined in a separate
 * namespace from ordinary identifers. I haven't heard about namespaces
 * in C as of yet, so this is a topic I'll need to dive into later. But
 * might be talking about the header files themselves which is a simple
 * concept to follow.
 * 
 * This allows C programs to have both a tag and another identifier
 * with the same spelling the same scope. 
 *      enum status {ok, fail}; // enumeration
 *      enum status status(void); // a function that returns an enum
 * 
 * This might not be good practice, but it is valid in C. I can think
 * of struct tags as type names and define alias for the tags using
 * typedef. This is what I've been doing in bootdev recently studying
 * about typedef struct name {} name_t; semantics.
 * 
 *      typedef struct s { int x; } s_t;
 * 
 * this now allows us to declare variables with s_t rather than having 
 * to use struct s everywhere we need to declare an instance or 
 * callout a return type, etc. 
 * 
 * This works fine except in the case of self-referential structures. This
 * is what I learned today. When I have recursive type structs so when this
 * happens I'll need to use 'forward declarations' which are like function
 * declarations, though I haven't touched those in this book yet.
 * 
 * An example of self-referential structs (reursive). Again it looks
 * like something I'll be using in DSA :
 *      struct tnode {
 *          int count;
 *          struct tnode *left;
 *          struct tnode *right;
 *      };
 * 
 * I i were to omit the tag on the first line, the compiler would 
 * complain becaused the referenced structure on lines 3 and 4 haven't
 * yet been declared, which makes sense, or because the whole structure
 * hasn't been used yet. Consequently, I would have no choice but to 
 * declare a tag for the struct. And that is what we do with typedef
 *      typedef struct tnode {
 *          int count;
 *          struct tnode *left;
 *          struct tnode *right;
 *      } tnode; 
 * 
 * Most C programmers use a different name for the tag and the typedef
 * but the same name works just fine. I can also define this type before
 * structure in what I referred to before as the "forward declaration" and
 * this way i can use it to declare the left and right members referred
 * to above. This is what I've seen in Go, which now makes sense as to
 * why.
 *      typedef struct tnode tnode; // this isn't common but works using same name
 *      struct tnode{
 *          int count;
 *          tnode *left;
 *          tnode *right;
 *      } tnode;
 * 
 * I jsut learned about this in bootdev earlier today. 
 * 
 * Type definitions can improve code readibility beyond their use with
 * strutures. For example, all three of teh following declarations of 
 * the signal funtion specify the same type:
 * 
 *      typedef void fv(int),  (*pfv)(int);
 *      void (*signal(int,void (*)(int)))(int);
 *      fv *signal(int,fv *);
 *      pfv signal(int,pfv);
 * 
 * 
 */