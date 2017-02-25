#include <SocketAddr.h>
#include <SocketOperation.h>

using namespace agilNet::net;

SocketAddr::SocketAddr()
    :valid(false)
{

}
SocketAddr::SocketAddr(struct sockaddr_in addr)
    : valid(true),
    sockAddr(addr)
{

}

SocketAddr::~SocketAddr()
{

}
SocketAddr::SocketAddr(const string& addrPort)
    :valid(false)
{
    struct sockaddr_in addrIn;
    if(!SocketOperation::toAddrIpv4(addrPort,addrIn))
    {
        return ;
    }
    new (this)SocketAddr( addrIn);
}

SocketAddr::SocketAddr(const string& addr,uint16_t port)
    :valid(false)
{
    struct sockaddr_in addrIn;
    if(!SocketOperation::toAddrIpv4(addr,port,addrIn))
    {
        return ;
    }
    new (this)SocketAddr( addrIn);

}

SocketAddr::SocketAddr(uint16_t port)
    :valid(false)
{
    struct sockaddr_in addrIn;
    if(!SocketOperation::toAddrIpv4(port,addrIn))
    {
        return ;
    }
    new (this)SocketAddr( addrIn);

}

void SocketAddr::setAddr(struct sockaddr_in addr)
{
    sockAddr = addr;
    valid = true;
}
struct sockaddr_in* SocketAddr::getAddr()
{
    return &sockAddr;
}

bool SocketAddr::isValid()
{
    return valid;
}
