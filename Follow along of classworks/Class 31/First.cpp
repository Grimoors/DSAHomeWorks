class MyDate
{

private:
    int yy;
    int mm;
    int dd;

public:
    //Constructor - Initialization
    MyDate();

    //Setter
    void SetDate(int s_yy, int s_mm, int s_dd)
    {
    }
    //Getter
    void GetDate(int *p_yy, int *p_mm, int *p_dd) // C-style
    {
    }

    void GetDate(int &r_yy, int &r_mm, int &r_dd) //C++-Style
    {
    }

    //Utilities
    void PrintDate()
    {
    }

    unsigned long int NumDaysTo(int I_yy, int I_mm, int I_dd)
    {
    }

    ~MyDate();
}

void MyDate::SetDate(int t_yy,int t_mm;int t_dd)
{
    yy=t_yy;
    mm=t_mm;
    dd=t_dd;
}

MyDate::MyDate()
//Zero Parameter Constructor
{
    yy = 1970;
    mm = 1;
    dd = 1;
}
//There is no return type for a constructor

MyDate::~MyDate
{
    //CleanUp
    //inform that object is being destroyed
}

void MyDate::GetDate(int &r_yy, int &r_mm, int &r_dd)
// "::" is a scope resolution operator. Specifies where the method / variable belongs to. Allowscrazy stuff like writing code for a function outside it's class. Might allow for polymorphism. Not sure.
{
    r_yy = yy;
    r_mm = mm;
    r_dd = dd;
}
/*
&=Reference
References cannot me null.
References cannot be freed.
References always refer to an instantiated primitive data type or to an object
*/
int main()
{

    MyDate m; //Object
}


class Car
{
    string carMake;//Toyota
    string carModel;//Fortuner
    string VIN;
    int manYear;
    DriveType drvType;//AWD,FWD,RW
}
//Encapsulation : Information hiding/ Abstraction?
class Icecream Machine
{
    private:
        int ltrsOfWater;
    public:
        GetUserChoice();
}