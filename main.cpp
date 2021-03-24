#include <iostream>
#include <cstring>

using namespace std;

#define TRUE (unsigned)1
#define FALSE (unsigned)0

int cpf[] = {1,2,3,4,5,6,7,8,9,0,9}; // 123.456.789-09
//cpfformat {0,0,0,0,0,0,0,0,0,0,0};

char mode[] = "verify"; 
//modes "complete" | "verify" 

int getDigit(int cpf[], int indexA, int indexB);
int completeCPF(int cpf[]);
int verifyCPF(int cpf[]);

int main(){

	int flag = FALSE;
	if (strcmp(mode,"verify")==0){
		flag = verifyCPF(cpf);
	}
	else if (strcmp(mode,"complete")==0){
		flag = completeCPF(cpf);
	}
	return flag;
}

int getDigit(int cpf[], int indexA, int indexB){
	
	int j = 10, k = 0;
	int soma = 0;
	for (int i=indexA; i<indexB; i++){
		k = j * cpf[i];
		//cout << "k = " << k << endl;
		soma += k;
		j--; 
	}
	//cout << "soma = " << soma << endl;
	k = soma % 11;
	
	return (k==0 || k==1)? 0 : 11-k;	
}

int completeCPF(int cpf[]){

	int digit = 0;
	
	// primeiro digito verificador
	cpf[9] = getDigit(cpf,0,9);

	// segundo digito verificador
	cpf[10] = getDigit(cpf,1,10); 
	
	cout << "CPF ";
	cout << cpf[0]<<cpf[1]<<cpf[2]<<"."<<cpf[3]<<cpf[4]<<cpf[5]<<"."<<cpf[6]<<cpf[7]<<cpf[8]<<"-"<<cpf[9]<<cpf[10];
	cout << " completado." << endl;
	return TRUE;
}

int verifyCPF(int cpf[]){

	int digit = 0;
	
	// primeiro digito verificador
	digit = getDigit(cpf,0,9);
	if (digit != cpf[9]){
		cout << "CPF errado." << endl;
		return FALSE;
	}

	// segundo digito verificador
	digit = getDigit(cpf,1,10); 
	if (digit != cpf[10]){
		cout << "CPF errado." << endl;
		return FALSE;
	}	

	cout << "CPF ";
	cout << cpf[0]<<cpf[1]<<cpf[2]<<"."<<cpf[3]<<cpf[4]<<cpf[5]<<"."<<cpf[6]<<cpf[7]<<cpf[8]<<"-"<<cpf[9]<<cpf[10];
	cout << " verificado." << endl;
	return TRUE;
}
