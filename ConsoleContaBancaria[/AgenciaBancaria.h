#pragma once
#include <string>
#include <iostream>	
#include "ContaBancaria.h"
#include <map>
using namespace std;

class AgenciaBancaria

{
private:
	map<int, ContaBancaria> contas;
	string nomeAgencia;
	static int proximoNumeroConta;
	string senhaAdministrador;

public:

	AgenciaBancaria(string nomeAgenica, string senhaAdminstrador);
	~AgenciaBancaria();
	bool abrirConta(string nomeCliente, string senha, tipoDeConta tipo);
	bool fecharConta(int numeroConta);
	ContaBancaria* obterConta(int numeroConta);
	void exibirContas(string senhaAdministrador);
};



