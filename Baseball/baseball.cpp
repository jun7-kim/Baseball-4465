#include <stdexcept>
#include <string>

using namespace std;

struct Result
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball(const string& questsion)
		: questsion(questsion)
	{
	}

	bool isDuplicatedNumber(string guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	bool isIncludeChar(const string& guessNumber)
	{
		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	void assertIllegalArgument(string guessNumber)
	{
		if (guessNumber == "")
		{
			throw invalid_argument("No input");
		}
		if (guessNumber.length() != 3) {
			throw invalid_argument("More than three number");
		}
		if (isIncludeChar(guessNumber))
		{
			throw invalid_argument("Should be number only");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Duplicated number");
		}
	}

	int getStrikeNumber(string guessNumber)
	{
		int result = 0;
		for (int i = 0;i < 3;i++)
		{
			int t = 0;
			int f = 0;
			int index = questsion.find(guessNumber[i]);
			if (index == -1)	continue;

			if (i == index)
			{
				result++;
			}
		}
		return result;
	}

	int getBallNumber(string guessNumber)
	{
		int result = 0;
		for (int i = 0;i < 3;i++)
		{
			int t = 0;
			int f = 0;
			int index = questsion.find(guessNumber[i]);
			if (index == -1)	continue;

			if (i != index)
			{
				result++;
			}
		}
		return result;
	}

	Result guess(string guessNumber)
	{
		assertIllegalArgument(guessNumber);

		if (guessNumber == questsion)
		{
			return { true,3,0 };
		}

		int scnt = getStrikeNumber(guessNumber);
		int bcnt = getBallNumber(guessNumber);
		return { false, scnt, bcnt };
	}
private:
	string questsion;
public:


};
