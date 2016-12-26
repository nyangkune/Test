#include "CodeTraining.h"
#include <sstream>
#include <algorithm>
#include "Bcrypt.h"

CodeTraining::CodeTraining(){}

CodeTraining::~CodeTraining(){}

void CodeTraining::Initialize()
{

	SelectFunc();

}

void CodeTraining::TextFunc()
{
	OutPutStringEndl("");

	OutPutStringEndl("01 : �̸��� �Է¹޾� ���");
	OutPutStringEndl("02 : ���� ���ڿ��� ���̸� ���");
	OutPutStringEndl("03 : \" , ' ���� ���");
	OutPutStringEndl("04 : ���ڸ� �Է¹޾� ���");
	OutPutStringEndl("05 : �����ϴ� �⵵ ���");
	OutPutStringEndl("06 : ���ڸ� ��������~ (�̱���)");
	OutPutStringEndl("07 : ������ �ʿ��� ����Ʈ ���ʹ��� ��");
	OutPutStringEndl("08 : ����");
	OutPutStringEndl("09 : �ܸ� ���� ���");
	OutPutStringEndl("10 : ���� ���� ���");
	OutPutStringEndl("11 : ��ǰ�� ���������� �ݾ� ���");
	OutPutStringEndl("12 : ��й�ȣ üũ");


	OutPutStringEndl("");
}

void CodeTraining::Line()
{
	OutPutStringEndl("");
	OutPutStringEndl("===============");
	OutPutStringEndl("");
}

void CodeTraining::SelectFunc()
{
	TextFunc();

	while (true)
	{
		Line();

		int num = InputNum("Select number : ");
		OutPutStringEndl("");

		switch (Select::Type(num))
		{
		case Select::Greeting:			Greeting();			break;
		case Select::StringLength:		StringLength();		break;
		case Select::QuotationMarks:	QuotationMarks();	break;
		case Select::Arithmetic:		Arithmetic();		break;
		case Select::CalcRetirement:	CalcRetirement();	break;
		case Select::PizzaParty:		PizzaParty();		break;
		case Select::PaintCalc:			PaintCalc();		break;
		case Select::Counter:			Counter();			break;
		case Select::SimpleInterest:	SimpleInterest();	break;
		case Select::CompoundInterest:	CompoundInterest();	break;
		case Select::TaxCalculator:		TaxCalculator();	break;
		case Select::PasswordCheck:		PasswordCheck();	break;
		default:
		{
			OutPutStringEndl("�߸��� ��ȣ�� �����ϼ̽��ϴ�.");

			TextFunc();

		}break;

		}
	}
}

void CodeTraining::Greeting()
{
	// �Է¹��� �̸��� ���
	ClearChar();

	OutPutString("What Ur Name : ");
	cin >> m_char;

	QString hello = QString("%1 : %2").arg("Hello").arg(QString().fromLocal8Bit(m_char));

	OutPutQString(hello);

}

void CodeTraining::StringLength()
{
	ClearChar();

	OutPutString("Input String : ");
	cin >> m_char;

	QString qString = nullptr;

	if (m_char == "/n")
	{
		qString = QString("%1").arg(QString().fromLocal8Bit("null ptr"));
	}
	else
	{
		int length = strlen(m_char);

		qString = QString("%1 : %2")
			.arg(QString().fromLocal8Bit("���ڿ��� ���̴�"))
			.arg(QString().setNum(length));

	}

	OutPutQString(qString);
}

void CodeTraining::QuotationMarks()
{
	QString qString = QString("%1").arg(QString().fromLocal8Bit("\"  ' ��? ' \""));

	OutPutQString(qString);
}

void CodeTraining::Arithmetic()
{
	int n1 = InputNum("Input number : ");

	int n2 = InputNum("Input number : ");

	if (n1 != 0 && n2 != 0)
	{
		Calc(n1, n2);
	}
	
}

void CodeTraining::Calc(int n1, int n2)
{
	cout << endl;
	cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
	cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
	cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;
	cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;

}

void CodeTraining::CalcRetirement()
{
	int age = InputNum("Now Age ? : ");

	int retireAge = InputNum("Retire Age : ");

	int restYear = retireAge - age;

	if (restYear < 0)
	{
		OutPutStringEndl("Wrong number Check and ReTry");

		return;
	}

	cout << "You have " << restYear << "year" << endl;
	
	QDate nowDate = QDate::currentDate();
	
	QDate retireDate = nowDate.currentDate().addYears(restYear);

	QString retirement = QString("[ It`s : %1 ], [ Retire Day in %2 ]")
		.arg(nowDate.toString("yy"))
		.arg(retireDate.toString("yy"));
		
	OutPutQString(retirement);

}

void CodeTraining::PizzaParty()
{
	int people = InputNum("���ڸ� �Դ� �������? :");
	int havePizza = InputNum("��� �����ų�??? :");

	int perHavePizza = havePizza * 100;
	
	int pieces = InputNum("���������� �ڸ�����?? :");
	int perpieces = pieces * 100;

	if (pieces < havePizza)
	{
		OutPutStringEndl("�������� �ϴ� ���� �� ũ��");
		return;
	}

	float rest = (float)perpieces / (float)perHavePizza;
}

