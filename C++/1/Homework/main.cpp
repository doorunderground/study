#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;

int fileinputData(ifstream& fin, int* data, int max_num_data);  // 10개의 정수 데이터를 입력받는 
void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout);  // 입력된 데이터의 통계 분석

int main()
{
    ifstream fin;
    ofstream fout;

    int max_num_data = 0;
    int data[10] = { 0 };

    fin.open("input.txt");
    if (fin.fail())
    {
        cout << "Fail to open an input file (" << INPUT_FILE_NAME << endl;
        exit(1);
    }

    max_num_data = fileinputData(fin, data, max_num_data);

    fout.open("output.txt");
    if (fout.fail())
    {
        cout << "Fail to open an output file (" << OUTPUT_FILE_NAME << endl;
        exit(1);
    }

    fout << "Total " << max_num_data << " input from input data file." << endl;
    fout << "Total " << max_num_data << " integer data : {";

    getStatistics_fileOut(data, max_num_data, fout);
}

int fileinputData(ifstream& fin, int* data, int max_num_data)
{
    int num_data = 0;

    while (!fin.eof())
    {
        fin >> data[num_data];
        num_data ++;
    }
    max_num_data = num_data;
    return max_num_data;
}

void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout)  // 입력된 데이터의 통계 분석
{
    int min, max;
	double sum = 0.0, var, diff = 0.0, sq_diff_sum = 0.0, avg, std_dev;

	min = INT_MAX;
	max = INT_MIN;

    for (int i = 0; i < num_data; i ++)
    {
        if (data_array[i] < min)
            min = data_array[i];
        if (data_array[i] > max)
            max = data_array[i];

        sum = sum + (double)data_array[i];
    }
    avg = sum / num_data; //평균

    for (int i = 0; i < num_data; i++)
    {
        diff = data_array[i] - avg;
        sq_diff_sum += diff * diff;
    }
    var = sq_diff_sum / num_data; //분산
    std_dev = sqrt(var); //표준편차

    
	fout << "min(" << min << "), max(" << max << "), sum(" << sum << "), avg(" << avg << "), var(" << var << "), std_dev(" << std_dev << ")" << "}" << endl;



}
