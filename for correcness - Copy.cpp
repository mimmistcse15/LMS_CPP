#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<cstdlib>

using namespace std;

/***************Admin Class*******************/

class admin
{
private:
    char name[30];
    char password[30];
public:
    void create_admin()
    {
        cin.ignore();
        cout<<"Enter name--"<<endl;
        gets(name);

        cout<<"Enter password--"<<endl;
        gets(password);
        cin.ignore();
    }
    void show()
    {
        cout<<"Admin's name--";
        puts(name);
        cout<<"----Welcome----"<<endl;
    }
    char *retpass()
    {
        return password;
    }
};

/*****************student class******************/

class student
{
private:
    char  name[30];
    char admno[40];
    char stbno[40];
    char password[30];
    int token;
public:
    void create_student()
    {
        cout<<"Enter Admission no"<<endl;
        cin>>admno;
        cin.ignore();
        cout<<"Enter student name"<<endl;
        gets(name);

        cout<<"Enter password"<<endl;
        gets(password);

        token=0;
        stbno[0]='\0';
    }
    void show()
    {
        cout<<"Admission no= "<<admno<<endl;
        cout<<"Students name= "<<name<<endl;
        if(token==1)
        {
            cout<<"Student book no= "<<stbno<<endl;
        }
        else
            cout<<"Student book no= "<<token<<endl;

    }
    int show_all()
    {

        cout<<admno<<"------"<<name<<"-----"<<token<<"-----"<<password<<endl;
    }
    char *retpass()
    {
        return password;
    }
    void modify()
    {
        cout<<"Admission no= "<<admno<<endl;
        cout<<"Modifying name= ";
        gets(name);
        cin.ignore();
        cout<<"Token= "<<token<<endl;
    }
    char *retadmno()
    {
        return admno;
    }
    char *retstbno()
    {
        return stbno;
    }

    int rettoken()
    {
        return token;
    }
    int addtoken()
    {
        token=1;
    }
    int resettoken()
    {
        token=0;
    }
    int getstbno(char t[])
    {
        strcpy(stbno,t);
    }
};

/*******************book class*****************/

class book
{
private:
    char bno[20];
    char bname[30];
    char aname[30];
    char issuebkno[30];
    int bktoken;
    int day;
    int month;
    int year;
public:
    void create_book()
    {
        cout<<"Enter book no"<<endl;
        cin>>bno;
        cin.ignore();
        cout<<"Enter book name"<<endl;
        gets(bname);
        cout<<"Enter authors name"<<endl;
        gets(aname);

        cin.ignore();
        bktoken=0;
        issuebkno[0]='\0';
    }
    void show()
    {
        cout<<"Book no-- "<<bno<<endl;
        cout<<"Book name-- "<<bname<<endl;
        cout<<"Authors name-- "<<aname<<endl;
        if(bktoken==1)
        {
            cout<<"Token=  "<<issuebkno<<endl;
        }
        else
        {
            cout<<"Token=  "<<bktoken<<endl;
        }

    }
    void show_all()
    {
        cout<<bno<<"--------"<<bname<<"-------"<<aname<<"--------"<<bktoken<<endl;
    }
    void create_date()
     {
         cout<<"Enter day: ";
         cin>>day;
         cin.ignore();
        cout<<"Enter month: ";
         cin>>month;
         cin.ignore();
        cout<<"Enter year: ";
         cin>>year;
     }
     void show_date()
     {
         cout<<day<<" / "<<month<<"/ "<<year<<endl;
     }
    void modify()
    {
        cout<<"Admission no-- "<<bno<<endl;
        cin.ignore();
        cout<<"Enter book name--";
        gets(bname);
        cout<<"Enter Authors name--";
        gets(aname);
        cin.ignore();
    }
    char *retbono()
    {
        return bno;
    }
    char *retissuebkno()
    {
        return issuebkno;
    }
    int retbktoken()
    {
        return bktoken;
    }
    int addbktoken()
    {
        bktoken=1;
    }
    int resetbktoken()
    {
        bktoken=0;
    }
    int retday()
    {
        return day;
    }
    int retmonth()
    {
        return month;
    }
    int retyear()
    {
        return year;
    }
    int resetdate()
    {
        day=0;
        month=0;
        year=0;
    }
    int getissuebkno(char t[])
    {
        strcpy(issuebkno,t);
    }

};


admin ad;
student st;
book bk;
fstream fp;
fstream fp1;

/****************writing admin profile*****************/

int writing_admin_profile()
{
    char c;
    fstream fp;

    fp.open("admin.txt",ios::out|ios::app);
    do
    {
        ad.create_admin();
        fp.write((char*)&ad,sizeof(admin));
        cout<<"Enter y if u want to add more"<<endl;
        cin>>c;
    }
    while(c=='y');

    fp.close();
}