void CodeTraining::PaintCalc()
{	
	int roomSize = InputNum("���� ������?? ������ ���� X ���� ���� �Է� : ");

	// 1���Ϳ� 9m^2 �� ���� �Է��Ѵٸ�.
	const int paint = 9;

	if (roomSize < paint)
	{
		OutPutStringEndl("�ʿ��� ����Ʈ ���ʹ� : 1");
	}
	else
	{
		// �ʿ��� ����Ʈ ��
		int needPaint = roomSize / paint;

		if ((roomSize % paint) > 0)
		{
			needPaint++;
		}

		OutPutTempleteString("�ʿ��� ����Ʈ�� : ", needPaint);
	}
}

void CodeTraining::Counter()
{
	int addPrice = 0;
	const double tax = 5.5;

	int idx = 1;

	while (idx <= 3)
	{
		int price = InputNum(" ��ǰ���� : ");

		int count = InputNum(" ��ǰ���� : ");

		addPrice += price * count;

		idx++;
	}


	double total_tax = ((double)addPrice * tax) / 100;
	total_tax = Rounding(total_tax, 3);

	double totalPrice = addPrice + total_tax;


	OutPutTempleteString("������ �Ѱ��� : ", addPrice);
	OutPutTempleteString("Tax : ", total_tax);
	OutPutTempleteString("�������� ����ؾ��ҵ� : ", totalPrice);

}

void CodeTraining::SimpleInterest()
{
	// �Ⱓ�� 1�� ����
	// ������ = ���� + ( ���� * ������ * �Ⱓ )
	auto payment = DoubleValue("���� : ");

	auto interest = DoubleValue("������ : ");

	auto period = DoubleValue("�Ⱓ : ");


	double result = payment + (payment * (interest * PreDefine::p_Percentage) * period) / PreDefine::p_Percentage;

	OutPutTempleteString("������ : ", result);

}

void CodeTraining::CompoundInterest()
{

}

void CodeTraining::TaxCalculator()
{
	double amount = DoubleValue("��ǰ������ �Է����ּ��� : ");

	std::string area = InputString("��°��� �Է��Ͻÿ� : ");

	const double tax = 0.5;

	TransformUpper(area);
	double percent = (amount * tax) / 100;
	double resultTax = Rounding(percent, 3);

	double resultAmount = amount + resultTax;

	if (area.find("WI") == string::npos)
	{
		//Ÿ����
		OutPutTempleteString("�Ѱ��� : ", resultAmount);
	}
	else
	{
		OutPutStringEndl("WI �� ������� 0.5% �� ������ �ο��մϴ�.");
		OutPutTempleteString("�Ѱ��� : ", resultAmount);
	}


}

void CodeTraining::PasswordCheck()
{
	std::string password = InputString("��й�ȣ �Է� : ");

	int result = password.compare(PreDefine::p_Password);

	if (result == 0)
	{
		OutPutStringEndl("Welcome!!");
	}
	else
	{
		OutPutStringEndl("Worng password");
	}

}


///////////////////////////////// Func

double CodeTraining::DoubleValue(std::string st)
{	
	string num = GetEmpty();
	OutPutString(st);
	cin >> num;

	stringstream convertor;
	double res = 0.0;

	convertor << num;
	convertor >> res;
	while (1)
	{
		if (convertor.fail())
			OutPutStringEndl("�Ǽ� �� �Է����ּ��� ex) 2.2 , 2 ");
		else
			break;
	}

	return res;
}


int CodeTraining::InputNum(std::string st)
{	
	ClearChar();

	OutPutString(st);
	cin >> m_char;

	int res = Convertor(m_char);

	return res;
}


int CodeTraining::Convertor(char* ch)
{
	stringstream convertor;

	int res = 0;

	convertor << ch;
	convertor >> res;

	if (convertor.fail())
	{	
		res = InputNum("Try Check Number");
	}

	return res;
}

inline double CodeTraining::Rounding(double& x, const int& digit)
{
	// digit �� �ڸ��� pow(float(10), digit) = 10^3 �� ��ŭ x ���� ���ϸ� ex)123.1235 -> 123123.5
	// 123123.5 + 0.5 = 1231235.0
	// floor �Լ����� �ڸ��� �Ҽ������� ���� 1231235 / pow(float(10), digit) = 10^3
	// return 123.1235  
	return (floor((x)* pow(float(10), digit) + 0.5f) / pow(float(10), digit));
}

void CodeTraining::OutPutQString(QString& st)
{
	puts(st.toLocal8Bit());
}

void CodeTraining::OutPutString(std::string st)
{
	cout << st;
}

void CodeTraining::OutPutStringEndl(std::string st)
{
	cout << st << endl;
}

template<typename T>
void CodeTraining::OutPutTempleteString(std::string st, T t)
{
	cout << st << t << endl;
}

std::string CodeTraining::GetEmpty()
{
	return m_emptyString;
}

void CodeTraining::ClearChar()
{
	ZeroMemory(m_char, sizeof(m_char));
}

std::string CodeTraining::InputString(std::string st)
{
	string input = GetEmpty();
	OutPutString(st);
	cin >> input;

	return input;
}

void CodeTraining::TransformUpper(std::string& st)
{
	std::transform(st.begin(), st.end(), st.begin(), ::toupper);
}