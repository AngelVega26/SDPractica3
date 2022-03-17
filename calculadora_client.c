#include "calculadora.h"
 
 
int calculadora_prog_1(char *host,int Numero1,int Numero2,char Operacion,CLIENT *clnt)
{
  
 int *result_1;
 inputs suma_1_arg;
 int *result_2;
 inputs resta_1_arg;
 int *result_3;
 inputs division_1_arg;
 int *result_4;
 inputs multipli_1_arg;
 
if(Operacion=='+')
{

 suma_1_arg.Numero1 = Numero1;
 suma_1_arg.Numero2 = Numero2;
 suma_1_arg.Operacion = Operacion;

 result_1 = suma_1(&suma_1_arg, clnt);
 if (result_1 == (int *) NULL) 

 {
 clnt_perror (clnt, "call failed");
 }

 return *result_1;
}	else if(Operacion=='-')
	{
 
	 resta_1_arg.Numero1 = Numero1;
 	 resta_1_arg.Numero2 = Numero2;
 	 resta_1_arg.Operacion = Operacion;
  
 	result_2 = resta_1(&resta_1_arg, clnt);
 	if (result_2 == (int *) NULL) 

 	{
 	clnt_perror (clnt, "call failed");
 	}

 	return *result_2;
	}	else if(Operacion=='*')
		{
 
		 multipli_1_arg.Numero1 = Numero1;
 	 	 multipli_1_arg.Numero2 = Numero2;
 	 	 multipli_1_arg.Operacion = Operacion;
  
 		result_3 = multipli_1(&multipli_1_arg, clnt);
 		if (result_3 == (int *) NULL) 

 		{
 		clnt_perror (clnt, "call failed");
 		}

 		return *result_3;
		}	else if(Operacion=='/')
			{
 
			 division_1_arg.Numero1 = Numero1;
			 division_1_arg.Numero2 = Numero2;
			 division_1_arg.Operacion = Operacion;
  
 				if(Numero2 == 0)

 				{
				 printf("Divicion invalida.\n");
				 exit(0);
 				}else
 					{

 					result_4 = division_1(&division_1_arg, clnt);
 						if (result_4 == (int *) NULL) 

 						{
 						clnt_perror (clnt, "call failed");
 							}
 							return *result_4;
 							}
						}
}
 


int main (int argc, char *argv[])
{
 char *host;
 int Numero1, Numero2;
 char Operacion;
 CLIENT *clnt;
 
 if (argc < 2) {
 printf ("usage: %s server_host\n", argv[0]);
 exit (1);
 }
  
 printf("Calculadora Distribuida\n");
 printf("(+) Suma\n(-)Resta\n(/)Division\n(*)Multiplicacion\n");
 printf("Operacion a realizar: \n");
 scanf("%s",&Operacion);
 printf("Ingresa los numeros para realizar la opeacion seleccionada :) \n");
 printf("Numero 1: \n");
 scanf("%d",&Numero1);
 printf("Numero 2: \n");
 scanf("%d",&Numero2);
 
  
 host = argv[1];
  
 clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VER, "udp");
  
 if (clnt == NULL) {
 clnt_pcreateerror (host);
 exit (1);
 }
  
 printf("Respuesta Final = %d\n",calculadora_prog_1 (host,Numero1,Numero2,Operacion,clnt));
  
 clnt_destroy (clnt);
  
exit (0);
}