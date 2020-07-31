#include <stdio.h>
#include <xmlrpc.h>
#include <xmlrpc-c/base.h>
#include <xmlrpc_client.h>
int main(int const argc, const char ** const argv) {

    xmlrpc_env env;
    xmlrpc_value * ans,*total;
    int sum;
    char * const name = "XML Client";
    char * const vers = "1.0";
    char * const url = "http://localhost:8080/RPC2";
    char * const procedure1 = "sum.add";
    char * const procedure2 = "echo.s";
    int a,b;
	printf("Enter number 1: ");
	scanf("%d",&a);
	printf("Enter number 2: ");
	scanf("%d",&b);
    
    xmlrpc_env_init(&env);

    
    xmlrpc_client_init2(&env, XMLRPC_CLIENT_NO_FLAGS, name, vers, NULL, 0);
    
    
    ans = xmlrpc_client_call(&env, url, procedure1,
                 "(ii)", (xmlrpc_int32) a, (xmlrpc_int32) b);
    total = xmlrpc_client_call(&env, url, procedure2,
                 "(ii)");
    
    xmlrpc_parse_value(&env, ans, "i", &sum);

    printf("The sum  is %d\n", sum);
    xmlrpc_parse_value(&env, total, "i", &sum);
	printf("Total calls to live server : %d\n",sum);
    
    xmlrpc_DECREF(ans);
	xmlrpc_DECREF(total);

    
    xmlrpc_env_clean(&env);
    
    
    xmlrpc_client_cleanup();

    return 0;
}

