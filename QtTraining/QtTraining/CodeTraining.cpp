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

	OutPutStringEndl("01 : 이름을 입력받아 출력");
	OutPutStringEndl("02 : 받은 문자열의 길이를 출력");
	OutPutStringEndl("03 : \" , ' 문자 출력");
	OutPutStringEndl("04 : 숫자를 입력받아 계산");
	OutPutStringEndl("05 : 은퇴하는 년도 계산");
	OutPutStringEndl("06 : 피자를 나눠먹자~ (미구현)");
	OutPutStringEndl("07 : 면적에 필요한 페인트 리터단위 수");
	OutPutStringEndl("08 : 계산대");
	OutPutStringEndl("09 : 단리 이자 계산");
	OutPutStringEndl("10 : 복리 이자 계산");
	OutPutStringEndl("11 : 물품에 세금포함한 금액 계산");
	OutPutStringEndl("12 : 비밀번호 체크");


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
			OutPutStringEndl("잘못된 번호를 선택하셨습니다.");

			TextFunc();

		}break;

		}
	}
}

void CodeTraining::Greeting()
{
	// 입력받은 이름을 출력
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
			.arg(QString().fromLocal8Bit("문자열의 길이는"))
			.arg(QString().setNum(length));

	}

	OutPutQString(qString);
}

void CodeTraining::QuotationMarks()
{
	QString qString = QString("%1").arg(QString().fromLocal8Bit("\"  ' 뭐? ' \""));

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
	int people = InputNum("피자를 먹는 사람수는? :");
	int havePizza = InputNum("몇개를 먹을거냐??? :");

	int perHavePizza = havePizza * 100;
	
	int pieces = InputNum("몇조각으로 자를거임?? :");
	int perpieces = pieces * 100;

	if (pieces < havePizza)
	{
		OutPutStringEndl("먹으려고 하는 수가 더 크다");
		return;
	}

	float rest = (float)perpieces / (float)perHavePizza;
}

void CodeTraining::PaintCalc()
{	
	int roomSize = InputNum("방의 면적은?? 면적은 가로 X 세로 값을 입력 : ");

	// 1리터에 9m^2 의 값을 입력한다면.
	const int paint = 9;

	if (roomSize < paint)
	{
		OutPutStringEndl("필요한 페인트 리터는 : 1");
	}
	else
	{
		// 필요한 페인트 수
		int needPaint = roomSize / paint;

		if ((roomSize % paint) > 0)
		{
			needPaint++;
		}

		OutPutTempleteString("필요한 페인트수 : ", needPaint);
	}
}

void CodeTraining::Counter()
{
	int addPrice = 0;
	const double tax = 5.5;

	int idx = 1;

	while (idx <= 3)
	{
		int price = InputNum(" 상품가격 : ");

		int count = InputNum(" 상품갯수 : ");

		addPrice += price * count;

		idx++;
	}


	double total_tax = ((double)addPrice * tax) / 100;
	total_tax = Rounding(total_tax, 3);

	double totalPrice = addPrice + total_tax;


	OutPutTempleteString("물건의 총가격 : ", addPrice);
	OutPutTempleteString("Tax : ", total_tax);
	OutPutTempleteString("세금포함 계산해야할돈 : ", totalPrice);

}

void CodeTraining::SimpleInterest()
{
	// 기간은 1년 단위
	// 원리금 = 원금 + ( 원금 * 연이율 * 기간 )
	auto payment = DoubleValue("원금 : ");

	auto interest = DoubleValue("년이율 : ");

	auto period = DoubleValue("기간 : ");


	double result = payment + (payment * (interest * PreDefine::p_Percentage) * period) / PreDefine::p_Percentage;

	OutPutTempleteString("원리금 : ", result);

}

void CodeTraining::CompoundInterest()
{

}

void CodeTraining::TaxCalculator()
{
	double amount = DoubleValue("상품가격을 입력해주세요 : ");

	std::string area = InputString("사는곳을 입력하시오 : ");

	const double tax = 0.5;

	TransformUpper(area);
	double percent = (amount * tax) / 100;
	double resultTax = Rounding(percent, 3);

	double resultAmount = amount + resultTax;

	if (area.find("WI") == string::npos)
	{
		//타지역
		OutPutTempleteString("총가격 : ", resultAmount);
	}
	else
	{
		OutPutStringEndl("WI 주 사람들은 0.5% 의 세금을 부여합니다.");
		OutPutTempleteString("총가격 : ", resultAmount);
	}


}

void CodeTraining::PasswordCheck()
{
	std::string password = InputString("비밀번호 입력 : ");

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
			OutPutStringEndl("실수 를 입력해주세요 ex) 2.2 , 2 ");
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
	// digit 는 자리수 pow(float(10), digit) = 10^3 승 만큼 x 값에 곱하면 ex)123.1235 -> 123123.5
	// 123123.5 + 0.5 = 1231235.0
	// floor 함수에서 자리수 소수점이하 버림 1231235 / pow(float(10), digit) = 10^3
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