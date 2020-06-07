#include "ServerConnection.h"

void ServerConnection::onConnection() {

    // Checks if log is valid
    if(sock < 0)
        return;

    // Basic necessary variables for getting the address
    socklen_t len;
    sockaddr_storage addr;
    char ipstr[INET6_ADDRSTRLEN];
    int port;

    // Gets address
    len = sizeof(addr);
    getpeername(sock, (sockaddr*)&addr, &len);

    // Deals with both IPv4 and IPv6:
    if (addr.ss_family == AF_INET) {
        // IPv4
        sockaddr_in *s = (sockaddr_in *)&addr;
        port = ntohs(s->sin_port);
        inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
    } else { 
        // IPv6
        sockaddr_in6 *s = (sockaddr_in6 *)&addr;
        port = ntohs(s->sin6_port);
        inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
    }

    // Sets connection's address
    connectedAddress = ipstr;

    // Logs address
    Logger::write("Received connection from : " + connectedAddress + ".", LOG_INFO);
}