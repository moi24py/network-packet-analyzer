#include <stdio.h>
#include <pcap.h>

// 1. Get program name and network interface name
int main(int argc, char *argv[])
{
    // If user does not provide two arguments
    if (argc < 2) {
        // Print an usage error message and exit the program
        fprintf(stderr, "Usage: %s <network interface>\n"
                "You must pass 2 arguments:\n"
                "1) The program name\n"
                "2) The network interface name\n", argv[0] //Program name
            );
        return 1;
    }

    // 2. Initialize: open the NI for sniffing
	char *net_int = argv[1];
    printf("Selected Network Interface: %s\n", net_int);
    
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    handle = pcap_open_live(net_int, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
	    fprintf(stderr, "Couldn't open Network Interface: \"%s\"\n"
                        "%s\n",
                        net_int, errbuf);
	    return 2;
    }

	return 0;
}