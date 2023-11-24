#pragma once
class AjoNeuvo
{
public:
	int _huippunopeus;
	int _vuosi;
	int _paino;
	AjoNeuvo(int huippunopeus, int vuosi, int paino)
	{
		_huippunopeus = huippunopeus;
		_vuosi = vuosi;
		_paino = paino;
	}
};

class Auto : public AjoNeuvo
{
public:
	int _ovet;
	int _renkaat;
	Auto(int huippunopeus, int vuosi, int paino, int oviLkm, int renkLkm)
		: AjoNeuvo(huippunopeus, vuosi, paino)
	{
		_ovet = oviLkm;
		_renkaat = renkLkm;
	}
};

class HenkiloAuto : public Auto
{
public:
	int _matkustajaLkm;

	HenkiloAuto(int huippunopeus, int vuosi, int paino, int oviLkm, int renkLkm, int matkustajat)
		: Auto(huippunopeus, vuosi, paino, oviLkm, renkLkm)
	{
		_matkustajaLkm = matkustajat;
	}
};

class KuormaAuto : public Auto
{
public:
	int _maxPaino;

	KuormaAuto(int huippunopeus, int vuosi, int paino, int oviLkm, int renkLkm, int maxPaino)
		: Auto(huippunopeus, vuosi, paino, oviLkm, renkLkm)
	{
		_maxPaino = maxPaino;
	}
};

class Lentokone : public AjoNeuvo
{
public:
	int _maxKorkeus;

	Lentokone(int huippunopeus, int vuosi, int paino, int maxKorkeus)
		: AjoNeuvo(huippunopeus, vuosi, paino)
	{
		_maxKorkeus = maxKorkeus;
	}
};

class Laiva : public AjoNeuvo
{
public:
	int _maxSyvaus;

	Laiva(int huippunopeus, int vuosi, int paino, int maxSyvaus)
		: AjoNeuvo(huippunopeus, vuosi, paino)
	{
		_maxSyvaus = maxSyvaus;
	}
};