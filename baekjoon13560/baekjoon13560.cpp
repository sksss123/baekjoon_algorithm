#include <iostream>
#include <stdlib.h>

using namespace std;

int sumSequnce(int num);
int compare(const void* first, const void* second);

int main()
{
	int numOfTeam = 0;
	int answer = 1;
	int sumTotalTeamScore = 0;
	int answerTotalTeamScore = 0;
	int score[10000] = {0,};

	cin >> numOfTeam;
	answerTotalTeamScore = sumSequnce(numOfTeam - 1);

	for (int i = 0; i < numOfTeam; i++)
		cin >> score[i];

	qsort(score, numOfTeam, sizeof(int), compare);

	for (int i = 0; i < numOfTeam - 1; i++)
	{
		sumTotalTeamScore += score[i];
		if (sumTotalTeamScore > answerTotalTeamScore - sumSequnce(numOfTeam - 2 - i))
		{
			answer = -1;
			break;
		}
	}
	sumTotalTeamScore += score[numOfTeam - 1];
	if(sumTotalTeamScore != answerTotalTeamScore)
		answer = -1;
	cout << answer;

	return 0;
}

int sumSequnce(int num)
{
	if(num == 0)
		return 0;
	else
		return (num+1) * num / 2;
}

int compare (const void *first, const void *second)
{
	return *(int *)second - *(int *)first;
}