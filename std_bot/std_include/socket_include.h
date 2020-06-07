#ifndef SOCKETINCLUDE_H
#define SOCKETINCLUDE_H

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "std_include.h"

std::vector<std::string> dns_lookup_ipv4(std::string address);

#endif