#ifndef CONNECTIONUNIT_H
#define CONNECTIONUNIT_H

#include <functional>
#include "MessagingUnit.h"
#include "ClientConnection.h"
#include "ServerConnection.h"
#include "BasicConnectionUnitFrame.h"

// Unit that manages connections
class ConnectionUnit : public MessagingUnit {
public:
    // Constructor
    ConnectionUnit();
    // Copy constructor
    ConnectionUnit(const ConnectionUnit& other) = default;

    // Copy operator
    virtual ConnectionUnit& operator=(const ConnectionUnit& other) = default;
    // Destructor
    virtual ~ConnectionUnit() = default;

    // Connects a connection to a remote server
    virtual int connectToServer(sp<ClientConnection> toConnect, string address, int port, int sourceInterfaceId = -1);
    // int HTTPConnection(string url);
    // Adds a connection
    int addConnection(sp<Connection> connection, int sourceInterfaceId = -1);

    // Send a message through a connection
    bool sendConnectionMessage(sp<ConnectionMessage> message, int destConnectionId, int sourceInterfaceId = -1);
    // Modify the destination of a connection's messages
    bool changeConnectionDestination(int connectionId, int newDestination);

    // Disconnects the connection of id 'connectionId'
    void disconnect(int connectionId);

    // Returns the id of a connection that can cast into T
    template<typename T>
    int getConnectionId();
    // Returns the id of a connection that can cast into T and makes filter return true
    template<typename T>
    int getConnectionId(function<bool(sp<Connection>)> filter);
    // Returns the id of multiple connections that can cast into T
    template<typename T>
    vector<int> getConnectionIds(int n, bool fill = false);
    // Returns the id of multiple connections that can cast into T and makes filter return true
    template<typename T>
    vector<int> getConnectionIds(int n, function<bool(sp<Connection>)> filter, bool fill = false);
    template<typename T>
    // Returns the id of all the connections that can cast into T
    vector<int> getAllConnectionIds();
    template<typename T>
    // Returns the id of all the connections that can cast into T and makes filter return true
    vector<int> getAllConnectionIds(function<bool(sp<Connection>)> filter);

    // Initialize the first frames
    virtual void initFrames() override;
    // Tick; launched every loop
    virtual void tick() override;

    // Removes the messageInterface of id 'interfaceId'
    virtual bool removeMessageInterface(int interfaceId) override;
    // Removes the messageInterface at the iterator 'interfaceIt'
    virtual bool removeMessageInterface(map<int, sp<MessageInterface>*>::iterator interfaceIt) override;

protected:
    // Connections managed by this ConnectionUnit
    map<int, sp<Connection>> connections;
    // Id of the last connection managed by this ConnectionUnit
    int lastConnectionId = 0;

    // Map that links a connection to the interface towards which the received messages should go
    unordered_map<int, int> connectionId_to_interfaceId;
    /** Map that links an interface to the connection that the messages should be sent to if no destination connection is given
     *  Changes when the interface : sends a message, connects to new connection, changes a connection's destination
     */
    unordered_map<int, int> interfaceId_to_preferredConnectionId;
};

template<typename T>
int ConnectionUnit::getConnectionId(){
    for(auto it = connections.begin(); it != connections.end(); it++){
        if(dynamic_pointer_cast<T>(it->second))
            return it->first;
    }

    return -1;
}

template<typename T>
int ConnectionUnit::getConnectionId(function<bool(sp<Connection>)> filter){
    for(auto it = connections.begin(); it != connections.end(); it++){
        sp<T> T_cast = dynamic_pointer_cast<T>(it->second);
        if(T_cast && filter(T_cast))
            return it->first;
    }

    return -1;
}

template<typename T>
vector<int> ConnectionUnit::getConnectionIds(int n, bool fill){
    vector<int> ret;

    for(auto it = connections.begin(); it != connections.end() && ret.size() < n; it++){
        if(dynamic_pointer_cast<T>(it->second))
            ret.push_back(it->first);
    }

    if(fill)
        while(ret.size() < n)
            ret.push_back(-1);

    return ret;
}

template<typename T>
vector<int> ConnectionUnit::getConnectionIds(int n, function<bool(sp<Connection>)> filter, bool fill){
    vector<int> ret;

    for(auto it = connections.begin(); it != connections.end() && ret.size() < n; it++){
        sp<T> T_cast = dynamic_pointer_cast<T>(it->second);
        if(T_cast && filter(T_cast))
            ret.push_back(it->first);
    }

    if(fill)
        while(ret.size() < n)
            ret.push_back(-1);

    return ret;
}

template<typename T>
vector<int> ConnectionUnit::getAllConnectionIds(){
    vector<int> ret;

    for(auto it = connections.begin(); it != connections.end(); it++){
        if(dynamic_pointer_cast<T>(it->second))
            ret.push_back(it->first);
    }

    return ret;
}

template<typename T>
vector<int> ConnectionUnit::getAllConnectionIds(function<bool(sp<Connection>)> filter){
    vector<int> ret;

    for(auto it = connections.begin(); it != connections.end(); it++){
        sp<T> T_cast = dynamic_pointer_cast<T>(it->second);
        if(T_cast && filter(T_cast))
            ret.push_back(it->first);
    }

    return ret;
}

#endif