#pragma once
#include "CuentaBancaria.h"
class CajaAhorro : public CuentaBancaria
{
public:
	CajaAhorro(int id);
	void Debitar(float importe);
	void Acreditar(float importe);
	float getSaldo() { return _saldo; }
};

