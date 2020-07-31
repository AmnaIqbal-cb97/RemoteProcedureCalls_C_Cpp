///////////////////////////////////////Code developed and Contributed by Muhammad Hamza (mhamzai)//////////////////////////////////
///////////////////////Use allowed in opensource projects only by fairuse and giving due credits to the developer//////////////////
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
  srvc_rqst(std::shared_ptr<Channel> channel): stub_(srvc::NewStub(channel)) {}

  
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
	
	int add(int a, int b) {
    
    output reply;
	input m;
	m.set_a(a);
	m.set_b(b);
	ClientContext context;
    Status status = stub_->add(&context, m, &reply);
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
  cout << "Enter number 1 :";
  int num1;
  cin >>num1;
  
  cout << "Enter number 2 :";
  int num2;
  cin >>num2;
  
  int reply = inst.add(num1,num2);
  std::cout << "Result is: " << reply << std::endl;
  reply = inst.echo();
  std::cout << "Number of server calls is: " << reply << std::endl;

  return 0;
}
