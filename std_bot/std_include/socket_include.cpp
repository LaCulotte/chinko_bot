#include "socket_include.h"
#include "Logger.h"

using namespace std;
vector<string> dns_lookup_ipv4(string address){
    addrinfo *hints, *res;

    hints = (addrinfo *) malloc(sizeof(addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;

    if(getaddrinfo(address.c_str(), NULL, hints, &res) != 0){
        Logger::write("Error on dns lookup of " + address + ".", LOG_INFO);
        return {};
    }    

    vector<string> output;

    for (addrinfo *ai = res; ai != NULL; ai = ai->ai_next){
        char addr_out[INET_ADDRSTRLEN];
        sockaddr_in *addr_in = (sockaddr_in *)ai->ai_addr;
        inet_ntop(AF_INET, &(addr_in->sin_addr), addr_out, sizeof(addr_out));
        output.push_back(addr_out);
    }

    freeaddrinfo(res);

    return output;
}