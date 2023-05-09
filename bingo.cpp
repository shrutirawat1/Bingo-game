//game BINGO
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
class computer
{
//functions in this class
//initalize, deletenum, getnumber, assignzero, check, deleteusernum
public:
    int bng[5][5];
    void initialize() //initializing the bingo table for computer
    {
        int a[25];  //an array which will contain all possible values for a bingo table
        for(int i=0; i<25; i++)
        {
            a[i]=i+1;
        }
        int j=25;
        int c=0,b=0;
        srand(time(0));
        for(int i=0; i<25; i++)
        {
            int num=rand()%j;
            if(b==5)
            {
                b=0;
                c++;
            }
            //randomly selected numbers are getting initialized in bingo matrix
            bng[c][b]=a[num];
            b++;
            //deleting the block of array which is generated randomly...
            //so that the number would not get repeated in the bingo table
            deletenum(a,num,j);
            //as number is deleted the size of array would also get decreased or
            //the area till which we can select random numbers is decreased
            j--;
        }
       /* cout<<"showing computer's bingo table(for testing) :"<<endl; //showing computer's table is only for testing purpose
        for(int c=0; c<5; c++)
        {
            for(int b=0; b<5; b++)
            {
                cout<<bng[c][b]<<ends;
            }
            cout<<endl;
        }*/
    }
    //function to delete block from array(support function)
    void deletenum(int a[],int num,int j)
    {
        for(int i=num+1; i<j; i++)
        {
            a[i-1]=a[i];
        }
    }

    int getnumber(int &y,int a[]) //function to randomly select a number to replace it with zero
    {
        //logic is much similar to function initialize
        int num,r;  //num is a index given by computer randomly
        srand(time(0));
        num=rand()%y;
        r=a[num];
        //cout<<"r is "<<r<<endl;
        deletenum(a,num,y);
        y--;
        return r;//returning r,the randomly selected number to further replace it with zero
    }
    void deleteusernum(int number,int a[],int &y)
    {
        int num;
        for(int i=0; i<y; i++)
        {
            if(a[i]==number)
            {
                num=i;
                break;
            }
        }
        deletenum(a,num,y);
        y--;
    }
    void assignzero(int num) //assigning zero to numbers to be deleted
    {
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(bng[i][j]==num)
                {
                    bng[i][j]=0;
                    i=5;
                    break;
                }
            }
        }
    }
    void check()   //check if there's a bingo ...to see if computer won
    {
        int countz=0,bingo=0;
//rows
        for(int i=0; i<5; i++)
        {
            countz=0;
            for(int j=0; j<5; j++)
            {
                if(bng[i][j]==0)
                {
                    countz++;
                }
                else
                {
                    break;
                }
            }
            if(countz==5)
            {
                bingo++;
            }
        }
//columns
        for(int i=0; i<5; i++)
        {
            countz=0;
            for(int j=0; j<5; j++)
            {
                if(bng[j][i]==0)
                {
                    countz++;
                }
                else
                {
                    break;
                }
            }
            if(countz==5)
            {
                bingo++;
            }
        }
//diagonal 1
        countz=0;
        for(int i=0; i<5; i++)
        {
            int j=i;
            if(bng[i][j]==0)
            {
                countz++;
            }
            else
            {
                break;
            }
            if(countz==5)
            {
                bingo++;
            }
        }
//diagonal 2
        countz=0;
        for(int i=4; i>=0; i--)
        {
            int j=i;
            if(bng[i][j]==0)
            {
                countz++;
            }
            else
            {
                break;
            }
            if(countz==5)
            {
                bingo++;
            }
        }
        if(bingo==5)
        {
            cout<<"BINGO.."<<endl<<"computer wins..."<<endl;
            for(int a=0; a<5; a++)
            {
                for(int b=0; b<5; b++)
                {
                    cout<<bng[a][b]<<ends;
                }
                cout<<endl;
            }
            exit(0);
        }
    }
//friend class user;
};

