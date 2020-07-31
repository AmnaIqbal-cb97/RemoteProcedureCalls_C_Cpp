///////////////////////////////////////Code developed and Contributed by Muhammad Hamza (mhamzai)//////////////////////////////////
///////////////////////Use allowed in opensource projects only by fairuse and giving due credits to the developer//////////////////
#include <iostream>
using namespace std;
#include <cxxtools/arg.h>
#include <cxxtools/remoteprocedure.h>
#include <cxxtools/json/rpcclient.h>

int main(int argc, char* argv[])
{
    cxxtools::Arg<std::string> ip(argc, argv, 'i');
    cxxtools::Arg<unsigned short> port(argc, argv, 'p', 8080);
    cxxtools::json::RpcClient client(ip, port);
    cxxtools::RemoteProcedure<int, int, int> add(client, "add");
    cxxtools::RemoteProcedure<int> echo(client, "echo");

	int a,b;
	cout << "Enter number 1: ";
	cin >> a;
	cout << "Enter number 2: ";
	cin >> b;

    // and now call the remote function
    int result = add(a,b);

    cout << result << endl;
	int total = echo();
	cout<<"Total calls to server : "<< total<<endl;
	return 0;

}
