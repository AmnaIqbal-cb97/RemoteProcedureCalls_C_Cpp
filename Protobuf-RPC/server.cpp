///////////////////////////////////////Code developed and Contributed by Muhammad Hamza (mhamzai)//////////////////////////////////
///////////////////////Use allowed in opensource projects only by fairuse and giving due credits to the developer//////////////////
#include <iostream>
using namespace std;
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "message.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using prptopkg::output;
using prptopkg::input;
using prptopkg::nill;
using prptopkg::srvc;
static int callnum=0;
class services final : public srvc::Service {
  Status add(ServerContext* context, const input* inp, output* result) override {
	  
    result->set_n(inp->a() + inp->b());
	callnum=callnum+1;
    return Status::OK;
  }
  
  Status echo(ServerContext* context, const nill* empt, output* result) override {
	  
    result->set_n(callnum);
    return Status::OK;
  }
};

int main(int argc, char** argv) {
  std::string server_address("0.0.0.0:8080");//connect on port 8080 and listen there
  services service;

  ServerBuilder builder;
  
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
  return 0;
}
