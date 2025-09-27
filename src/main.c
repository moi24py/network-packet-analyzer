#include <stdio.h>
#include <pcap.h>

// Get program name and network interface name
int main(int argc, char *argv[])
{
    // if user does not provide two arguments
    if (argc < 2) {
        // print an usage error message and exit the program
        fprintf(stderr, "Usage: %s <network interface>\n"
                "You must pass 2 arguments:\n"
                "1) The program name\n"
                "2) The network interface name\n", argv[0] //program name
            );
        return 1;
    }

    // Network interface to sniff on
	char *net_int = argv[1];

	printf("Network interface: %s\n", net_int);
	return(0);
}