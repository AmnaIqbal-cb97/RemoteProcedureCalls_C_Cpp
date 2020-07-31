///////////////////////////////////////Code developed and Contributed by Muhammad Hamza (mhamzai)//////////////////////////////////
///////////////////////Use allowed in opensource projects only by fairuse and giving due credits to the developer//////////////////
#include <stdio.h>
#include <xmlrpc.h>
#include <xmlrpc_server.h>
#include <xmlrpc-c/server_abyss.h>
static int total=0;
static xmlrpc_value *
sum(xmlrpc_env * const envP, xmlrpc_value * const paramArrayP, void * const serverContext) 
{

    xmlrpc_int32 x, y;

    xmlrpc_parse_value(envP, paramArrayP, "(ii)", &x, &y);
    x = x + y;
	total=total+1;
    return xmlrpc_build_value(envP, "i", x);
}

static xmlrpc_value *
echo(xmlrpc_env * const envP, xmlrpc_value * const paramArrayP, void * const serverContext) 
{

    xmlrpc_int32 x;
    x = (xmlrpc_int32)total;
    return xmlrpc_build_value(envP, "i", x);
}


int main (int const argc, const char ** const argv) {

    xmlrpc_server_abyss_parms parameter;
    xmlrpc_registry * registryP;
    xmlrpc_env env;
    xmlrpc_env_init(&env);

    registryP = xmlrpc_registry_new(&env);

    xmlrpc_registry_add_method(&env, registryP, NULL, "sum.add", &sum, NULL);
	xmlrpc_registry_add_method(&env, registryP, NULL, "echo.s", &echo, NULL);
    parameter.config_file_name = argv[1];
    parameter.registryP = registryP;

    printf("Starting XML RPC server...\n\n");
	printf("Server is running ... :)\n");
    xmlrpc_server_abyss(&env, &parameter, XMLRPC_APSIZE(registryP));
	
    return 0;
}
