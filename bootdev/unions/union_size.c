/**Union Size
 * 
 * The downside of unions is that the size of the union is the
 * size of the LARGEST field in the union. 
 * 
 * for example:
 */
#include <stdio.h>

typedef union {
    int data;
    char err[256];
} int_or_err_message_t;

// this union is designed to hold an int 99% of the time. But in 
// hopefully rare cases where we get an error, instead of storing
// an int, it'll store an error message at most 256 bytes long. 
// The trouble here is that 99% of the time we are wasting 252 
// bytes for every int that it stores. That's super inefficient. 

// Imagine now that I have an array of 1000 int_or_err_message_t 
// objects. Even if non of them make use of the .err field, the 
// array is taking up 256,000 bytes of memory. An array of ints
// that would normally only take up 4,000 bytes (if 32 bit)

// Assignment - answer the following questions:
// How many bytes will an instance of SensorData require? 8 bytes
// What is the correct order, from least to greatest, of the memory
//  requirements of the given unions? 
//      🔹 SensorData
//      🔹 Item
//      🔹 PacketPayload

union SensorData {
    long int temperature;
    long int humidity;
    long int pressure;
};
union PacketPayload {
    char text[256];
    unsigned char binary[256];
    struct ImageData {
        int width;
        int height;
        unsigned char data[1024];
    } image; // note the var name here cuz the struct is actually
    // acting as a LITERAL TYPE here. o sea I'm creating and using 
    // it at the same time.
};

union Item {
    struct {
        int damage;
        int range;
        int size;
    } weapon;
    struct {
        int healing_amount;
        int duration;
    } potion;
    struct {
        int door_id;
    } key;
};

int main(int argc, char const *argv[])
{
    printf("\n");
    int x;
    char y;
    long z;

    printf("On my system:\n");
    printf("\tsizeof(int) = %zu\n",sizeof(x));
    printf("\tsizeof(char) = %zu\n",sizeof(y));
    printf("\tsizeof(long int) = %zu\n\n",sizeof(z));


    union SensorData sensor_data;
    union PacketPayload packet_payload;
    union Item item;
    printf("A instance of SensorData will require %zu bytes.\n",sizeof(sensor_data));
    printf("A instance of PacketPayload will require %zu bytes.\n",sizeof(packet_payload));
    printf("A instance of Item will require %zu bytes.\n",sizeof(item));



    printf("\n");
    return 0;
}

