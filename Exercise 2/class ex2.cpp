//SUBMITTED BY - NAVJOT KAUR
//SUBMITTED TO - POOYA TAHERI
#include "Students.h"
#include "MyException.h"
using namespace std;

//POST: reads the file
//PARAM: vec=vector of students which stores the students' names and scores from the text file into vector.
void input_file(vector<Students> &vec) throw(MyException)
{
	Students s;
	string student_name;
	double student_score;
	ifstream fin;
	fin.open("file.txt");
	if(fin.fail())
		throw MyException("INPUT FILE NOT FOUND");  //exception if file is not found.
	fin.peek();
	if(fin.eof())
		throw MyException("INPUT FILE OPENED BUT IT IS EMPTY");   //exception if file opens but it is empty.
	int i=0;
	while(!fin.eof())
	{
		fin >> student_name >> student_score;
		s.setName(student_name);
		s.setScore(student_score);
		vec.push_back(s);
		i++;
	}
	fin.close();
}

//POST: calculates the average of the numbers
//PARAM: vec=vector of students which contains students' scores whose average is to be calculated.
double average(vector<Students> &vec) throw(invalid_argument)
{
	/*If file.txt is empty then in order to prevent this function to print some garbage value for average,
	      an exception is handled in the input_file function stating that the file is empty*/
	Students s;
	double sum=0;
	for(int i=0;i<vec.size();i++)
	{
		double student_score=vec[i].getScore();
		if(student_score<0 || student_score>100)
			throw invalid_argument("INVALID ARGUMENT FOR STUDENT SCORE!!!");    //exception if invalid argument is entered for student's score.
		sum+=student_score;
	}
	double avg=sum/vec.size();
	return avg;
}

//POST: writes the line on the file
//PARAM: vec=vector of students whose calculated average is displayed on text file.
void output_file(vector<Students> &vec) throw(MyException)
{
	Students s;
	ofstream fout;
	fout.open("file.txt");
	if(fout.fail())
		throw MyException("OUTPUT FILE NOT CREATED");     //exception if output file opening failed.
	double av=average(vec);
	fout << "The average of all numbers is " << av << endl;
	int i=0;
	while(i<vec.size())
	{
		fout << vec[i].getName() << "\t" << vec[i].getScore() << endl;
		i++;
	}
	fout.close();
	cout << "The file is successfully loaded in your file.txt. " << endl;
}

int main()
{
	vector<Students> vec;
	try
	{
		input_file(vec);
		output_file(vec);
	}
	catch(MyException &exc)
	{
		cout << "EXCEPTION OCCURRED : ";
		cout << exc.what() << endl;
	}
	catch(invalid_argument &inv)
	{
		cout << "EXCEPTION OCCURRED : " << endl;
		cout << inv.what() << endl;
	}
	catch(...)  //catches the exception if wrong data type is thrown.
	{
		cout << "UNKNOWN EXCEPTION FOUND!!!" << endl;
	}
	system("pause");
	return 0;
}