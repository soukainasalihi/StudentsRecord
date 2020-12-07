/*
*  Student: Soukaina Salihi
*  Course: CIT-284 Advanced C++/OOP
*  
*/
#include<iostream>
#include <iomanip>
#include<conio.h>
#include<cstdlib>
#include <string>
#include <fstream>

using namespace std;
struct student
{
	string name;
	string year;
	string major;
	int test[10];
	double mean;
	int median;
	string mode;
	double deviation;


}temp, student[10] =

{ "Sally Smith", "Freshman", "History", {}, 0, 0, "", 0,
"John Jones", "Junior", "Economics", {}, 0, 0, "", 0,
"Barbara Josh", "Senior", "Linguistics", {}, 0, 0, "", 0,
"Marla Wilson", "Freshman", "Literature", {}, 0, 0, "", 0,
"Edward Thom", "Junior", "Music", {}, 0, 0, "", 0,
"Mary Dany", "Junior", "Philosophy", {}, 0, 0, "", 0,
"Jihan Chow", "Senior", "Engineering ", {}, 0, 0, "", 0,
"Jullie Marc", "Freshman", "Biology", {}, 0, 0, "", 0,
"Ellisio Bruno", "Senior", "Geology", {}, 0, 0, "", 0,
"Jessica Thomy", "Junior", "Fine Arts", {}, 0, 0, "", 0,
};

ofstream outputFile;
string outputFileName;

int main(){

	outputFile.open("StudentsRecordes.txt");

	unsigned seed = time(0);
	srand(seed);

	for (int x = 0; x < 10; x++){
		for (int i = 0; i < 10; i++){

			student[x].test[i] = rand() % 100 + 1; // random function 
		}
	}

	for (int x = 0; x < 10; x++){

		int frequency[10] = { 0 };
		int frequentValues[10] = { 0 };
		for (int i = 0; i < 10; i++){
			for (int y = 0; y<10 - 1; y++){
				if (student[x].test[y]>student[x].test[y + 1]){
					int temp1 = student[x].test[y + 1];
					student[x].test[y + 1] = student[x].test[y];
					student[x].test[y] = temp1;
				}
			}
		}

		//////////////Mean/////////////

		double total = 0;
		for (int i = 0; i < 10; i++){
			total += student[x].test[i];
		}
		student[x].mean = total / 10;

		//////////////////Find Freqency////////////////////
		int size = 0;
		for (int i = 0; i < 10; i++) {

			int found = 0;
			for (int j = 0; j < i; j++) {
				if (student[x].test[i] == student[x].test[j]) found++;
			}

			if (found == 0) {

				int count = 1;

				for (int j = i + 1; j < 10; j++) {
					if (student[x].test[i] == student[x].test[j]) count++;
				}
				frequency[size] = count;
				frequentValues[size] = student[x].test[i];
				//	cout << right << setw(3) << student[x].test[i];
				size++;
			}
		}

		///////////Find modes///////////
		int maxVal = 1;
		for (int i = 0; i < size; i++)
		{
			if (frequency[i] > maxVal)
				maxVal = frequency[i];
		}


		for (int i = 0; i < size; i++)
		{
			if (maxVal == 1){
				student[x].mode = to_string(int(student[x].mean));
				break;
			}
			else if (frequency[i] == maxVal){
				student[x].mode += to_string(int(frequentValues[i])) + "  ";
			}
			//////////  Find adjecent ///////////////
			else if (frequency[i] == maxVal && frequency[i + 1] == maxVal){
				if (frequentValues[i + 1] - frequentValues[i] == 1){
					student[x].mode = frequentValues[i] + frequentValues[i + 1] / 2;

				}
			}

		}
		///////////////// Median////////////
		student[x].median = (student[x].test[4] + student[x].test[5]) / 2;

		///////////Standard deviation///////
		double total2 = 0;
		for (int i = 0; i < 10; i++)
		{
			total2 += pow(student[x].test[i] - student[x].mean, 2);
		}
		student[x].deviation = sqrt(total2 / 10);


	}



	cout << "\t\t\t Students Academic Records\n\n";

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (student[i].deviation > student[j].deviation)
			{
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
		}
		cout << left
			<< setw(21) << "\nStudent Name  :"
			<< setw(20) << student[i].name << endl
			<< setw(20) << "Student class :"
			<< setw(20) << student[i].year << endl
			<< setw(20) << "student major :"
			<< setw(20) << student[i].major << endl;

		outputFile << left
			<< setw(21) << "\nStudent Name  :"
			<< setw(20) << student[i].name << endl
			<< setw(20) << "Student class :"
			<< setw(20) << student[i].year << endl
			<< setw(20) << "student major :"
			<< setw(20) << student[i].major << endl;


		cout << setw(20) << "Test scores   :";
		outputFile << setw(20) << "Test scores   :";

		for (int y = 0; y < 10; y++){
			cout << left << setw(4) << student[i].test[y];
			outputFile << left << setw(4) << student[i].test[y];

		}
		cout << setw(21) << "\nThe mean      :"
			<< left << setw(20) << setprecision(2) << fixed << student[i].mean;
		outputFile << setw(21) << "\nThe mean      :"
			<< left << setw(20) << setprecision(2) << fixed << student[i].mean;

		cout << setw(21) << "\nThe mode      :" << student[i].mode << "  ";
		outputFile << setw(21) << "\nThe mode      :" << student[i].mode << "  ";

		cout << setw(21) << "\nThe median    :" << left << setprecision(2) << setw(20) << student[i].median;
		outputFile << setw(21) << "\nThe median    :" << left << setprecision(2) << setw(20) << student[i].median;


		cout << setw(21) << "\nThe deviation :" << left << setw(20) << student[i].deviation;
		outputFile << setw(21) << "\nThe deviation :" << left << setw(20) << student[i].deviation << endl << endl;

		cout << endl << endl;

	}

	cout << "Hit a key ...." << endl;
	_getch();
	return 0;

}