/*************writing student profile********************/

int writing_students_profile()
{
    char ch;
    fstream fp;

    fp.open("student.txt",ios::out|ios::app);
    do
    {
        st.create_student();
        fp.write((char*)&st,sizeof(student));
        cout<<"Enter Y or y if u want to add more"<<endl;
        cin>>ch;
    }
    while(ch=='Y'||ch=='y');
    fp.close();

}

/*************writing book profile*****************/

int writing_book_profile()
{
    fstream fp;
    char  ch;
    fp.open("book.txt",ios::out|ios::app);
    do
    {
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"Enter y if u want to add more"<<endl;
        cin>>ch;
    }
    while(ch=='Y'||ch=='y');


}

/***********writing date***************/

int writing_date()
{
      fstream fp;
      fp.open("book.txt",ios::in|ios::app);
      bk.create_date();
      fp.write((char*)&bk,sizeof(book));
      fp.close();
}
/***********display all student profile***************/

int display_alls()
{
    fstream fp;
    fp.open("student.txt",ios::in);
    cout<<"Admno"<<"-------"<<"Name"<<"-----"<<"token"<<"------"<<"Password"<<endl;
    while(fp.read((char*)&st,sizeof(student)))
    {

        st.show_all();
    }
    fp.close();

}

/*************display book profile******************/

int display_allb()
{
    fstream fp;
    fp.open("book.txt",ios::in);
    cout<<"Book no"<<"--"<<"Book name"<<"---"<<"Authors name"<<"-----"<<"bktoken"<<endl;
    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.show_all();
    }
    fp.close();

}

/****************display specific student profile******************/

int display_sps(char ch[])
{
    fstream fp;
    int f=0;
    fp.open("student.txt",ios::in);

    while(fp.read((char*)&st,sizeof(student)))
    {

        if(strcmpi(st.retadmno(),ch)==0)
        {
            st.show();

        }
    }
    fp.close();

}

/****************display specific book***************/

int display_spb(char no[])
{
    fstream fp;
    fp.open("book.txt",ios::in);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbono(),no)==0)
        {
            bk.show();
        }
    }
    fp.close();

}

/**********display special call****************/

int display_sps_call()
{
    char ch[20];
    char n;
    do
    {
        cout<<"Enter admission no"<<endl;
        cin>>ch;
        display_sps(ch);
        cout<<"Enter y if u want more"<<endl;
        cin>>n;
    }
    while(n=='Y'||n=='y');
}
int display_spb_call()
{
    char ch[10];
    char c;
    do
    {
        cout<<"Enter book no"<<endl;
        cin>>ch;
        display_spb(ch);
        cout<<"Enter y if u wanna find more"<<endl;
        cin>>c;
    }
    while(c=='Y'||c=='y');
}

/****************modify student**************/

int modify_st()
{
    fstream fp;
    int found=0;
    char adno[20];
    cout<<"Enter the Admission no u want to modify"<<endl;
    cin>>adno;
    fp.open("student.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.retadmno(),adno)==0)
        {
            st.show();
            cout<<"Enter the new data"<<endl;
            st.modify();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"Record is updated"<<endl;
            found=1;
        }
    }
    fp.close();
    if(found==0)
    {
        cout<<"Record is not found"<<endl;
    }

}

/**************modify book***************/

int modify_bk()
{
    fstream fp;
    int f=0;
    char ch[20];
    cout<<"Enter the book no u want to modify"<<endl;
    cin>>ch;
    fp.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbono(),ch)==0&& f==0)
        {
            bk.show();
            cout<<"Enter The new information"<<endl;
            bk.modify();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(book));
            f=1;
            cout<<"Record is updated"<<endl;
        }
    }
    fp.close();
    if(f==0)
    {
        cout<<"Record is not found"<<endl;
    }
}

/****************** delete student****************/

int delete_st()
{
    fstream fp;
    fstream fp1;
    int f=0;
    char adno[20];
    fp.open("student.txt",ios::in|ios::out);
    cout<<"Enter the Admission no u want to delete"<<endl;
    cin>>adno;
    fp1.open("temp.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmpi(st.retadmno(),adno)!=0)
        {
            fp1.write((char*)&st,sizeof(student));
            f=1;
        }
        else
        {
            f=0;
        }
    }
    fp.close();
    fp1.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
    if(f==1)
    {
        cout<<"Record is deleted"<<endl;
    }
    else
    {
        cout<<"Record is not found"<<endl;
    }

}

/****************Delete book*************/

