#include "CajaAhorro.h"

CajaAhorro::CajaAhorro(int id)
{
	_id = id;
	_saldo = 0;
}

void CajaAhorro::Debitar(float importe)
{
	if (importe > 0 && (_saldo - importe) > 0)
	{
		_saldo -= importe;
	}
}

void CajaAhorro::Acreditar(float importe)
{
	if (importe > 0) _saldo += importe;
}
