# include <iostream>
# include <string>
using namespace std;

class Time
{
protected:
    int hour;
    int min;
public:
    // default constructor
    Time()
    {
        hour = 0;
        min = 0;
    }
    
    // constructor
    Time(int h, int m, int s)
    {
        hour = h;
        min = m;
    }
    
    // mutator functions
    void setHour(int h)
    {
        hour = h;
    }
    
    void setMin(int m)
    {
        min = m;
    }   
    
    // accessor functions
    int getHour() const
    {
        return hour;
    }
    
    int getMin() const
    {
        return min;
    }
    
    // display function
    void displayTime() const
    {
        cout << "hour: " << getHour() << endl;
        cout << "min: " << getMin() << endl;
        cout << endl;
    }
};

class MilTime : public Time
{
    protected:
        int milHours;
    public:
        // constructors
        MilTime() : Time ()
        {
            milHours = 0;
        }

        MilTime(int h)
        {
            setTime(h);
        }

        // mutator functions
        void setMilHours(int h)
        {
            milHours = h;
        }
        
        void setTime(int mh)
        {
          try{
               if (mh > 2359 || mh < 0)
               {
                throw "Error!!Time range [0 2359]";
               }
               else
               {
                
                if ( (mh % 100) < 0 || (mh % 100) > 59 )
                  throw 100;
             }}
                catch(const char* h)
                {
                    cout << "Error :" <<h<<endl;
                }
                catch(int num)
                {
                  cout << "Error: "<<num;
                }
                setMilHours(mh);
                setHour(mh / 100);
                setMin(mh % 100);
             
        }

        // accessor functions
        int getMilHours() const
        {
            return milHours;
        }
        
        // display function
        void displayMilitaryTime()
        {
            cout << "Military Hours: " << getMilHours() << endl;
        }
};


int main()
{
    MilTime t(3454);
    return 0;
}
