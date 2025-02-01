/**Helper Fields
 * 
 * One interesting (albeit not commonly used) trick is to use unions
 * to create "helpers" for accessing different parts of a piece of
 * memory. 
 * 
 * for example, below in memory we would have a union that will hold
 * memory for uint32 but that would actual hold the value of an RGBA
 * of size 32bits or a struct of 4 fields 8bits each. 
 * https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/su7cGjT.png
 * 
 * Only 4 bytes are used, and unlike in 99% of scenarios, it actually 
 * makes sense to both set and get values from this union through both 
 * the components and rgba fields. Both fields in the union are 
 * EXACTLY 32bits in size meaning that we can 'safely?' access the 
 * entire set of colors through the .rgba field or get a single 
 * color component through the .components field
 * 
 * The convenience of additional fields, with the efficiency of a
 * single memory location!
 * 
 * Assignment: 
 * Complete the PacketHeaer union that will have 2 potential fields
 *      🔹 tcp_header: A struct. The first 2 bytes being src_port. 
 *         the next 2 bytes are dest_port, and the last 4 bytes 
 *         are seq_num
 *      🔹 raw: An array of 8 bytes
 * Use uint8_t, uint16_t, and uint32_t for the types of the fields
 * based on the number of bytes needed. 
 *      🔹 8 bits = 1 byte
 */

#include <stdio.h>
#include <stdint.h>

typedef union Color {
    struct{
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    } components;
    uint32_t rgba;
} color_t;

typedef union PacketHeader {
    struct {
        uint16_t src_port;
        uint16_t dest_port;
        uint32_t seq_num;
    } tcp_header;
    uint8_t raw[8]; // ??? This was a correct assumption. If I change
    // it to a uint64_t or uint32_t which I thought at first, I get 
    // garbage results. Its uint8_t because its an array of 8 bytes
    // each byte must then be 8 bits. The total size would of course
    // be 64 bits (8 * 8), but the array syntax is the type of each
    // element not the total size. Thus uint8_t 🤓
} packet_header_t;

int main(int argc, char const *argv[])
{
    packet_header_t header;

    header.tcp_header.src_port = 0x1234;
    header.tcp_header.dest_port = 0x5678;
    header.tcp_header.seq_num = 0x9ABCDEF0;

    printf("\n\nTest #1:\n");
    printf("\tPacketHolder union should be 8 bytes and it is %zu bytes\n\n",sizeof(header));
    
    printf("Test #2:\n");
    printf("\tsrc_port should be 0x1234 and it is 0x%X\n",header.tcp_header.src_port);
    printf("\tdest_port should be 0x5678 and it is 0x%X\n",header.tcp_header.dest_port);
    printf("\tseq_num should be 0x9ABCDEF0 and it is 0x%X\n\n",header.tcp_header.seq_num);

    packet_header_t header2 = {0}; // setting each individual element
    header2.tcp_header.src_port = 0x1234;
    header2.tcp_header.dest_port = 0x5678;
    header2.tcp_header.seq_num = 0x9ABCDEF0;

    printf("test #3\n");
    printf("\t[0] should be 0x34 and its 0x%X\n",header2.raw[0]);
    printf("\t[1] should be 0x12 and its 0x%X\n",header2.raw[1]);
    printf("\t[2] should be 0x78 and its 0x%X\n",header2.raw[2]);
    printf("\t[3] should be 0x56 and its 0x%X\n",header2.raw[3]);
    printf("\t[4] should be 0xF0 and its 0x%X\n",header2.raw[4]);
    printf("\t[5] should be 0xDE and its 0x%X\n",header2.raw[5]);
    printf("\t[6] should be 0xBC and its 0x%X\n",header2.raw[6]);
    printf("\t[7] should be 0x9A and its 0x%X\n",header2.raw[7]);

    return 0;
}


