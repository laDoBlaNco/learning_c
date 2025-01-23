#include  <stdio.h>

/**
 * Alignment:
 * Object types have alignment requirements that place restrictions
 * on the addresses at which objects of that type may be allocated. an 
 * alignment represents the number of bytes between successive addresses
 * at which a give object can be allocated. So its like the divisions between
 * the allocations in memory. This was touched on in my Go course when talking 
 * about the Go garbage collector and understanding th hardware underneath.
 * CPUs may have different behavior  when accessing aligned data (for example, 
 * the data address is a multiple of the data size) versus unaligned data. 
 * 
 * Some machine instructions can peform multibyte accesses on nonword boundaries
 * but there may be a peformance penalty. A word is a natural, fixed-sized unit
 * of data (I remember this terminology as well in the Go course when speaking
 * about the size of or measuring instructions.) handled by the instruction set
 * or the hardware of the processor. Some platforms cannot access unaligned 
 * memory. Alignment requirements may depend on the CPU word size (typically 16,
 * 32, or 64 bits). Thus 32 and 64 bit machines.
 * 
 * Generally, we C programmers don't need to concern ourselves with alignment
 * requirements, because the compiler chooses suitable alignments for its 
 * various types, Dynamically allocated memory from malloc is required to be
 * sufficiently aligned for all standard types, including arrays and structs.
 * However on rare occasions, I might need to override the compiler's default 
 * choices; for example to align data on the boundaries of the memory cache lines 
 * (that's what it was, when we talked about Go GC and cache lines) that must start
 * at power-of-two address boundaries or to meet other system-specific reqs. 
 * Traditionally though, these reqs were met by linker commands, or by overallocating
 * memory with malloc followed by rounding the user address upward, or similar 
 * operations involving other nonstandard facilities. 
 * 
 * C11 intro'd a simple, forward-compatible mechanism for specifying alignments. 
 * Alignments are rep'd as values of the type size_t (which I learned about in Bootdev
 * a few hours ago). Every valid alignment value is a nonnegative integral power of two
 * An object type imposes a default alignment req on every object of that type: a
 * stricter alignment (a larger power of two) can be requested using the alignment
 * specifier (_Alignas). I can then include an alignment specifier in the declaration
 * specifiers of a declaration. Below we see this to ensure that 'good_buff' is 
 * properly aligned while 'bad_buff' may have issues
 */

struct S {
    int i;
    double d;
    char c;
};

int main(void) {
    unsigned char bad_buff[sizeof(struct S)];
    _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];

    struct S *bad_s_ptr = (struct S *)bad_buff; // wrong pointer alignment
    struct S *good_s_ptr = (struct S *)good_buff; // correct pointer alignment
}

// Alignments are orderd from weaker to stronger (also called stricter) alignments
// Stricter alignments have larger alignment values. An address that satisfies an
// alignment req also satisfies any valid, weaker alignment requirement.