class user
{
public:
    int bng[5][5];
//computer a; check why not working as a friend class
//a.check();
    void initialize()
    {
        cout<<"enter numbers for your bingo table :"<<endl;
        for(int i=0; i<5; i++)
        {
            cout<<"for row "<<i+1<<endl;
            for(int j=0; j<5; j++)
            {
waapis:
                cout<<"enter number for box "<<j+1<<endl;
                cin>>bng[i][j];
                if(bng[i][j]>25 || bng[i][j]<1)
                {
                    cout<<"please enter number from 1 to 25 "<<endl;
                    goto waapis;
                }

                for(int a=0; a<=i; a++)
                {
                    for(int b=0; b<=j; b++)
                    {
                        if(j==b && i==a)
                        {
                            continue;
                        }
                        else
                        {
                            if(bng[a][b]==bng[i][j])
                            {
                                cout<<"number already entered...please enter another number "<<endl;
                                goto waapis;
                            }
                        }
                    }
                }

            }
            cout<<"numbers entered till "<<i+1<<" rows :"<<endl;
            for(int a=0; a<=i; a++)
            {
                for(int b=0; b<5; b++)
                {
                    cout<<bng[a][b]<<ends;
                }
                cout<<endl;
            }
        }
    }
    int getnumber()//getting number from user to be replaced by zero
    {
        int num;
above:
    cout<<"let's start "<<endl;
        cout<<"enter number :";
        cin>>num;
        if(num<1 || num>25)
        {
            cout<<"please enter number from 1 to 25 "<<endl;
            goto above;
        }
        int c=0;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(bng[i][j]==num)
                {
                    c++;
                }
            }
        }
        if(c==0)
        {
            cout<<"please select a number not deleted yet.."<<endl;
            goto above;
        }
        return num;
    }

    void assignzero(int num) //assigning zero to numbers to be deleted
    {
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(bng[i][j]==num)
                {
                    bng[i][j]=0;
                    i=5;
                    break;
                }
            }
        }
    }
    void check()  //check if there's a bingo ...to see if user won
    {
        int countz=0,bingo=0;
//rows
        for(int i=0; i<5; i++)
        {
            countz=0;
            for(int j=0; j<5; j++)
            {
                if(bng[i][j]==0)
                {
                    countz++;
                }
                else
                {
                    break;
                }
            }
            if(countz==5)
            {
                bingo++;
            }
        }
//columns
        for(int i=0; i<5; i++)
        {
            countz=0;
            for(int j=0; j<5; j++)
            {
                if(bng[j][i]==0)
                {
                    countz++;
                }
                else
                {
                    break;
                }
            }
            if(countz==5)
            {
                bingo++;
            }
        }
//diagonal 1
        countz=0;
        for(int i=0; i<5; i++)
        {
            int j=i;
            if(bng[i][j]==0)
            {
                countz++;
            }
            else
            {
                i=5;
                break;
            }
            if(countz==5)
            {
                bingo++;
            }
        }
//diagonal 2
        countz=0;
        for(int i=4; i>=0; i--)
        {
            int j=i;
            if(bng[i][j]==0)
            {
                countz++;
            }
            else
            {
                i=-1;
                break;
            }
            if(countz==5)
            {
                bingo++;
            }
        }
        if(bingo==5)
        {
            cout<<"BINGO.."<<endl<<"you win..."<<endl;
            for(int a=0; a<5; a++)
            {
                for(int b=0; b<5; b++)
                {
                    cout<<bng[a][b]<<ends;
                }
                cout<<endl;
            }
            exit(0);
        }
    }

};

main()
{
    int f=25;
    int a[25];
    for(int i=0; i<25; i++)
    {
        a[i]=i+1;
    }
    cout<<"welcome....Let's start the game."<<endl;
    computer ct;
    user us;
    us.initialize();
    ct.initialize();
    int i=1,st=0;
    while(1)
    {
        switch(i)
        {
        case 1:
        {
            int c=us.getnumber();
            st++;
            // int abc=ct.getnumber(f,a); //smjh aa gya , variable a is already in this scope and i'm passing array which is also a
            ct.deleteusernum(c,a,f);
            us.assignzero(c);
            ct.assignzero(c);
            i++;
            break;
        }
        case 2:
        {
            int b=ct.getnumber(f,a);
            st++;
            cout<<"computer selected "<<b<<endl;
            ct.assignzero(b);
            us.assignzero(b);
            i--;
            break;
        }
        }
        if(st>15)
        {
            us.check();
            ct.check();
        }
    }
}
