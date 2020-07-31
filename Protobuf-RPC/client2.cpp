#include <iostream>
using namespace std;
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "message.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using prptopkg::output;
using prptopkg::input;
using prptopkg::nill;
using prptopkg::srvc;

class srvc_rqst
 {
 public:
  srvc_rqst(std::shared_ptr<Channel> channel)
      : stub_(srvc::NewStub(channel)) {}

  
  int echo() {
    
    output reply;
	nill m;
	ClientContext context;
    Status status = stub_->echo(&context, m, &reply);
    if (status.ok()) {
      return reply.n();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return -1;
    }
  }
  

 private:
  std::unique_ptr<srvc::Stub> stub_;
};

int main(int argc, char** argv) {
  srvc_rqst inst(grpc::CreateChannel("localhost:8080", grpc::InsecureChannelCredentials()));
  int reply = inst.echo();
  std::cout << "Number of server calls is: " << reply << std::endl;

  return 0;
}