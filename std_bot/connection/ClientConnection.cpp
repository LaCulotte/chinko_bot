#include "ClientConnection.h"

bool ClientConnection::connectTo(string address, int port){
    // Disconnects if the connection object is already connected 
    if(connected)
        this->disconnect();


    // Initialiazes the socket
    if(!(sock = socket(AF_INET, SOCK_STREAM, 0))){
        Logger::write("Cannot create socket.", LOG_ERROR);
        return false;
    }

    // Initializes address variables 
    sockaddr_in addr_in;
    int addr_len = sizeof(addr_in);
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(port);

    // Tries to find the adress
    if(inet_pton(AF_INET, address.c_str(), &addr_in.sin_addr) <= 0){
        Logger::write(address + " is not a valid IP adress. Attenpting a dns request.", LOG_INFO);
        
        // If it is not a valid ip adress, tries a dns lookup
        vector<string> ips = dns_lookup_ipv4(address);

        // Tries to connect to one of the returned adresses
        bool correctAddress = false;
        for(int i = 0; i < ips.size() && !correctAddress; i++){
            if(inet_pton(AF_INET, address.c_str(), &addr_in.sin_addr) > 0)
                correctAddress = true;
        }

        if(!correctAddress){
            Logger::write("Impossible to find " + address + ".", LOG_WARNING);
            return false;
        }
    }

    // Connects to the set adress
    if(connect(sock, (sockaddr *) &addr_in, sizeof(addr_in)) < 0){
        Logger::write("Cannot connect to :" + address + ".", LOG_WARNING);
        return false;
    }

    // If sucessful, Logs and sets the object's attributes
    Logger::write("Connected to : " + address + ".", LOG_INFO);
    connected = true;
    connectedAddress = address;

    return true;
}

