#pragma once  
#include <string>  
#include <vector>
#include <iostream>  

using namespace std;

enum tipoDeConta { contaCorrente, contaConjunta, contaJuridica, poupanca };
enum tipoDeTransacao { saque, deposito, transferencia };

class HistoricoDeTransacoes {
private:
	vector <tipoDeTransacao> transacoes;
	size_t maxTransacoes;

public:
	HistoricoDeTransacoes(size_t maxTransacoes = 100) : maxTransacoes(maxTransacoes) {};
	void adicionarTransacao(tipoDeTransacao transacao) {
		if (transacoes.size() >= maxTransacoes) {
			transacoes.erase(transacoes.begin());
		}
		transacoes.push_back(transacao);

		
	}
	const vector<tipoDeTransacao>& obterTransacoes() const {
		return transacoes;
	}

};
class ContaBancaria {
public:
	//Construtor padrão  
	ContaBancaria();
	//Destrutor  
	~ContaBancaria();

	//Métodos  
	bool abrir(int numeroConta, string numeroAgencia, string nome, string senha, tipoDeConta tipo);
	bool alteraSenha(string novaSenha, string velhaSenha);
	void depositar(float valor);
	bool sacar(float valor, string senha);
	void receberTransferencia(float valor, string nome);
	float transferir(float valor, string senha, ContaBancaria contaBancaria);
	float consultarSaldo(string senha);
	void exibirHistoricoDeTransacoes() const;
	bool Ativa() const { return ativa; }
	std::string getNomeCliente() const { return nomeCliente; }
	void fechar();

private:
	int numeroDaConta;
	string numeroDaAgencia;
	string nomeCliente;
	string senhaAtual;
	tipoDeConta tipoDaConta;
	float saldo, limites;
	bool ativa;
	HistoricoDeTransacoes historicoDetransacoes;

};
