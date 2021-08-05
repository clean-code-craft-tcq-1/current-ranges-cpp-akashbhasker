#include <vector>

using namespace std;


struct CurrentReadingsParameters{
	int current_min;
	int current_max;
	int number_of_readings;
};


std::vector<int> sortCurrentReadingsData (std::vector<int>& periodicCurrentSample);

void processCurrentReadingsData(std::vector<int>inputCurrentSamples, std::vector<CurrentReadingsParameters*>& currentParam_st);
