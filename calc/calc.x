struct inputs{
	float a;
	float b;
	char op;
};
program calc_prog{
version calc_vers{
	float calculator(inputs)=1;
}=1;
}=0x22222222;
