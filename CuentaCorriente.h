#pragma once
#include "CuentaBancaria.h"
class CuentaCorriente : public CuentaBancaria
{
private:
	float _limite;
public:
	CuentaCorriente(int id, float limite);
	void Debitar(float importe);
	void Acreditar(float importe);
	float getSaldo() {return _saldo;}
};

