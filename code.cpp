
#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void pranshujain() //MY INFORMATION
{
    cout << "\n MY NAME IS PRANSHU JAIN";
    cout << "\n MY FAVOURITE SUBJECT IS COMPUTER SCIENCE  \n but AS I don't have pc earlier I don't know about that earlier";
    cout << "\n 96 IN COMPUTER SCIENCE, PASSIONATE IN IT ";
    cout << "\n THOUGHT TO MAKE A PROGRAM TO SIMPLY DEMONSTATE COUNSELLING OF DTE";
    cout << "\n SORRY IF THE PROGRAM IS NOT UPTO MARK AND COLOURFUL (I have less time)";
    getch();
}
class be
{
public:
    string name;
    int per, seat;
    vector<int> x;
    be(string n, int p)
    {
        per = p;
        name = n;
    }
    bool operator>(be obj)
    {
        return this->per > obj.per;
    }
    bool operator<(be obj)
    {
        return this->per < obj.per;
    }
};
bool gotoxy(const WORD x, const WORD y)
{
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
bool verify(char check)
{
    return (check == 'y' || check == 'Y');
}
main()
{
    system("CLS");
    system("Color 16");
    // textbackground(BLUE);
    int j, i, big, pos, ar[20], store, roll;
    int f = 0, n, m;
    char check = 'n';
    char info;
    string ch[10] = {"Acropolis, Indore", "IET DAVV, Indore", "IPS Academy,Indore", "LNCT, Bhopal", "SIRT, Bhopal", "SGSITS, Indore", "TIT, Bhopal", "JEC, Jabalpur"};
    ;
    cout << "\n Do you want to know about me Y/N :- ";
    cin >> check;
    if (verify(check))
    {
        pranshujain();
        system("CLS");
    }
    vector<be> bt;
    system("CLS");
    for (int ji = 0; ji < 3; ji++)
    {
        for (int jk = 0; jk < 20; jk++)
        {
            Sleep(100);
            gotoxy(30 + jk, 8);
            cout << "{}";
        }
        system("CLS");
    }
    gotoxy(30, 8);
    cout << "PRANSHU JAIN PRESENTS";
    Sleep(700);
    while (true)
    {
        cout << "\nEnter Record of student no. " << f + 1;
        string name, per;
        int percent;
        cout << "\nEnter Name : ";
        getline(cin >> ws, name);
    tryagain:
        try
        {
            cout << "\nEnter Percentile : ";
            cin >> per;
            percent = stoi(per);
        }
        catch (exception e)
        {
            cout << "Please Enter a valid number, try again...";
            goto tryagain;
        }
        bt.push_back(be{name, percent});
        cout << "\n Preference Setter ";
        cout << "\n REMEMEBER THESE THINGS -";
        cout << "\n 1.You have to write college number not college name for preference setting";
        cout << "\n 2.You must enter colleges which you like the most firsly than less prefered one";
        cout << " 3. C.N. means college number";
        getch();
        system("CLS");
        cout << "\n The list of college is as follows -";
        gotoxy(2, 4);
        cout << "C.N.";
        gotoxy(15, 4);
        cout << "College Name ";
    c:
        n = 6;
        check = 'y';
        big = 0;
        for (i = 0; i < 8; i++)
        {
            gotoxy(2, n);
            cout << i + 1;
            gotoxy(15, n++);
            cout << ch[i];
        }
        n = 15;
        for (i = 0; check == 'y' || check == 'Y'; i++)
        {

            int y;
            while (true)
            {
                try
                {
                    gotoxy(n, 15);
                    cin >> per;
                    y = stoi(per);
                    break;
                }
                catch (exception e)
                {
                    gotoxy(15, 14);
                    cout << "Enter valid number! try again...";
                }
            }
            bt[f].x.push_back(y);
            n = n + 2;
            cout << "\n Do you want to enter more..";
            cin >> check;
        }
        system("CLS");
        cout << "\n Now YOUR set PREFERENCE is :";
        n = 6;
        for (i = 0; i < bt[f].x.size(); i++)
        {
            gotoxy(2, n);
            cout << bt[f].x[i];
            gotoxy(15, n++);
            cout << ch[bt[f].x[i] - 1];
        }
        getch();
        system("CLS");
        cout << "\n Do You Want to Edit Your Preference Y/N ";
        cin >> check;
        if (check == 'Y' || check == 'y')
        {
            bt[f].x.clear();
            goto c;
        }
        cout << "\n YOU HAVE COMPLETED CHOICE FILLING";
        cout << "\n Remember your rollno. is :" << f + 1;
        system("CLS");
        cout << "\n Do you want to enter more students ?\n";
        cin >> check;
        if (check == 'y' || check == 'Y')
        {
            f++;
        }
        else
        {
            break;
        }
    }
    system("CLS");
    sort(bt.begin(), bt.end(), greater<>());
    bt[0].seat = bt[0].x[0];
    int flag = 0;
    for (int i = 1; i < bt.size(); i++)
    {
        for (int j = 0; j < bt[i].x.size(); j++)
        {
            flag = 0;
            for (int k = 0; k < i; k++)
            {
                if (bt[k].seat == bt[i].x[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                continue;
            }
            else
            {
                bt[i].seat = bt[i].x[j];
                break;
            }
        }
    }
des:

    gotoxy(18, 4);
    cout << "After Counselling the entered students got the following seats:";
    gotoxy(18, 8);
    cout << "S.N.";
    gotoxy(24, 8);
    cout << "Name";
    gotoxy(43, 8);
    cout << "College";
    gotoxy(73, 8);
    cout << "%age";
    for (i = 0; i < bt.size(); i++)
    {
        gotoxy(20, 10 + 2 * i);
        cout << i + 1;
        gotoxy(23, 10 + 2 * i);
        cout << bt[i].name.substr(0, 20);
        gotoxy(43, 10 + 2 * i);
        cout << ch[bt[i].seat - 1].substr(0, 30);
        gotoxy(73, 10 + 2 * i);
        cout << bt[i].per << "%";
    }
    getch();
}

// cout << "\n Your Result Platform -";
// cout << "\n Enter your roll no. -";
// cin >> roll;
// cout << "\n YOUR NAME :" << bt[roll - 1].name << "\n"
//      << "\n YOU ARE ALLOTED THE FOLLOWING COLLEGE :";
// cout << bt[roll - 1].seat;
// cout << "  &::& " << ch[bt[roll - 1].seat - 1] << "\n YOUR PERENTILE :" << bt[roll - 1].per;
// cout << "\n Do you want to see other result:Y/N \n";
// check = 'n';
// cin >> check;
// if (check == 'y')
// {
//     system("CLS");
//     goto des;
// }