int delete_bk()
{
    fstream fp;
    fstream fp1;
    int f=0;
    char ch[20];
    cout<<"Enter the Admission no u wanna delete"<<endl;
    cin>>ch;
    fp.open("book.txt",ios::in|ios::out);
    fp1.open("temp1.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbono(),ch)!=0)
        {
            fp1.write((char*)&bk,sizeof(book));
            f=1;
        }
        else
        {
            f=0;
        }
    }
    fp.close();
    fp1.close();
    remove("book.txt");
    rename("temp1.txt","book.txt");
    if(f==1)
    {
        cout<<"Record is deleted successfully"<<endl;
    }
}

/***********Issue book*******************/

int issue_book()
{
    fstream fp;
    fstream fp1;
    int f=0;
    int flag=0;
    char stno[20];
    char bono[20];
    int b=0;
    cout<<"Enter student no"<<endl;
    cin>>stno;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&f==0)
    {
        if(strcmpi(st.retadmno(),stno)==0)
        {
            f=1;
            if(st.rettoken()==0)
            {
                cout<<"Enter book no"<<endl;
                cin>>bono;
                while(fp1.read((char*)&bk,sizeof(book))&&flag==0)
                {
                    if(strcmpi(bk.retbono(),bono)==0)
                    {
                        if(bk.retbktoken()==0)
                        {
                            b=1;
                            bk.show();
                            st.addtoken();
                            bk.addbktoken();
                            writing_date();
                            st.getstbno(bk.retbono());
                            bk.getissuebkno(bk.retbono());
                            int pos=-1*sizeof(st);
                            int pos2=-1*sizeof(bk);
                            fp.seekp(pos,ios::cur);
                            fp1.seekp(pos2,ios::cur);
                            flag=1;
                            fp.write((char*)&st,sizeof(student));
                            fp1.write((char*)&bk,sizeof(book));
                            cout<<"Book is issued successfully."<<endl;
                        }
                        else
                        {
                            cout<<"Book has been issued"<<endl;
                        }
                    }
                }
                if(flag==0)
                {
                    cout<<"Book is not found"<<endl;
                }
            }
            else
            {
                cout<<"u have not returned last book"<<endl;
            }
        }
    }
    fp.close();
    fp1.close();
    if(f==0)
    {
        cout<<"Student is not found"<<endl;
    }
}

/*****************Dposit book*******************/

int deposit_book()
{
    fstream fp;
    fstream fp1;
    int b=0;
    int day,fine,found=0,flag=0;
    char stno[20];
    cout<<"Enter student no"<<endl;
    cin>>stno;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.retadmno(),stno)==0)
        {
            found=1;
            if(st.rettoken()==1 )
            {
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {

                    if(strcmpi(st.retstbno(),bk.retbono())==0)
                    {
                        if(bk.retbktoken()==1)
                        {
                            bk.show();
                            bk.show_date();
                            flag=1;
                            cout<<"Enter the day"<<endl;
                            cin>>day;


                    if(day>15)
                    {
                       int fine=(day-15)*2;
                       cout<<"The fine will be "<<fine<<" Tk"<<endl;
                    }
                     else
                    {
                       cout<<"There will be no fine"<<endl;
                     }
                            st.resettoken();
                            bk.resetbktoken();
                            bk.resetdate();
                            int pos=-1*sizeof(st);
                            int pos2=-1*sizeof(bk);
                            fp.seekp(pos,ios::cur);
                            fp1.seekp(pos2,ios::cur);
                            fp.write((char*)&st,sizeof(student));
                            fp1.write((char*)&bk,sizeof(book));
                            cout<<"Book is deposited successfully "<<endl;
                        }
                    }

                }
                if(flag==0)
                {
                    cout<<"book is not found"<<endl;
                }
            }
        }
    }
    if(found==0)
    {
        cout<<"Student dosent exist"<<endl;
    }
    fp.close();
    fp1.close();
}

/****************Admin menu**************/

int admin_menu()
{
    int choice;
    while(choice!=11)
    {
        cout<<"\t\tEnter Admins choice"<<endl;
        cout<<"Enter-1-createing student profile"<<endl;
        cout<<"Enter-2-for showing all  students profile"<<endl;
        cout<<"Enter-3-for showing specfic student profile"<<endl;
        cout<<"Enter-4-for modifying student profile"<<endl;
        cout<<"Enter-5-for deleting student profile"<<endl;
        cout<<"Enter-6-for creating book profile"<<endl;
        cout<<"Enter-7-for showing all book profile"<<endl;
        cout<<"Enter-8-for showing specific book profile"<<endl;
        cout<<"Enter-9-for modifying book profile"<<endl;
        cout<<"Enter-10-for deleting book profile"<<endl;
        cout<<"Enter -11-Back to main menu"<<endl;
        cout<<"Enter(1-11)"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            writing_students_profile();
            break;
        case 2:
            display_alls();
            break;
        case 3:
            display_sps_call();
            break;
        case 4:
            modify_st();
            break;
        case 5:
            delete_st();
            break;
        case 6:
            writing_book_profile();
            break;
        case 7:
            display_allb();
            break;
        case 8:
            display_spb_call();
            break;
        case 9:
            modify_bk();
            break;
        case 10:
            delete_bk();
            break;
        }
    }
}

