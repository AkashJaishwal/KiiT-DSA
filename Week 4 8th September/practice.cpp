#include <iostream>
using namespace std;
class Student
{
public:
    int roll_no;
    string name;
    string sec;
    void Stu()
    {
        cout << "Enter the name of the Student : ";
        getline(cin, name);
        cout << "Enter Roll Number : ";
        cin >> roll_no;
        cin.ignore();
        cout << "Enter Section : ";
        cin >> sec;
    }
};
class Test : public Student
{
public:
    int *s = new int;
    void Tst()
    {
        Student::Stu();
        cout << "\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter the Marks for Sub " << i + 1 << " : ";
            cin >> s[i];
            if (s[i] < 0 || s[i] > 100)
            {
                cout << "Wrong Input !!";
                cin.ignore();
                cout << "\n\n";
                Test::Tst();
            }
        }
        cin.ignore();
    }
    void display()
    {
        cout << "\n\n--------------------------------------------\n";
        cout << "\tDetails You Entered : \n\n";
        cout << "Name : " << Student::name << endl;
        cout << "Rol No. : " << Student::roll_no << endl;
        cout << "Section : " << Student::sec << endl;
    }
};
class Sports : public Student
{
public:
    string sport;
    string score;
    void Sprts()
    {
        cout << "\n";
        cout << "Enter the name of the Sports : ";
        getline(cin, sport);
        cout << "Enter the Score : ";
        getline(cin, score);
    }
};
class Result : public Sports, public Test
{
public:
    Result()
    {
        Test::Tst();
        Sports::Sprts();
        int opt;
        float r = 0;
        cout << "\n";
        cout << "For Modification :";
        cout << "\n1.Subjects Marks\n2.Sports Score\n3.No Modifications\n";
        cout << "Your Option : ";
        cin >> opt;
        if (opt != 1 && opt != 2 && opt != 3)
        {
            cout << "\nWrong Input !!";
            cin.ignore();
            cout << "\n\n";
            Test::Tst();
        }
        else if (opt == 1)
        {
            cout << "\nEnter the new Modified Marks :\n";
            for (int i = 0; i < 5; i++)
            {
                cout << "Enter the Marks for Sub " << i + 1 << " : ";
                cin >> Test::s[i];
                if (s[i] < 0 || s[i] > 100)
                {
                    cout << "\nWrong Input !!";
                    cin.ignore();
                    cout << "\n\n";
                    Test::Tst();
                }
            }
            cout << "Changes Made Succesfully !!\n";
        }
        else if (opt == 2)
        {
            cin.ignore();
            cout << "\nEnter the new modified Score for " << Sports::sport << " : \n";
            cout << "Enter the Score : ";
            getline(cin, Sports::score);
            cout << "Changes Made Succesfully !!\n";
        }
        else
            cout << "\nNo Changes Made !!";
        for (int i = 0; i < 5; i++)
        {
            r = r + Test::s[i];
        }
        Test::display();
        cout << "Result : " << r / 5;
        cout << "\nSports Name : " << Sports::sport;
        cout << "\nScore : " << Sports::score;
        cout << "\n\n\n";
    }
};
int main()
{
    system("CLS");
    Result res;
}