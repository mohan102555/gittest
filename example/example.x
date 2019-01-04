const BUFFER_SIZE=1024;
struct doubles{
	double a;
	double b;
};
struct strings{
	char src[BUFFER_SIZE];
	char dst[BUFFER_SIZE];
};
program example_prog{
version example_vers{
int fact(int)=1;
double power(doubles)=2;
string strconc(strings)=3;
}=1;
}=0x11111111;
