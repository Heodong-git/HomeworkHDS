#include <iostream>

class MyInt
{
	int Value = 0;

public:
	void SetValue(int _Value) { Value = _Value; }

public:
	// µ¡¼À
	MyInt operator+(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value + _other.Value;
		
		return Result;
	}

	// »¬¼À
	MyInt operator-(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value - _other.Value;

		return Result;
	}

	// ³ª´°¼À
	MyInt operator/(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value / _other.Value;

		return Result;
	}

	// °ö¼À 
	MyInt operator*(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value * _other.Value;

		return Result;
	}

	// ³ª¸ÓÁö
	MyInt operator%(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value % _other.Value;

		return Result;
	}	

	// Ãà¾àÇü
	MyInt operator+=(MyInt& _other)
	{
		Value += _other.Value;
		return *this;
	}

	MyInt operator-=(MyInt& _other)
	{
		Value -= _other.Value;
		return *this;
	}

	MyInt operator/=(MyInt& _other)
	{
		Value /= _other.Value;
		return *this;
	}

	MyInt operator*=(MyInt& _other)
	{
		Value *= _other.Value;
		return *this;
	}

	MyInt operator++()
	{
		++Value;
		return *this;
	}

	MyInt operator++(int)
	{
		Value++;
		return *this;
	}

	MyInt operator--()
	{
		--Value;
		return *this;
	}

	MyInt operator--(int)
	{
		Value--;
		return *this;
	}

	MyInt operator%=(MyInt& _other)
	{
		Value %= _other.Value;
		return *this;
	}

	// ºñ±³¿¬»êÀÚ 
	bool operator<(MyInt& _other)
	{
		return Value < _other.Value;
	}
	
	bool operator>(MyInt& _other)
	{
		return Value > _other.Value;
	}

	bool operator<=(MyInt& _other)
	{
		return Value <= _other.Value;
	}

	bool operator>=(MyInt& _other)
	{
		return Value >= _other.Value;
	}

	bool operator==(MyInt& _other)
	{
		return Value == _other.Value;
	}

	bool operator!=(MyInt& _other)
	{
		return Value != _other.Value;
	}
};

int main()
{
	// °ªµÎ°³ 
	MyInt Value;
	MyInt Value0;

	// °ª ¼¼ÆÃ
	Value.SetValue(10);
	Value0.SetValue(100);

	++Value;
	
	Value++;

	--Value;
	Value--;

	// µ¡¼À
	MyInt Result = Value + Value + Value0;
	
	// »¬¼À
	Result = Value0 - Value;
	
	// °ö¼À
	Result = Value * Value0;

	// ³ª´°¼À 
	Result = Value0 / Value;

	// ³ª¸ÓÁö
	Result = Value0 % Value;

	// Value = 10 
	// Value0 = 100
	bool Check = Value < Value0;

	Check = Value > Value0;
	Check = Value <= Value0;
	Check = Value >= Value0;
	Check = Value != Value0;
	Check = Value == Value0;

	// Ãà¾à¿¬»ê
	Value += Value0;
	Value.SetValue(10);
	
	Value -= Value0;
	Value.SetValue(10);

	Value *= Value0;
	Value.SetValue(10);

	Value /= Value0;
	Value.SetValue(10);
	
	Value %= Value0;
	Value.SetValue(10);

	int a = 0;
	return 0;
}