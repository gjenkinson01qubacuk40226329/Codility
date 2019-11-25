#include "Diverse.h"

string createDiverse(int A, int B, int C)
{
	if (A < 0 || B < 0 || C < 0) {
		return "Your inputs are invalid";
	}

	string lastChar; lastChar = "";
	string stringArray[3]; stringArray[0] = "a"; stringArray[1] = "b"; stringArray[2] = "c";
	int intArray[3]; intArray[0] = A; intArray[1] = B; intArray[2] = C;


	string diverse = "";



	while (intArray[0] > 0 || intArray[1] > 0 || intArray[2] > 0)
	{

		bubbleSortArrays(stringArray, intArray);

		if (intArray[1] == 0 && intArray[2] == 0 && lastChar == stringArray[0]) {

			string s(1, (diverse.at(diverse.length() - 2)));

			if (s != lastChar && intArray[0] > 0) {
				diverse += stringArray[0];
			}

			break;
		}

		if (lastChar != stringArray[0]) {
			if (intArray[0] > 1) {
				diverse += stringArray[0];
				diverse += stringArray[0];
				intArray[0] -= 2;
			}
			else if (intArray[0] > 0) {
				diverse += stringArray[0];
				intArray[0] -= 1;
			}
			if (intArray[1] > 0) {
				diverse += stringArray[1];
				intArray[1] -= 1;
				lastChar = stringArray[1];
			}
			else {
				lastChar = stringArray[0];
			}
		}

		else if (lastChar == stringArray[0]) {
			if (intArray[1] > 0) {
				diverse += stringArray[1];
				intArray[1] -= 1;
			}
			if (intArray[0] > 0) {
				diverse += stringArray[0];
				intArray[0] -= 1;
				lastChar = stringArray[0];
			}
			else {
				lastChar = stringArray[1];
			}


		}
	}

	return diverse;
}

	void bubbleSortArrays(string stringArray[], int intArray[])
	{

		string tempString = "";
		int tempInt;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (intArray[j] < intArray[j + 1]) {
					tempInt = intArray[j];
					intArray[j] = intArray[j + 1];
					intArray[j + 1] = tempInt;

					tempString = stringArray[j];
					stringArray[j] = stringArray[j + 1];
					stringArray[j + 1] = tempString;
				}
			}

		}

	}
