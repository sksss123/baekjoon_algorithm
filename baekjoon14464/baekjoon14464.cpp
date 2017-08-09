#include <iostream>
#include <cstdlib>

using namespace std;

int compare(const void * first, const void * second);
int CompareStart(const void * first, const void * second);
int CompareEnd(const void * first, const void * second);

class timeOfCow{
public:
	unsigned int start, end;
	timeOfCow()
	:start(0), end(0)
	{};
};

int main()
{
	int numOfChiken, numOfCow, numOfMatching = 0;
	timeOfCow timeOfCowAcross[20000];
	unsigned int timeOfChikenHelp[20000] = {0, };

	cin >> numOfChiken >> numOfCow;
	for(int i = 0; i < numOfChiken; i++)
	{
		cin >> timeOfChikenHelp[i];
	}
	for(int i = 0; i < numOfCow; i++)
	{
		cin >> timeOfCowAcross[i].start >> timeOfCowAcross[i].end;
	}

	qsort(timeOfChikenHelp, numOfChiken, sizeof(unsigned int), compare);
	qsort(timeOfCowAcross, numOfCow, sizeof(timeOfCow), CompareStart);
	qsort(timeOfCowAcross, numOfCow, sizeof(timeOfCow), CompareEnd);

//	int startMatcing = 0;
	for(int i=0; i < numOfChiken; i++)
	{
		int j = 0;
		while(j < numOfCow /*&& timeOfChikenHelp[i] >= timeOfCowAcross[j].start*/)
		{
			if(timeOfChikenHelp[i] <= timeOfCowAcross[j].end && timeOfCowAcross[j].start <= timeOfChikenHelp[i])
			{
				timeOfCowAcross[j].start = -1;
				timeOfCowAcross[j].end = -1;
				numOfMatching++;
				break;
			}
			j++;
		}
	}
	// for (int i=0; i< numOfChiken; i++)
	// {
	// 	cout << timeOfChikenHelp[i] << endl;
	// }
	// for (int i=0; i < numOfCow; i++)
	// {
	// 	cout << timeOfCowAcross[i].start << " " << timeOfCowAcross[i].end << endl;
	// }
	cout << numOfMatching;

	return 0;
}

int compare(const void * first, const void * second)
{
	if(*(int *)first < *(int *)second)
		return -1;
	else if(*(int *)first > *(int *)second)
		return 1;
	else
		return 0;
}

int CompareStart(const void * first, const void * second)
{
	if( (*(timeOfCow *) first).start < (*(timeOfCow *) second).start )
		return -1;
	else if((*(timeOfCow *) first).start > (*(timeOfCow *) second).start)
		return 1;
	else
		return 0;
}

int CompareEnd(const void * first, const void * second)
{
	if((*(timeOfCow *) first).end < (*(timeOfCow *) second).end)
		return -1;
	else if((*(timeOfCow *) first).end > (*(timeOfCow *) second).end)
		return 1;
	else
		return 0;
}