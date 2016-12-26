#pragma once
#include "Common.h"
#include "Singleton.h"

class CodeTraining : public Singleton<CodeTraining>
{
public:
	CodeTraining();
	~CodeTraining();

public:
	void Initialize();

	std::string GetEmpty();


public:
	void Line();
	void SelectFunc();
	void TextFunc();

	void Greeting();
	void StringLength();
	void QuotationMarks();

	void Arithmetic();
	void Calc(int n1, int n2);


	void CalcRetirement();

	void PizzaParty();
	void PaintCalc();
	void Counter();
	void SimpleInterest();
	void CompoundInterest();
	void TaxCalculator();
	void PasswordCheck();
	        

public:
	// Func
	void ClearChar();
	int InputNum(std::string st);
	double DoubleValue(std::string st);
	int Convertor(char* ch);

	void OutPutQString(QString& st);
	void OutPutString(std::string st);
	void OutPutStringEndl(std::string st);
	template<typename T>
	void OutPutTempleteString(std::string st, T t);

	inline double Rounding(double& x, const int& digit);
	std::string InputString(std::string st);
	void TransformUpper(std::string& st);


	



private:
	const std::string m_emptyString = "";

public:
	char m_char[16];

};

#define  CODETRAINING() CodeTraining::GetInstance()