/********************Admin login***************/

int admin_login()
{
    int choice;
    while(choice!=5)
    {
        cout<<"\t\tMain Menu"<<endl;
        cout<<"Enter-1-If u want to add new admin"<<endl;
        cout<<"Enter-2-Administrator menu"<<endl;
        cout<<"Enter-3-Book Issue"<<endl;
        cout<<"Enter-4-Deposit Book"<<endl;
        cout<<"Enter-5- for Exit"<<endl;
        cout<<"Enter (1-5)"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            writing_admin_profile();
            break;
        case 2:
            admin_menu();
            break;
        case 3:
            issue_book();
            break;
        case 4:
            deposit_book();
            break;

        }
    }
}

/*int admin_check()
{
    fstream fp;
    int flag=0;
    char pass[20];
    fp.open("admin.txt",ios::in|ios::out);
    cout<<"enter admin password"<<endl;
     cin>>pass;
     while(fp.read((char*)&ad,sizeof(admin))&& flag==0)
     {
         if(strcmpi(ad.retpass(),pass)==0)
         {
             ad.show();
             admin_login();
             flag=1;
         }
     }
     if(flag==0)
     {
         cout<<"Admin not found"<<endl;
     }
}*/

/*int admin_entrance()
{
    int choice;
    while(choice!=3)
    {
        cout<<"Enter-1-for creating admin"<<endl;
        cout<<"Enter-2-for Admin's work admin"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            writing_admin_profile();
            break;
            case 2:
            admin_check();
            break;
        }
    }
}*/

/*****************Student login******************/

int student_login()
{
    int choice;
    while(choice!=3)
    {

        cout<<"\t\tMain Menu"<<endl;
        cout<<"Enter-1-Book Issue"<<endl;
        cout<<"Enter-2-Deposit Book"<<endl;
        cout<<"Enter-3- for Exit"<<endl;
        cout<<"Enter (1-3)"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            issue_book();
            break;
        case 2:
            deposit_book();
            break;

        }
    }
}

/*****************Admin work**************/

int admin_work()
{
    fstream fp;
    int flag=0;
    char pass[20];
    fp.open("admin.txt",ios::in|ios::out);
    cout<<"enter admin password"<<endl;
    cin>>pass;
    while(fp.read((char*)&ad,sizeof(admin))&& flag==0)
    {
        if(strcmpi(ad.retpass(),pass)==0)
        {
            ad.show();
            admin_login();
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"Admin not found"<<endl;
    }
}

/****************student work*******************/

int student_work()
{
    fstream fp;
    int f=0;
    char password[20];

    cout<<"Enter user password "<<endl;
    cin>>password;
    fp.open("student.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && f==0)
    {
        if(strcmpi(st.retpass(),password)==0)
        {
            cout<<"------welcome------"<<endl;
            student_login();
            f=1;
        }

    }
    if(f==0)
    {
        cout<<"False password"<<endl;
    }
    fp.close();

}

/******************login system*********************/

int login()
{
    int choice;
    while(choice!=3)
    {
        system("cls");
        cout<<"1. Log In as Admin"<<endl;
        cout<<"2. Log In as Student"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter (1-3)"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            admin_work();
            break;
        case 2:
            student_work();
            break;
        }
    }
}

/*******************Registration**************/

int registration()
{
    char n;
    fstream fp;
    fp.open("student.txt",ios::out|ios::app);
    do
    {
        st.create_student();
        fp.write((char*)&st,sizeof(student));
        cout<<"Enter 'n' if u have entered all infrmaton"<<endl;
        cin>>n;

    }
    while(n=='y');
    fp.close();

}

/******************Main menu*******************/

int main()
{

    int choose;

    while(choose!=3)
    {
        cout<<"\t\t*Main Option*"<<endl<<endl;
        cout<<"1. Student Registration"<<endl;
        cout<<"2: Log In"<<endl;
        cout<<"3. Exit"<<endl<<endl;
        cout<<"Enter (1-3)"<<endl;
        cin>>choose;
        switch(choose)
        {
            case 1:
            registration();
            break;
            case 2:
            login();
            break;
        }
    }
}
