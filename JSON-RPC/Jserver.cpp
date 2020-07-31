///////////////////////////////////////Code developed and Contributed by Muhammad Hamza (mhamzai)//////////////////////////////////
///////////////////////Use allowed in opensource projects only by fairuse and giving due credits to the developer//////////////////
#include <iostream>
using namespace std;
#include <cxxtools/arg.h>
#include <cxxtools/log.h>
#include <cxxtools/json/rpcserver.h>
#include <cxxtools/eventloop.h>

static int total=0;
int echo()
{
  return total;
}

int add(int a, int b)
{
  total++;
  return a + b;
}

int main(int argc, char* argv[])
{    
	cxxtools::Arg<std::string> ip(argc, argv, 'i');

    cxxtools::Arg<unsigned short> port(argc, argv, 'p', 8080);

    cxxtools::EventLoop loop;

    cxxtools::json::RpcServer jsonServer(loop, ip, port);

    jsonServer.registerFunction("echo", echo);
    jsonServer.registerFunction("add", add);

    loop.run();
 
}
