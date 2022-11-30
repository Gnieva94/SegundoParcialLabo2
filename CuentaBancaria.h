#pragma once
class CuentaBancaria
{
protected:
	int _id;
	float _saldo;
public:
	//METODOS DE CLASE
	void setId(int id) { _id = id; }
	void setSaldo(float saldo) { _saldo = saldo; }
	int getId() { return _id; }
	float getSaldo() { return _saldo; }
};

