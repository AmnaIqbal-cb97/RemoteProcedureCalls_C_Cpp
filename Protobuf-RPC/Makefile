PROTO_FILE = message
SERVER = server
CLIENT = client2

all:
	protoc --cpp_out=. ./$(PROTO_FILE).proto
	g++ -std=c++11 `pkg-config --cflags protobuf grpc`  -c -o $(PROTO_FILE).pb.o $(PROTO_FILE).pb.cc
	protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./$(PROTO_FILE).proto
	g++ -std=c++11 `pkg-config --cflags protobuf grpc`  -c -o $(PROTO_FILE).grpc.pb.o $(PROTO_FILE).grpc.pb.cc
	g++ -std=c++11 `pkg-config --cflags protobuf grpc`  -c -o $(CLIENT).o $(CLIENT).cpp
	g++ $(PROTO_FILE).pb.o $(PROTO_FILE).grpc.pb.o $(CLIENT).o -L/usr/local/lib `pkg-config --libs protobuf grpc++` -pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl -o $(CLIENT)
	g++ -std=c++11 `pkg-config --cflags protobuf grpc`  -c -o $(SERVER).o $(SERVER).cpp
	g++ $(PROTO_FILE).pb.o $(PROTO_FILE).grpc.pb.o $(SERVER).o -L/usr/local/lib `pkg-config --libs protobuf grpc++` -pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl -o $(SERVER)
	
clean:
	sudo rm -f *.o *.pb.cc *.pb.h client1 client2 server