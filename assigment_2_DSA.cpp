#include <iostream>
#include <cstring>
using namespace std;

// linear search
class Student
{
public:
    int roll;
    char name[15];
    double cgpa;
    void accept();
    // void display();
};

void Student::accept()
{
    cout << "\nEnter name of student:: ";
    cin >> name;
    cout << "\n Enter roll number of student:: ";
    cin >> roll;
    cout << "\n Enter cgpa of student:: ";
    cin >> cgpa;
}

int rollsearch(Student arr[], int n, int x)
{
    cout << "Enter the roll no. : " << endl;
    cin >> x;
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i].roll == x)
        {
            // cout << "value found " << endl;
            cout << "student found at the index " << i + 1 << endl;
            cout << "Name of student " << arr[i].name << endl
                 << "and cgpa is " << arr[i].cgpa << endl;
        }
    }
return -1;
}

int namebsearch(Student students[], int n, const char *x)
{

    int s = 0;     //    s= strarting point
    int e = n - 1; // e= ending point
    while (s <= e) // m = mid
    {
        int m = s + (e - s) / 2;
        int cmp = strcmp(students[m].name, x);
        if (cmp == 0)
        {
            return m;
        }
        else if (cmp < 0)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return -1;
}

int cgpasearch(Student arr[], int n, int x)
{
    cout << "Enter the cgpa :  " << endl;
    cin >> x;
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i].cgpa == x)
        {
            // cout << "value found " << endl;
            cout << "student found at the index " << i + 1 << endl;
            cout << "Name of student " << arr[i].name << endl
                 << "and cgpa is " << arr[i].cgpa << endl;
        }
    }
    return -1;
}

int rollbsearch(Student students[], int n, int x) // s= start,e=end,m=mid
{
    cout << "Enter roll number to search: ";
    cin >> x;
    int e = n - 1, s = 0;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (students[m].roll == x)
        {
            return m;
        }
        else if (students[m].roll < x)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return -1;
}


int namesearch(Student arr[], int n, const char *x)
{

    for(int i=0;i<n;i++)  
    {
        int cmp = strcmp(arr[i].name, x);
        if (cmp == 0)
        {
           cout<<"Name is : "<< arr[i].name <<endl;
           cout<<"Name found at the index "<<i<<endl;
           cout<<"roll is : "<< arr[i].roll <<endl;
           cout<<"cgpa is : "<< arr[i].cgpa <<endl;
        }
       
    
    }
    return -1;
}





int cgpabsearch(Student students[], int n, int x) // s= start,e=end,m=mid
{
    cout << "Enter cgpa  to search: ";
    cin >> x;
    int e = n - 1, s = 0;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (students[m].cgpa == x)
        {
            return m;
        }
        else if (students[m].cgpa < x)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return -1;
}

int main()
{
    for (int i = 0; i < 100; i++)
    {

        char a;
        cout << "Enter 'y' if the data is not  in sorted format " << endl;
        cin >> a;

        if (a == 'y')
        {   cout<<"   By using linear search  "<<endl;
            int n, i, j,index,x;
            Student s[10];
            cout << "\n Enter how many students record you want to enter  " << endl;
            cin >> n;
            for (i = 0; i < n; i++)
            {
                 s[i].accept();  
            }

            int b;
            cout << "Select 1 for selecting by roll " << endl;
            cout << "Select 2 for selecting by name  " << endl;
            cout<<"Select 3 for selecting by cgpa"<<endl;

            cout << "Select the way you want to select the student " << endl;
            cin >> b;

            if (b == 1)
            {
              index = rollsearch(s, n, x);

              if (index!=-1)
              {
                cout<<"Data not found ";
              }
              
            }

            if (b==2)
            { 
                char x[100];
                cout << "Enter name   to search: ";
                cin >> x;

               index =  namesearch(s,n,x);
                if (index!=-1)
                {
                    cout<<"Data not found ";
                }
                
                
            }
            

            if (b == 3)
            {
              index = cgpasearch(s, n, x);
              if (index!=-1)
              {
                cout<<"Data not found ";
              }

            }
        }

        else
        {
            cout<<"By using Binary search"<<endl;
            int n;
            cout << "Enter the number of students: "<<endl;
            cin >> n;

            Student s[100]; //  maximum of 100 students

            for (int i = 0; i < n; ++i)
            {
                s[i].accept();
            }

            int b;
            cout << "Select 1 for selecting by roll " << endl;
            cout << "Select 2 for selecting by name  " << endl;
            cout << "Select 3 for selecting by cgpa " << endl<<endl;
            cout << "Select the way you want to select the student " << endl;
            cin >> b;
            int index, x;
            if (b == 1)
            {
                index = rollbsearch(s, n, x);
            }

            if (b == 2)
            {

                char x[100];
                cout << "Enter name   to search: "<<endl;
                cin >> x;

                index = namebsearch(s, n, x);
                
            }

            if (b == 3)
            {
                index = cgpabsearch(s, n, x);
            }

            if (index != -1)
            {
                cout << "Student found: " << endl
                     << "Name: " << s[index].name << endl;
                cout << " Roll: " << s[index].roll << endl;
                cout << " CGPA: " << s[index].cgpa << endl;
            }
            else
            {
                cout << "Data not found." << endl;
            }
        }
        char h;
        cout << "Enter 'y' if you want to search again" << endl;
        cin >> h;
        if (h == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}
