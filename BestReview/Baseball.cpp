#include <stdexcept>
#include <string>

struct Result
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(std::string guessNum) : question(guessNum) {}

	Result guess(std::string str)
	{
		AssertIllegalArgument(str);

		if(str == question)
		{
			return Result({ true,3,0 });
		}

		return { false, getStrikeCnt(str) ,getBallCnt(str) };
	}

private:
	int getStrikeCnt(std::string str)
	{
		int strike = 0;
		for(int i = 0;i < str.length();i++)
		{
			int idx = question.find(str[i]);
			if(idx == -1) continue;
			if (idx == i) strike++;
		}
		return strike;
	}

	int getBallCnt(std::string str)
	{
		int ball = 0;
		for(int i = 0;i < str.length();i++)
		{
			int idx = question.find(str[i]);
			if(idx == -1) continue;
			if (idx == i) continue;
			ball++;
		}
		return ball;
	}

	bool IsDuplicated(std::string str)
	{
		return str[0] == str[1] || str[0] == str[2] || str[2] == str[1];
	}

	bool IsIncludeChar(std::string str)
	{
		for(auto c : str)
		{
			if((c >= '0' && c <= '9')) continue;
			return true;
		}
		return false;
	}

	void AssertIllegalArgument(std::string str)
	{
		if (str == "")
			throw std::invalid_argument("값을 입력하시오");
		if (str.length() != 3)
			throw std::invalid_argument("숫자 3개를 넣어주세요");

		if(IsIncludeChar(str))
			throw std::invalid_argument("숫자만 써주세요");

		if(IsDuplicated(str))
			throw std::invalid_argument("중복수 금지");
	}
private:
	std::string question;
};
