#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(int id, float limite)
{
	_id = id;
	_limite = limite;
	_saldo = 0;
}

void CuentaCorriente::Debitar(float importe)
{
	if ((_saldo - importe) > _limite)
	{
		_saldo -= importe;
	}
}

void CuentaCorriente::Acreditar(float importe)
{
	if (importe > 0) _saldo += importe;
}
