#include <iostream>
#include <cstdlib>

using namespace std;

class facility
{
public:
	int location;
	int type;
	facility() : location(0), type(0)
	{};
};

int compare(const void* first, const void* second)
{
	return ((facility *) first)->location - ((facility *) second)->location;
}

int main()
{
	int numOfType, numOfFacility;
	int numOfEachType[100000] = {0,};
	facility* facilityLine;
	int type;
	cin >> numOfType >> numOfFacility;

	facilityLine = new facility[numOfFacility];
	for(int i=0; i < numOfFacility; i++)
	{
		cin >> facilityLine[i].location >> facilityLine[i].type;
		numOfEachType[facilityLine[i].type]++;
	}

	qsort(facilityLine, numOfFacility, sizeof(facility), compare);

	int first=0, last=numOfFacility-1;
	
	while(numOfEachType[facilityLine[first].type] > 1 && numOfEachType[facilityLine[last].type] > 1)
	{
		if(facilityLine[first+1].location - facilityLine[first].location > facilityLine[last].location - facilityLine[last-1].location)
		{
			numOfEachType[facilityLine[first].type]--;
			first++;
		}
		else
		{
			numOfEachType[facilityLine[last].type]--;
			last--;
		}
	}

	while(numOfEachType[facilityLine[first].type] > 1)
	{
		numOfEachType[facilityLine[first].type]--;
		first++;
	}

	while(numOfEachType[facilityLine[last].type] > 1)
	{
		numOfEachType[facilityLine[last].type]--;
		last--;
	}

	cout << (facilityLine[last].location - facilityLine[first].location)/2;

	delete facilityLine;
	return 0;
}