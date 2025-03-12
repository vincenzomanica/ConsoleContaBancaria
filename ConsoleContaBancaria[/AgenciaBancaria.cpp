#include "AgenciaBancaria.h"
#include "ContaBancaria.h"

AgenciaBancaria::AgenciaBancaria(std::string nomeAgencia, string senhaAdministrador) : nomeAgencia(nomeAgencia),  senhaAdministrador(senhaAdministrador) {}

AgenciaBancaria::~AgenciaBancaria() {}

bool AgenciaBancaria::abrirConta(std::string nomeCliente, std::string senha, tipoDeConta tipo)
{
	int numeroConta = proximoNumeroConta++;
	ContaBancaria conta;
	if (conta.abrir(numeroConta, nomeAgencia, nomeCliente, senha, tipo))
	{
		contas[numeroConta] = conta;
		return true;
	}
	else
		return false;

}
bool AgenciaBancaria::fecharConta(int numeroConta)
{
	auto it = contas.find(numeroConta);
	if (it != contas.end())
	{
		it->second.fechar();
		contas.erase(it);
		return true;
	}
	else
		return false;
}
ContaBancaria* AgenciaBancaria::obterConta(int numeroConta) {
	auto it = contas.find(numeroConta);
	if (it != contas.end())
		return &it->second;
	else
		return nullptr;

}


void AgenciaBancaria::exibirContas(string senhaAdministrador) {
	for (const auto& conta : contas) {
		if (conta.second.Ativa()) {
			std::cout << "Conta: " << conta.first << " - " << conta.second.getNomeCliente() << std::endl;
		}
	}
