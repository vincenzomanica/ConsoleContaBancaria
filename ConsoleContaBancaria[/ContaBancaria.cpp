#include "ContaBancaria.h"

ContaBancaria::ContaBancaria(void)
{
	ativa = false;
	saldo = 0;
	limites = 1000;
}
ContaBancaria::~ContaBancaria(void)
{
}
bool ContaBancaria::abrir(int numeroConta, string numeroAgencia, string nome, string novaSenha, tipoDeConta tipo)
{
	if (ativa == false)
	{
		numeroDaConta = numeroConta;
		numeroDaAgencia = numeroAgencia;
		nomeCliente = nome;
		senhaAtual = novaSenha;
		tipoDaConta = tipo;
		ativa = true;
		return true;
	}
	else
		return false;
}
bool ContaBancaria::alteraSenha(string novaSenha, string velhaSenha)
{
	if (ativa == true && senhaAtual == velhaSenha)
	{
		senhaAtual = novaSenha;
		return true;
	}
	return false;
}
void ContaBancaria::depositar(float valor) {

	saldo += valor;
	HistoricoDeTransacoes historico;
	historico.adicionarTransacao(deposito);

}
bool ContaBancaria::sacar(float valor, string senha) {
	if (ativa && senha == senhaAtual)
	{
		if (valor < saldo + limites)
		{
			saldo -= valor;
			HistoricoDeTransacoes historico;
			historico.adicionarTransacao(saque);
			return true;
		}
	}
	return false;
}
void ContaBancaria::receberTransferencia(float valor, string nome)
{
	saldo += valor;
	HistoricoDeTransacoes historico;
	historico.adicionarTransacao(transferencia);
}
float ContaBancaria::consultarSaldo(string senha) {
	if (ativa && senha == senhaAtual)
	{
		return saldo;
	}
	return -1;
}
float ContaBancaria::transferir(float valor, string senha, ContaBancaria contaBancaria) {
	if (ativa == true && contaBancaria.ativa == true && saldo !=0) {
		contaBancaria.saldo += valor;
		saldo -= valor;
		historicoDetransacoes.adicionarTransacao(transferencia);
		return true;

	}
	else
		return -1;
}
void ContaBancaria::fechar() {
	ativa = false;
	saldo = 0;
	limites == 0;

}
void ContaBancaria::exibirHistoricoDeTransacoes()const {
	const vector <tipoDeTransacao>& transacoes = historicoDetransacoes.obterTransacoes();
	for (tipoDeTransacao transacao : transacoes ) {
		cout << tipoDeTransacaoParaString(transacao) << endl;

	}
}

string tipoDeTransacaoParaString(tipoDeTransacao transacao) {
	switch (transacao) {
	case deposito: return "Deposito";
	case saque: return "Saque";
	case transferencia: return "Transferencia";
	default: return "Desconhecido";
	}
}
