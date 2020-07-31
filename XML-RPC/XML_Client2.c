///////////////////////////////////////Code developed and Contributed by Muhammad Hamza (mhamzai)//////////////////////////////////
///////////////////////Use allowed in opensource projects only by fairuse and giving due credits to the developer//////////////////
#include <stdio.h>
#include <xmlrpc.h>
#include <xmlrpc-c/base.h>
#include <xmlrpc_client.h>

int main(int const argc, const char ** const argv) {

    xmlrpc_env env;
    xmlrpc_value *total;
    int sum;
    char * const name = "XML Client";
    char * const vers = "1.0";
    char * const url = "http://localhost:8080/RPC2";
    char * const procedure = "echo.s";
    xmlrpc_env_init(&env);

    
    xmlrpc_client_init2(&env, XMLRPC_CLIENT_NO_FLAGS, name, vers, NULL, 0);
    
    total = xmlrpc_client_call(&env, url, procedure,
                 "(ii)");
    
    xmlrpc_parse_value(&env, total, "i", &sum);
	printf("Total calls to live server : %d\n",sum);
    
xmlrpc_DECREF(total);

    
    xmlrpc_env_clean(&env);
    
    
    xmlrpc_client_cleanup();

    return 0;
}

