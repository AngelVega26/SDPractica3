struct inputs{
	char Operacion;
	int Numero1;
	int Numero2;
};

program CALCULADORA_PROG{
	version CALCULADORA_VER{
	int SUMA(inputs)=1;
	int RESTA(inputs)=2;
	int DIVISION(inputs)=3;
	int MULTIPLI(inputs)=4;
	} = 1;
} = 0x31111111;

