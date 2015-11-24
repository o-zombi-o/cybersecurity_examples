/// @filename example1.cpp
/// @author Joel D. Rodriguez-Ortiz
/// @brief CS562 Out of Bounds Access Example 1

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

// RFC 6520
struct HeartbeatMessageType
{
    unsigned char type;
    unsigned short length;
    unsigned char* payload;
    unsigned char padding[16];
};

int main(int, char**)
{
    // allocate memory for incoming heartbeat message
    HeartbeatMessageType* beat = (HeartbeatMessageType*) 
        malloc(1 * sizeof(HeartbeatMessageType));

    beat->payload = (unsigned char*) malloc(3 * sizeof(char));

    // a false beat message length is written
    beat->length = 50;

    // actual payload is 3 bytes
    beat->payload[0] = 'f';
    beat->payload[1] = 'o';
    beat->payload[2] = 'o';

    // library has been working on some other stuff in the meantime
    // like decrypting messages with my secret key
    char* secret = (char*) malloc(6 * sizeof(char));
    secret[0] = 's';
    secret[1] = 'e';
    secret[2] = 'c';
    secret[3] = 'r';
    secret[4] = 'e';
    secret[5] = 't';

    // heart beat response portion does not check payload length when 
    // creating response
    char* response = (char*) malloc(beat->length * sizeof(char));

    // protocol is supposed to respond the same payload as request
    memcpy(response, beat->payload, beat->length);

    // what is in response?
    for (int i = 0; i < beat->length; ++i)
        printf("%c", response[i]);

    printf("\n");

    free(response);

    free(secret);
    free(beat->payload);
    free(beat);
}
