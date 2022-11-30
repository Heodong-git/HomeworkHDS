#include <iostream>

class MyInt
{
	int Value = 0;

public:
	void SetValue(int _Value) { Value = _Value; }

public:
	// ����
	MyInt operator+(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value + _other.Value;
		
		return Result;
	}

	// ����
	MyInt operator-(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value - _other.Value;

		return Result;
	}

	// ������
	MyInt operator/(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value / _other.Value;

		return Result;
	}

	// ���� 
	MyInt operator*(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value * _other.Value;

		return Result;
	}

	// ������
	MyInt operator%(MyInt& _other)
	{
		MyInt Result;
		Result.Value = this->Value % _other.Value;

		return Result;
	}	

	// �����
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

	// �񱳿����� 
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
	// ���ΰ� 
	MyInt Value;
	MyInt Value0;

	// �� ����
	Value.SetValue(10);
	Value0.SetValue(100);

	++Value;
	
	Value++;

	--Value;
	Value--;

	// ����
	MyInt Result = Value + Value + Value0;
	
	// ����
	Result = Value0 - Value;
	
	// ����
	Result = Value * Value0;

	// ������ 
	Result = Value0 / Value;

	// ������
	Result = Value0 % Value;

	// Value = 10 
	// Value0 = 100
	bool Check = Value < Value0;

	Check = Value > Value0;
	Check = Value <= Value0;
	Check = Value >= Value0;
	Check = Value != Value0;
	Check = Value == Value0;

	// ��࿬��
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