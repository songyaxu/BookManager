#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
class Reader  //读者的基类
{public:
    int Readerid;
    string ReaderID;
    string ReaderName;
    string ReaderUnit;
    string ReaderKey;
    char ReaderManager;
    char ReaderClassification;
    int LoanNumber;
    int ReservationNumber;
    int Permission;
    virtual void setReader()=0;
    virtual void show()=0;
    Reader *next;
};

class Student:public Reader   //读者派生的本科生类
{public:
    void setReader()
    {
        ReaderClassification='a';
        ReaderManager='n';
        Permission=4;
        cout<<"请输入读者的证件号码：";
        cin>>ReaderID;
        ReaderKey=ReaderID;
        cout<<"请输入读者的姓名：";
        cin>>ReaderName;
        cout<<"请输入读者的单位：";
        cin>>ReaderUnit;
        LoanNumber=0;
        ReservationNumber=0;
        cout<<endl;
    }
    void show()    //显示读者信息
    {
        cout<<"读者信息-》"<<Readerid<<".";
        cout<<"证件号码："<<ReaderID<<" 读者姓名："<<ReaderName<<" 读者单位：";
        cout<<ReaderUnit<<" 读者类型："<<"本科生 "<<"借书数量："<<LoanNumber;
        cout<<" 预约数量："<<ReservationNumber<<" 借阅限制数："<<Permission<<endl;
    }
};

class GraduateStudent:public Reader  //读者派生的研究生类
{public:
    void setReader()
    {
        ReaderClassification='b';
        Permission=6;
        ReaderManager='n';
        cout<<"请输入读者的证件号码：";
        cin>>ReaderID;
        ReaderKey=ReaderID;
        cout<<"请输入读者的姓名：";
        cin>>ReaderName;
        cout<<"请输入读者的单位：";
        cin>>ReaderUnit;
        LoanNumber=0;
        ReservationNumber=0;
        cout<<endl;
    }
    void show()  //显示读者信息
    {
        cout<<"读者信息-》"<<Readerid<<".";
        cout<<"证件号码："<<ReaderID<<" 读者姓名："<<ReaderName<<" 读者单位：";
        cout<<ReaderUnit<<" 读者类型："<<"研究生 "<<"借书数量："<<LoanNumber;
        cout<<" 预约数量："<<ReservationNumber<<" 借阅限制数："<<Permission<<endl;
    }
};

class Teacher: public Reader  //读者派生的教师类
{public:
    void setReader()
    {
        ReaderClassification='c';
        Permission=10;
        ReaderManager='n';
        cout<<"请输入读者的证件号码：";
        cin>>ReaderID;
        ReaderKey=ReaderID;
        cout<<"请输入读者的姓名：";
        cin>>ReaderName;
        cout<<"请输入读者的单位：";
        cin>>ReaderUnit;
        LoanNumber=0;
        ReservationNumber=0;
        cout<<endl;
    }
    void show()  //显示读者信息
    {
        cout<<"读者信息-》"<<Readerid<<".";
        cout<<"证件号码："<<ReaderID<<" 读者姓名："<<ReaderName<<" 读者单位：";
        cout<<ReaderUnit<<" 读者类型："<<"教师 "<<"借书数量："<<LoanNumber;
        cout<<" 预约数量："<<ReservationNumber<<" 借阅限制数："<<Permission<<endl;
    }
};

class Books  //图书类
{public:
    int Bookid;
    string BookID;
    string BookChinaID;
    string BookName;
    string BookAuthor;
    string BookPress;
    string BookDate;
    string BookISBN;
    string BookVersion;
    double BookPirce;
    int  BookLoanNum;
    int  BookReservationNum;
    int  BookFreeNum;
    Books *next;
    void setBooks()
    {
        cout<<"请输入图书的编号：";
        cin>>BookID;
        cout<<"请输入图书的数量：";
        cin>>BookFreeNum;
        BookLoanNum=0;
        BookReservationNum=0;
        cout<<"请输入图书的中图分类号：";
        cin>>BookChinaID;
        cout<<"请输入图书名称：";
        cin>>BookName;
        cout<<"请输入图书的作者： ";
        cin>>BookAuthor;
        cout<<"请输入图书的出版社： ";
        cin>>BookPress;
        cout<<"请输入图书的出版日期：";
        cin>>BookDate;
        cout<<"请输入图书的IBSN： ";
        cin>>BookISBN;
        cout<<"请输入图书的版次： ";
        cin>>BookVersion;
        cout<<"请输入图书的定价： ";
        cin>>BookPirce;
        cout<<endl;
    }
    void show()
    {
        cout<<Bookid<<".";
        cout<<"图书编号: "<<BookID;
        cout<<" 中图分类号: "<<BookChinaID;
        cout<<" 书名:"<<BookName;
        cout<<" 作者:"<<BookAuthor;
        cout<<" 出版社:"<<BookPress;
        cout<<" 出版日期:"<<BookDate;
        cout<<" ISBN:"<<BookISBN;
        cout<<" 版次:"<<BookVersion;
        cout<<" 定价:"<<BookPirce;
        cout<<" 图书的状态:";
        cout<<" 在架上： "<<BookFreeNum;
        cout<<" 借阅中： "<<BookLoanNum;
        cout<<" 被预约： "<<BookReservationNum;
        cout<<endl;
    }
};

void Show_Book(Books *Bookhead)   //显示图书信息
{

    int a=1;
    while(Bookhead)
    {
        Bookhead->Bookid=a;
        Bookhead->show();
        Bookhead=Bookhead->next;
        a++;
    }
}

void Insert_Book(Books *&Bookhead,int sum)  //将读者插入链表
{
    Books *p,*s;
    p=new Books;
    p->setBooks();
    p->Bookid=sum+1;
    s=Bookhead;
    if(sum==0)
    {
        Bookhead=p;
        Bookhead->next=NULL;
        return;
    }
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=p;
    p->next=NULL;
    return;
}

void Modify_Book(Books *&Bookhead,int sum)  //修改图书信息
{
    int temp;
    cout<<"请输入修改图书的方式：";
    cout<<"     1.按馆藏序号修改";
    cout<<"     2.按图书编号修改";
    cin>>temp;
    if(temp==1)
    {
        char tag_1;
        cout<<"是否显示馆藏图书？<Y/N>";
        cin>>tag_1;
        if(tag_1=='Y'||tag_1=='y')
            Show_Book(Bookhead);
        int num,tag;
        Books *p;
        p=Bookhead;
        cout<<"请输入您要修改的序号：";
        cin>>num;
        while(num>sum||num<=0)
        {
            cout<<"输入错误！请重新输入序号：";
            cin>>num;
        }
        cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
        cout<<"                     请选择修改信息：\n";
        cout<<"                     1.图书编号\n";
        cout<<"                     2.中图分类号\n";
        cout<<"                     3.书名\n";
        cout<<"                     4.作者\n";
        cout<<"                     5.出版社\n";
        cout<<"                     6.出版日期\n";
        cout<<"                     7.ISBN\n";
        cout<<"                     8.版次\n";
        cout<<"                     9.定价\n";
        cout<<"                     10.图书数量\n";
        cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
        while(p->Bookid!=num)
        {
            p=p->next;
        }
        cout<<"请选择修改的内容：";
        cin>>tag;
        if(tag==1)
        {
            cout<<"请输入新的图书编号：";
            cin>>p->BookID;
        }
        if(tag==2)
        {
            cout<<"请输入新的中图分类号：";
            cin>>p->BookChinaID;
        }
        if(tag==3)
        {
            cout<<"请输入图书书名：";
            cin>>p->BookName;
        }
        if(tag==4)
        {
            cout<<"请输入图书的作者：";
            cin>>p->BookAuthor;
        }
        if(tag==5)
        {
            cout<<"请输入图书的出版社：";
            cin>>p->BookPress;
        }
        if(tag==6)
        {
            cout<<"请输入图书的出版日期：";
            cin>>p->BookDate;
        }
        if(tag==7)
        {
            cout<<"请输入图书的ISBN：";
            cin>>p->BookISBN;
        }
        if(tag==8)
        {
            cout<<"请输入图书的版次：";
            cin>>p->BookVersion;
        }
        if(tag==9)
        {
            cout<<"请输入图书的定价：";
            cin>>p->BookPirce;
        }
        if(tag==10)
        {
            if(p->BookReservationNum==0&&p->BookLoanNum==0)
            {
                cout<<"请输入图书数量：";
                cin>>p->BookFreeNum;
            }
            else
            {
                cout<<"有借阅或者预约的图书无法修改！\n";
            }
        }
    }
    if(temp==2)
    {
        Books *h;
        h=Bookhead;
        int a=0;
        cout<<"请输入要修改的图书编号：";
        string tag_0;
        while(cin>>tag_0)
        {
            for(Books *p=Bookhead;p!=NULL;p=p->next)
            {
                if(p->BookID==tag_0)
                {
                    a++;
                }
            }
            if(a>0)
            {
                while(h)
                {
                    if(h->BookID==tag_0)
                    {
                        h->show();
                    }
                    h=h->next;
                }
                break;
            }
            if(a==0)
            {
                cout<<"没有相关图书，请重新输入图书编号：";
            }
        }
        cout<<"搜索到的图书是否为要修改的图书？<Y/N>";
        char ans;
        cin>>ans;
        Books *p;
        p=Bookhead;
        while(p->BookID!=tag_0)
        {
            p=p->next;
        }
        if(ans=='Y'||ans=='y')
        {
            cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
            cout<<"                     请选择修改信息：\n";
            cout<<"                     1.图书编号\n";
            cout<<"                     2.中图分类号\n";
            cout<<"                     3.书名\n";
            cout<<"                     4.作者\n";
            cout<<"                     5.出版社\n";
            cout<<"                     6.出版日期\n";
            cout<<"                     7.ISBN\n";
            cout<<"                     8.版次\n";
            cout<<"                     9.定价\n";
            cout<<"                     10.图书数量\n";
            cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
            int tag;
            cout<<"请选择修改的内容：";
            cin>>tag;
            if(tag==1)
            {
                cout<<"请输入新的图书编号：";
                cin>>p->BookID;
            }
            if(tag==2)
            {
                cout<<"请输入新的中图分类号：";
                cin>>p->BookChinaID;
            }
            if(tag==3)
            {
                cout<<"请输入图书书名：";
                cin>>p->BookName;
            }
            if(tag==4)
            {
                cout<<"请输入图书的作者：";
                cin>>p->BookAuthor;
            }
            if(tag==5)
            {
                cout<<"请输入图书的出版社：";
                cin>>p->BookPress;
            }
            if(tag==6)
            {
                cout<<"请输入图书的出版日期：";
                cin>>p->BookDate;
            }
            if(tag==7)
            {
                cout<<"请输入图书的ISBN：";
                cin>>p->BookISBN;
            }
            if(tag==8)
            {
                cout<<"请输入图书的版次：";
                cin>>p->BookVersion;
            }
            if(tag==9)
            {
                cout<<"请输入图书的定价";
                cin>>p->BookPirce;
            }
            if(tag==10)
            {
                if(p->BookReservationNum==0&&p->BookLoanNum==0)
                {
                    cout<<"请输入图书数量：";
                    cin>>p->BookFreeNum;
                }
                else
                {
                    cout<<"有借阅或者预约的图书无法修改！\n";
                }
            }
        }
        else
            return;
    }

}

int Del_Book(Books *&Bookhead,int sum)  //删除图书
{
    Books *p,*h,*q;
    q=h=p=Bookhead;
    cout<<"————————————————————————————————————————————\n";
    cout<<"               请选择功能表：\n";
    cout<<"               1.按馆藏序号删除\n";
    cout<<"               2.按图书编号删除\n";
    cout<<"————————————————————————————————————————————\n";
    int ans;
    cin>>ans;
    if(ans==1)
    {
        char tag;
        cout<<"是否显示馆藏图书<Y/N>:";
        cin>>tag;
        if(tag=='Y'||tag=='y')
        {
            Show_Book(Bookhead);
        }
        cout<<"请输入删除图书的序号:";
        int num;
        cin>>num;
        while(num<=0||num>sum)
        {
            cout<<"输入错误！请重新输入：";
            cin>>num;
        }
        if(Bookhead->Bookid==num)
        {
            char ans_1;
            Bookhead->show();
            cout<<"是否删除此图书？<Y/N>:";
            cin>>ans_1;
            if(ans_1=='Y'||ans_1=='y')
            {
                if(Bookhead->BookLoanNum==0&&Bookhead->BookReservationNum==0)
                {
                    Bookhead=Bookhead->next;
                    cout<<"删除成功！\n";
                    return 1;
                }
                else
                {
                    cout<<"图书被借阅中或者预约中无法删除！\n";
                    return 0;
                }

            }
            else
                return 0;
        }
        q=p=Bookhead;
        while(p->Bookid!=num)
        {
            q=p;
            p=p->next;
        }
        p->show();
        cout<<"是否删除此图书？<Y/N>:";
        char ans_1;
        cin>>ans_1;
        if(ans_1=='Y'||ans_1=='y')
        {
            if(p->BookLoanNum==0&&p->BookReservationNum==0)
            {
                q->next=p->next;
                cout<<"删除成功！\n";
                return 1;
            }
            else
            {
                cout<<"图书被借阅中或者预约中无法删除！\n";
                return 0;
            }
        }
        else
            return 0;
    }
    if(ans==2)
    {
        q=h=p=Bookhead;
        string info;
        int a1=0;
        cout<<"请输入图书编号：";
        cin>>info;
        while(p)
        {
            if(p->BookID==info)
                a1=1;
            p=p->next;
        }
        if(a1==0)
            {
                cout<<"没有搜索到相关图书！\n";
                return 0;
            }
        if(a1==1)
        {
            cout<<"搜索到的信息如下：\n";
            h=Bookhead;
            while(h)
            {
                if(h->BookID==info)
                    h->show();
                h=h->next;
            }
        }
        cout<<"请选择删除的图书序号：";
        int a;
        cin>>a;
        char ans_1;
        if(a==1)
        {
            Bookhead->show();
            cout<<"是否删除此图书？<Y/N>:";
            cin>>ans_1;
            if(ans_1=='Y'||ans_1=='y')
            {
                if(Bookhead->BookLoanNum==0&&Bookhead->BookReservationNum==0)
                {
                    Bookhead=Bookhead->next;
                    cout<<"删除成功！\n";
                    return 1;
                }
                else
                {
                    cout<<"图书被借阅中或者预约中无法删除！\n";
                    return 0;
                }
            }
            else
                return 0;
        }
        q=p=Bookhead;
        while(p->Bookid!=a)
        {
            q=p;
            p=p->next;
        }
        p->show();
        cout<<"是否删除此图书？<Y/N>:";
        char ans_2;
        cin>>ans_2;
        if(ans_2=='Y'||ans_2=='y')
        {
            if(p->BookLoanNum==0&&p->BookReservationNum==0)
            {
                q->next=p->next;
                cout<<"删除成功！\n";
                return 1;
            }
            else
            {
                cout<<"图书被借阅中或者预约中无法删除！\n";
                return 0;
            }
        }
        else
            return 0;
    }
    return 0;
}

void Show_Reader(Reader *Readerhead,int sum) //显示读者信息
{
    int num=0;
    while(Readerhead)
    {
        num++;
        Readerhead->Readerid=num;
        Readerhead->show();
        Readerhead=Readerhead->next;
    }
}

void Insert_Reader(Reader *&Readerhead,int sum)  //将读者插入链表函数
{
    Reader *p,*s;
    char ch;
    cout<<"请先输入要加入的读者类型(a:本科生,b:研究生,c:教师)：";
    cin>>ch;
    while(ch!='a'&&ch!='b'&&ch!='c')
        {
            cout<<"输入错误！请重新输入！";
            cin>>ch;
        }
    if(ch=='a')
    {
        p=new Student;
        p->setReader();
    }
    else
        if(ch=='b')
        {
            p=new GraduateStudent;
            p->setReader();
        }
    else
    {
        p=new Teacher;
        p->setReader();
    }
    p->Readerid=sum+1;
    s=Readerhead;
    if(sum==0)
    {
        Readerhead=p;
        Readerhead->next=NULL;
        return;
    }
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=p;
    p->next=NULL;
    return;
}

int Search_Reader(Reader *Readerhead,string ID)  //寻找相应证件号码的读者
{
    Reader *s;
    s=Readerhead;
    while(s)
    {
        if(s->ReaderID==ID)
            {
                s->show();
                return 1;
            }
        s=s->next;
    }
    return 0;
}

int Search_Ma_Reader(Reader *Readerhead,string ID) //寻找相应证件号码的管理员专用函数
{
    Reader *s;
    s=Readerhead;
    while(s)
    {
        if(s->ReaderID==ID&&s->ReaderManager=='y')
            {
                return 1;
            }
        s=s->next;
    }
    return 0;
}

void Modify_Reader(Reader *&Readerhead,int sum) //修改读者信息函数
{
    int temp1;
    cout<<"请输入修改读者的方式：\n";
    cout<<"         1.按读者序号修改\n";
    cout<<"         2.按证件号码修改\n";
    cin>>temp1;
    if(temp1==1)
    {
        char ch;
        int tag,tag_1;
        Reader *s;
        s=Readerhead;
        cout<<"是否显示读者列表？<Y/N>";
        cin>>ch;
        if(ch=='Y'||ch=='y')
            Show_Reader(Readerhead,sum);
        cout<<"请输入修改的序号：";
        cin>>tag;
        while(tag<=0||tag>sum)
        {
            cout<<"输入错误，请重新输入！";
            cin>>tag;
        }
        cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
        cout<<"                     请选择修改信息：\n";
        cout<<"                     1.证件号码\n";
        cout<<"                     2.读者姓名\n";
        cout<<"                     3.读者单位\n";
        cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
        while(s->Readerid!=tag)
        {
            s=s->next;
        }
        cin>>tag_1;
        if(tag_1==1)
        {
            if(s->ReaderID!="0131122589")
            {cout<<"请输入读者的证件号码：";
            cin>>s->ReaderID;
            cout<<"修改成功！\n";}
            else
            {
                cout<<"无法修改此用户！\n";
            }
        }
        if(tag_1==2)
        {
            cout<<"请输入读者的姓名：";
            cin>>s->ReaderName;
            cout<<"修改成功！\n";
        }
        if(tag_1==3)
        {
            cout<<"请输入读者的单位:";
            cin>>s->ReaderUnit;
            cout<<"修改成功！\n";
        }
    }
    if(temp1==2)
    {
        Reader *h,*q,*s;
        s=q=h=Readerhead;
        cout<<"请输入修改读者的证件号码：";
        string data;
        cin>>data;
        while((Search_Reader(Readerhead,data))!=1)
        {
                cout<<"对不起，搜多不到相关信息！\n";
                cout<<"请确保您的证件号码正确！请重新输入证件号码：";
                cin>>data;
        }
        cout<<"以上信息是否为要修改的读者信息？<Y/N>";
        char tag;
        cin>>tag;
        if(tag=='Y'||tag=='y')
        {
            while(s->ReaderID!=data)
            {
                s=s->next;
            }
            cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
            cout<<"                     请选择修改信息：\n";
            cout<<"                     1.证件号码\n";
            cout<<"                     2.读者姓名\n";
            cout<<"                     3.读者单位\n";
            cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
            int tag_1;
            cin>>tag_1;
            if(tag_1==1)
            {
                if(s->ReaderID=="0131122589")
                {cout<<"请输入读者的证件号码：";
                cin>>s->ReaderID;
                cout<<"修改成功！\n";
                }
                cout<<"无法修改此用户！\n";
            }
            if(tag_1==2)
            {
                cout<<"请输入读者的姓名：";
                cin>>s->ReaderName;
                cout<<"修改成功！\n";
            }
            if(tag_1==3)
            {
                cout<<"请输入读者的单位:";
                cin>>s->ReaderUnit;
                cout<<"修改成功！\n";
            }
        }
        else
            return;

    }
}

int Search_Book(Books *Bookhead,string Name)  //寻找相应名字的图书函数
{
    Books *s;
    s=Bookhead;
    while(s)
    {
        if(s->BookName==Name)
            return 1;
        s=s->next;
    }
    return 0;
}

struct LoanBook  //借阅预约链表
{
    int id;
    Books *book;
    Reader *person;
    char state;
    int Deadline;
    LoanBook *next;
    void show()
    {
        cout<<id<<"."<<"  书名："<<book->BookName<<" 借阅剩余时间： "<<Deadline<<"天 图书编号："<<book->BookID<<" 中图分类号："<<book->BookChinaID;
        cout<<" 图书状态：";
        if(state=='2')
        {
            cout<<" 借阅中 ";
            cout<<"借阅人： "<<person->ReaderName<<" 借阅人证件号： "<<person->ReaderID;
            cout<<" 借阅人类别： ";
        }
        if(state=='1')
        {
            cout<<" 被预约 ";
            cout<<"预约人： "<<person->ReaderName<<" 预约人证件号： "<<person->ReaderID;
            cout<<" 预约人类别： ";
        }
        if(person->ReaderClassification=='a')
        {
            cout<<"本科生 ";
        }
        if(person->ReaderClassification=='b')
        {
            cout<<"研究生 ";
        }
        if(person->ReaderClassification=='c')
        {
            cout<<"教师 ";
        }
        cout<<" 读者单位："<<person->ReaderUnit<<endl;

    }
};

void Insert_LoanBook(LoanBook *&Loanhead,Books *p,Reader *q,int date,int x,int y) //插入借阅预约链表
{
    LoanBook *s,*w;
    w=Loanhead;
    s=new LoanBook;
    s->book=p;
    s->person=q;
    s->Deadline=date;
    s->id=y;
    if(x==1)
        s->state='1';
    else
        s->state='2';
    if(Loanhead==NULL)   //头为空时
    {
        Loanhead=s;
        Loanhead->next=NULL;
    }
    else      //头不为空时
    {
        while(w->next!=NULL)
        {
            w=w->next;
        }
        w->next=s;
        s->next=NULL;
    }
}

void Show_LoanBook(LoanBook *&Loanhead)  //显示借阅预约信息
{
    int num=1;
    LoanBook *h;
    h=Loanhead;
    if(!h)
        cout<<"没有借阅预约信息！\n";
    while(h)
    {
        h->id=num;
        h->show();
        h=h->next;
        num++;
    }
}

int Search_LoanBook(LoanBook *Loanhead,string ad)  //查找借阅人员数据
{
    LoanBook *s;
    s=Loanhead;
    while(s)
    {
        if(s->person->ReaderID==ad)
        {
                return 1;
        }
        s=s->next;
    }
    return 0;
}

int Distinguish(string s)  //识别读者类别函数
{
   if(s=="本科生")
     return 1;
   else
    if(s=="研究生")
     return 2;
   else
   if(s=="教师")
     return 3;
   else
   return 4;
}

void Append_Reader(const char *fileName,Reader *&Readerhead)  //将读者保存数据到文件
{
    ofstream outstuf(fileName,ios::out);
    if(!outstuf)
    {
        cout<<"打开失败！\n";
        return;
    }
    Reader *s;
    s=Readerhead;
    while(s)
    {outstuf<<s->Readerid<<'.';
    outstuf<<"证件号码： "<<s->ReaderID<<" 读者姓名： "<<s->ReaderName;
    outstuf<<" 读者权限: ";
    if(s->ReaderManager=='y')
        outstuf<<"管理员 ";
    if(s->ReaderManager=='n')
        outstuf<<"非管理员 ";
    outstuf<<" 密码： "<<s->ReaderKey;
    outstuf<<" 读者单位： ";
    outstuf<<s->ReaderUnit<<" 读者类型： ";
    if(s->ReaderClassification=='a')
        outstuf<<"本科生 ";
    else
    if(s->ReaderClassification=='b')
        outstuf<<"研究生 ";
    else
        outstuf<<"教师 ";
    outstuf<<"借书数量： "<<s->LoanNumber;
    outstuf<<" 预约数量： "<<s->ReservationNumber<<" 借阅限制数： "<<s->Permission<<'\n';
    s=s->next;
    }
    outstuf.close();
    return;
}

void Append_Book(const char *fileName,Books *&Bookhead)  //将图书保存数据到文件
{
    ofstream outstuf(fileName,ios::out);
    if(!outstuf)
    {
        cout<<"打开失败！\n";
        return;
    }
    Books *s;
    s=Bookhead;
    while(s)
    {outstuf<<s->Bookid<<".";
    outstuf<<"图书编号: "<<s->BookID;
    outstuf<<" 中图分类号: "<<s->BookChinaID;
    outstuf<<" 书名: "<<s->BookName;
    outstuf<<" 作者: "<<s->BookAuthor;
    outstuf<<" 出版社: "<<s->BookPress;
    outstuf<<" 出版日期: "<<s->BookDate;
    outstuf<<" ISBN: "<<s->BookISBN;
    outstuf<<" 版次: "<<s->BookVersion;
    outstuf<<" 定价: "<<s->BookPirce;
    outstuf<<" 图书的状态:";
    outstuf<<"在架上： "<<s->BookFreeNum;
    outstuf<<" 借阅中： "<<s->BookLoanNum;
    outstuf<<" 被预约： "<<s->BookReservationNum;
    outstuf<<'\n';
    s=s->next;
    }
    outstuf.close();
    return;
}

void Append_LoanBook(const char *fileName,LoanBook *&Loanhead)  //将图书借阅预约保存数据到文件
{
    ofstream outstuf(fileName,ios::out);
    if(!outstuf)
    {
        cout<<"打开失败！\n";
        return;
    }
    LoanBook *s;
    s=Loanhead;
    while(s)
    {outstuf<<s->id<<".";
    outstuf<<"书名:"<<s->book->BookName;
    outstuf<<"剩余天数: "<<s->Deadline;
    outstuf<<" 图书编号: "<<s->book->BookID;
    outstuf<<" 中图分类号:"<<s->book->BookChinaID;
    outstuf<<"图书状态: ";
    if(s->state=='1')
    {
        outstuf<<" 被预约 ";
        outstuf<<"预约人：";
        outstuf<<s->person->ReaderName;
        outstuf<<"预约人证件号： ";
        outstuf<<s->person->ReaderID;
        outstuf<<" 预约人类别:";
        if(s->person->ReaderClassification=='a')
            outstuf<<"本科生";
        if(s->person->ReaderClassification=='b')
            outstuf<<"研究生";
        if(s->person->ReaderClassification=='c')
            outstuf<<"教师";
    }
    if(s->state=='2')
    {
        outstuf<<"借阅中 ";
        outstuf<<"借阅人：";
        outstuf<<s->person->ReaderName;
        outstuf<<"借阅人证件号： ";
        outstuf<<s->person->ReaderID;
        outstuf<<" 借阅人人类别：";
        if(s->person->ReaderClassification=='a')
            outstuf<<"本科生";
        if(s->person->ReaderClassification=='b')
            outstuf<<"研究生";
        if(s->person->ReaderClassification=='c')
            outstuf<<"教师";
    }
    outstuf<<"读者单位："<<s->person->ReaderUnit;
    outstuf<<'\n';
    s=s->next;
    }
    outstuf.close();
    return;
}

void Insert_Re_Reader(Reader *&Readerhead,Reader *t) //数据恢复使用的读者插入链表函数
{
    Reader *q,*p;
    q=p=Readerhead;
    if(Readerhead==NULL)
    {
        Readerhead=t;
        Readerhead->next=NULL;
    }
    else
    {
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=t;
        t->next=NULL;
    }
}

int Recovery_Reader(const char *fileName,Reader *& Readerhead)  //读者的数据恢复
{
    ifstream instuf(fileName,ios::in);
    instuf.seekg(0,ios::beg);
    if(!instuf)
    {
        cout<<"打开失败！\n";
        return 0;
    }
    int num=0;
    string x1,x2,x3,x4,x5,x6;
    string y;
    int a,b,c;
    Reader *t;
    while(instuf>>y>>x1>>y>>x2>>y>>x5>>y>>x6>>y>>x3>>y>>x4>>y>>a>>y>>b>>y>>c)
    {
        if((Distinguish(x4)==1))
        {
            t=new Student;
            t->ReaderID=x1;
            t->ReaderName=x2;
            t->ReaderUnit=x3;
            t->ReaderClassification='a';
            if(x5=="非管理员")
            t->ReaderManager='n';
            if(x5=="管理员")
            t->ReaderManager='y';
            t->ReaderKey=x6;
            t->LoanNumber=a;
            t->ReservationNumber=b;
            t->Permission=c;
        }
        else
        if((Distinguish(x4)==2))
        {
            t=new GraduateStudent;
            t->ReaderID=x1;
            t->ReaderName=x2;
            t->ReaderUnit=x3;
            t->ReaderClassification='b';
            if(x5=="非管理员")
            t->ReaderManager='n';
            if(x5=="管理员")
            t->ReaderManager='y';
            t->ReaderKey=x6;
            t->LoanNumber=a;
            t->ReservationNumber=b;
            t->Permission=c;
        }
        else
        {
            t=new Teacher;
            t->ReaderID=x1;
            t->ReaderName=x2;
            t->ReaderUnit=x3;
            t->ReaderClassification='c';
            if(x5=="非管理员")
            t->ReaderManager='n';
            if(x5=="管理员")
            t->ReaderManager='y';
            t->ReaderKey=x6;
            t->LoanNumber=a;
            t->ReservationNumber=b;
            t->Permission=c;
        }
        num++;
        t->Readerid=num;
        Insert_Re_Reader(Readerhead,t);
    }
    instuf.close();
    return num;
}

void Insert_Re_Book(Books *&Bookhead,Books *t)  //数据恢复使用的图书插入函数
{
    Books *q,*p;
    q=p=Bookhead;
    if(Bookhead==NULL)
    {
        Bookhead=t;
        Bookhead->next=NULL;
    }
    else
    {
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=t;
        t->next=NULL;
    }
}

int Recovery_Book(const char *fileName,Books *& Bookhead)  //图书的数据恢复
{
    ifstream instuf(fileName,ios::in);
    instuf.seekg(0,ios::beg);
    if(!instuf)
    {
        cout<<"打开失败！\n";
        return 0;
    }
    int num=0;
    string x1,x2,x3,x4,x5,x6,x7,x8;
    string y;
    int a,b,c;
    double pirce;
    Books *t;
    while(instuf>>y>>x1>>y>>x2>>y>>x3>>y>>x4>>y>>x5>>y>>x6>>y>>x7>>y>>x8>>y>>pirce>>y>>a>>y>>b>>y>>c)
    {
        t=new Books;
        t->BookID=x1;
        t->BookChinaID=x2;
        t->BookName=x3;
        t->BookAuthor=x4;
        t->BookPress=x5;
        t->BookDate=x6;
        t->BookISBN=x7;
        t->BookVersion=x8;
        t->BookPirce=pirce;
        t->BookFreeNum=a;
        t->BookLoanNum=b;
        t->BookReservationNum=c;
        num++;
        t->Bookid=num;
        Insert_Re_Book(Bookhead,t);
    }
    instuf.close();
    return num;
}

int Del_Reader(Reader *&Readerhead,int sum)   //删除读者
{
    Reader *q,*p,*h;
    q=p=h=Readerhead;
    cout<<"————————————————————————————————————————————\n";
    cout<<"               请选择功能表：\n";
    cout<<"               1.按序号删除\n";
    cout<<"               2.按读者证件号码删除\n";
    cout<<"————————————————————————————————————————————\n";
    int ans;
    cin>>ans;
    if(ans==1)
    {
        cout<<"是否显示所有读者？<Y/N>";
        char ans_1;
        cin>>ans_1;
        if(ans_1=='y'||ans_1=='Y')
        {
            Show_Reader(Readerhead,sum);
        }
        cout<<"请输入读者序号：";
        int tag;
        while(cin>>tag)
        {
            for(q=Readerhead;q->Readerid!=tag;q=q->next)
            {
            }
            q->show();
            cout<<"显示的读者是否为要删除的读者？<Y/N>";
            char tag_1;
            cin>>tag_1;
            if(tag_1=='Y'||tag_1=='y')
            {
                if(tag==1)
                {
                      cout<<"无法删除！\n";
                      return 0;
                }
                else
                {
                    while(h->Readerid!=tag)
                    {
                        q=h;
                        h=h->next;
                    }
                    if(h->LoanNumber==0&&h->ReservationNumber==0)
                    {
                        q->next=h->next;
                        h=NULL;
                        cout<<"删除成功！\n";
                        return 1;
                    }
                    else
                    {
                        cout<<"此读者有借阅的书或者预约的书，无法删除！\n";
                        return 0;
                    }
              }
           }
           else
           {
               cout<<"请重新输入序号：";
           }
        }
    }
    if(ans==2)
    {
        q=p=h=Readerhead;
        cout<<"请输入读者证件号码：";
        string temp;
        cin>>temp;
        while((Search_Reader(Readerhead,temp))!=1)
        {
                cout<<"对不起，搜多不到相关信息！\n";
                cout<<"请确保您的证件号码正确！请重新输入证件号码：";
                cin>>temp;
        }
        cout<<"以上读者信息是否为要删除的读者信息<Y/N>";
        char aq;
        cin>>aq;
        if(aq=='Y'||aq=='y')
        {
            while(q->ReaderID!=temp)
            {
                p=q;
                q=q->next;
            }
            if(Readerhead==q)
            {

                cout<<"无法删除！\n";
                return 0;
            }
            if(q->LoanNumber==0&&q->ReservationNumber==0)
            {
                p->next=q->next;
                q=NULL;
                cout<<"删除成功！\n";
                return 1;
            }
            else
            {
                cout<<"此读者有借阅的书或者预约的书，无法删除！\n";
                return 0;
            }
        }
        else
            return 0;
    }
    return 0;
}

int Recovery_LoanBook(const char* fileName,LoanBook*& Loanhead,Books *Bookhead,Reader *Readerhead) //图书借阅数据恢复
{
    ifstream instuf(fileName,ios::in);
    instuf.seekg(0,ios::beg);
    if(!instuf)
    {
        cout<<"打开失败！\n";
        return 0;
    }
    int num=0;
    string x1,x2,x3;
    string y;
    int a;
    int b;
    Books *s;
    Reader *p;
    while(instuf>>y>>a>>y>>x1>>y>>x2>>y>>x3>>y)
    {
        p=Readerhead;
        s=Bookhead;
        if(x2=="借阅中")
        b=2;
        if(x2=="被预约")
        b=1;
        while(s)
        {
            if(s->BookID==x1)
            {
                break;
            }
            s=s->next;

        }
        while(p)
        {
            if(p->ReaderID==x3)
                break;
            p=p->next;
        }
        num++;
        Insert_LoanBook(Loanhead,s,p,a,b,num);
    }
    instuf.close();
    return num;
}

int Get_Key(string key)  //密码掩饰操作
{
    int i;
    char ch;
    char str[20];//用保存输入的密码
    i=0;
    system("cls");
    cout<<"请输入密码：";
    ch=getch() ;
    while(ch!=13)
    {
        if(ch==8&&i>0)//退格键ASII码
        {
            i--;
            str[i]='\0';
            system("cls"); //清屏重新输入
            cout<<"请输入密码：";
            for(int j=0;j<i;j++)
            {
                cout<<"*";
            }
            ch=getch();
        }
        else
        {
            printf("*");
            str[i]=ch;
            i++;
            ch=getch();
        }
    }
    str[i]='\0';
    if(str==key)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

int Fuzzy_search(Books *Bookhead,string s,string a[])  //模糊搜索图书
{
    int j=0;
    for(Books *p=Bookhead;p;p=p->next)
    {
        if(p->BookName.find(s)!=string::npos)
        {
            a[j]=p->BookID;
            j++;
        }
    }
    return j;
}

int main()
{
    LoanBook *Loanhead=NULL;
    Books *Bookhead=NULL;
    Reader *Readerhead=NULL;
    int choice;
    int Booksum=0;
    int Readersum=0;
    int Loansum=0;
    Booksum+=Recovery_Book("e://BookManger//books.txt",Bookhead);  //图书数据恢复
    Readersum+=Recovery_Reader("e://BookManger//reader.txt",Readerhead);  //读者数据恢复
    Loansum+=Recovery_LoanBook("e://BookManger//loanbook.txt",Loanhead,Bookhead,Readerhead);//借阅数据恢复
    cout<<"\n";
    cout<<"              ******************************************\n";
    cout<<"              *            欢迎使用图书管理系统！      *\n";
    cout<<"              *               0.退出系统               *\n";
    cout<<"              *              1.管理员登陆              *\n";
    cout<<"              *             2.普通用户登陆             *\n";
    cout<<"              ******************************************\n";
    int answer;
    string chl,chl1;
    while(cin>>answer)
    {
            if(answer==1)  //管理员系统
            {
            int wrong1=0;
            Reader *h10;
            h10=Readerhead;
            cout<<"请输入用户名：";
            cin>>chl;
            while((Search_Ma_Reader(Readerhead,chl))!=1)
            {
                cout<<"您输入的用户名无效！\n";
                cout<<"请重新输入：";
                cin>>chl;
            }
            while(h10)
            {
                 if(h10->ReaderID==chl)
                      break;
                  h10=h10->next;
            }
            while(1)
            {
                 int quee=Get_Key(h10->ReaderKey);
                 if(quee==1)
                    break;
                 else
                 {
                     cout<<"密码错误！是否重新输入？<Y/N>";
                     char bad;
                     cin>>bad;
                     if(bad=='N'||bad=='n')
                     {
                         wrong1=1;
                         break;
                     }
                 }
             }
    if(wrong1==0)
    {cout<<endl;
    cout<<"*******************************************************************************\n";
    cout<<"                        请选择功能：\n";
    cout<<"                        0.返回上一层.\n";
    cout<<"                        1.图书信息管理.\n";
    cout<<"                        2.借阅人员信息管理.\n";
    cout<<"                        3.图书借阅.\n";
    cout<<"                        4.图书预约.\n";
    cout<<"                        5.图书延期与还书.\n";
    cout<<"                        6.信息查询.\n";
    cout<<"                        7.信息统计.\n";
    cout<<"                        8.管理管理员.\n";
    cout<<"*******************************************************************************\n";
    while(cin>>choice)
    {
        if(choice==0)
        {
            Append_Book("e://BookManger//books.txt",Bookhead);
            Append_Reader("e://BookManger//reader.txt",Readerhead);
            Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            break;
        }
        if(choice==1)
        {
            int choice1;
            cout<<"———————————————————————————————————————\n";
            cout<<"　　　　　　　　　　　 请选择功能：\n";
            cout<<"                       0.返回上一层.\n";
            cout<<"                       1.录入图书.\n";
            cout<<"                       2.修改图书信息.\n";
            cout<<"                       3.删除图书.\n";
            cout<<"                       4.查看所有图书.\n";
            cout<<"———————————————————————————————————————\n";
            while(cin>>choice1)
            {
                if(choice1==0)
                break;
                if(choice1==1)
                {
                    int choice2;
                    cout<<"＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n";
                    cout<<"                    请选择功能：\n";
                    cout<<"                    1.按数量录入\n";
                    cout<<"                    2.单个录入\n";
                    cout<<"＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n";
                    cin>>choice2;
                    if(choice2==1)
                    {
                        int num;
                        cout<<"请输入图书的数量：\n";
                        cin>>num;
                        while(num--)
                        {
                            Insert_Book(Bookhead,Booksum);
                            Booksum+=1;
                        }
                    }
                    if(choice2==2)
                    {
                        Insert_Book(Bookhead,Booksum);
                        Booksum+=1;
                    }
                    Append_Book("e://BookManger//books.txt",Bookhead);
                }
                if(choice1==2)
                {
                    Modify_Book(Bookhead,Booksum);
                    Append_Book("e://BookManger//books.txt",Bookhead);
                }
                if(choice1==3)
                {
                    Booksum-=Del_Book(Bookhead,Booksum);
                    Append_Book("e://BookManger//books.txt",Bookhead);
                }
                if(choice1==4)
                {
                    Show_Book(Bookhead);
                    Append_Book("e://BookManger//books.txt",Bookhead);
                }
                cout<<"———————————————————————————————————————\n";
                cout<<"　　　　　　　　　　　 请选择功能：\n";
                cout<<"                       0.返回上一层.\n";
                cout<<"                       1.录入图书.\n";
                cout<<"                       2.修改图书信息.\n";
                cout<<"                       3.删除图书.\n";
                cout<<"                       4.查看所有图书.\n";
                cout<<"———————————————————————————————————————\n";
            }
        }
        if(choice==2)
        {
            int choice1;
            cout<<"———————————————————————————————————————\n";
            cout<<"　　　　　　　　　　　 请选择功能：\n";
            cout<<"                       0.返回上一层.\n";
            cout<<"                       1.录入读者.\n";
            cout<<"                       2.修改读者信息.\n";
            cout<<"                       3.删除读者信息.\n";
            cout<<"                       4.查看所有读者.\n";
            cout<<"———————————————————————————————————————\n";
            while(cin>>choice1)
            {
                if(choice1==0)
                break;
                if(choice1==1)
                {
                    int choice2;
                    cout<<"＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n";
                    cout<<"                    请选择功能：\n";
                    cout<<"                    1.按数量录入\n";
                    cout<<"                    2.单个录入\n";
                    cout<<"＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n";
                    cin>>choice2;
                    if(choice2==1)
                    {
                        int num;
                        cout<<"请输入读者的数量：\n";
                        cin>>num;
                        while(num--)
                        {
                            Insert_Reader(Readerhead,Readersum);
                            Readersum+=1;
                        }
                    }
                    if(choice2==2)
                    {
                        Insert_Reader(Readerhead,Readersum);
                        Readersum+=1;
                    }
                    Append_Reader("e://BookManger//reader.txt",Readerhead);
                }
                if(choice1==2)
                {
                    Modify_Reader(Readerhead,Readersum);
                    Append_Reader("e://BookManger//reader.txt",Readerhead);
                }
                if(choice1==3)
                {
                    Readersum-=Del_Reader(Readerhead,Readersum);
                    Append_Reader("e://BookManger//reader.txt",Readerhead);
                }
                if(choice1==4)
                {
                    Show_Reader(Readerhead,Readersum);
                    Append_Reader("e://BookManger//reader.txt",Readerhead);
                }
                cout<<"———————————————————————————————————————\n";
                cout<<"　　　　　　　　　　　 请选择功能：\n";
                cout<<"                       0.返回上一层.\n";
                cout<<"                       1.录入读者.\n";
                cout<<"                       2.修改读者信息.\n";
                cout<<"                       3.删除读者信息.\n";
                cout<<"                       4.查看所有读者.\n";
                cout<<"———————————————————————————————————————\n";
            }
        }
        if(choice==3)
        {
            int ans;
            char a1;
            string Name;
            cout<<"是否借阅预约的图书？<Y/N>";
            cin>>a1;
            if(a1=='Y'||a1=='y')
            {
                string a0;
                LoanBook *b1,*b2,*b4;
                int b=0,f=0,e=0;
                b4=b1=b2=Loanhead;
                cout<<"请输入您的证件号码：";
                cin>>a0;
                while((Search_LoanBook(Loanhead,a0))!=1)
                {
                    cout<<"对不起，搜不到相关信息！\n";
                    cout<<"请确保您的证件号码正确！重新输入证件号码：";
                    cin>>a0;
                }
                while(b1)
                {
                    if(b1->person->ReaderID==a0&&b1->state=='1')
                    {
                        b1->show();
                        b++;
                        if(b1->book->BookFreeNum>0)
                        {
                            f++;
                        }
                    }
                    b1=b1->next;
                }
                if(b>0&&f!=0)
                 {
                    int b3;
                    cout<<"请输入您要选择借阅的图书序号：";
                    cin>>b3;
                    b4=Loanhead;
                    while(b4)
                   {
                    if(b4->person->ReaderID==a0&&b4->state=='1')
                    {
                        b++;
                        if(b4->book->BookFreeNum>0)
                        {
                            e++;
                        }
                        break;
                    }
                    b4=b4->next;
                    }
                    if(e>0)
                    {cout<<"请输入借阅的天数：<天数少于30>";
                    int date;
                    cin>>date;
                    while(date<=0||date>30)
                    {
                        cout<<"请重新输入！";
                        cin>>date;
                    }
                    while(b2)
                    {
                        if(b2->id==b3)
                        {
                            b2->person->LoanNumber+=1;
                            b2->person->ReservationNumber-=1;
                            b2->book->BookFreeNum-=1;
                            b2->book->BookReservationNum-=1;
                            b2->book->BookLoanNum+=1;
                            b2->Deadline=date;
                            b2->state='2';
                            break;
                        }
                        b2=b2->next;
                    }
                    cout<<"借书成功！\n";
                }
                else
                {
                    cout<<"此图书还没有空闲的，请再耐心等待！\n";
                }
                 }
                else
                if(b>0)
                {
                    cout<<"1此图书还没有空闲的，请再耐心等待！\n";
                }
                else
                {
                    cout<<"您没有预约!\n";
                }
            }
            else
            {
                cout<<"︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿\n";
                cout<<"                     请选择动能表：\n";
                cout<<"                     1.按名借书\n";
                cout<<"                     2.搜索借书\n";
                cout<<"︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿\n";
                cin>>ans;
                if(ans==1)
                {
                    Books *s,*p;
                    p=s=Bookhead;
                    int tag;
                    int tag_1=1;
                    cout<<"请输入书的全名：";
                    while(cin>>Name)
                    {
                         while((Search_Book(Bookhead,Name))!=1)
                        {
                            cout<<"没有搜索到相关的图书！\n";
                            cout<<"请在此输入书名：";
                            cin>>Name;
                        }
                        cout<<"搜索到的图书列表如下：\n";
                        for(s=Bookhead;s!=NULL;s=s->next)
                        {
                            if(s->BookName==Name)
                            {
                                 s->show();
                            }
                        }
                        cout<<"请输入要借阅图书的序号：";
                        cin>>tag;
                        for(p=Bookhead;p->Bookid!=tag;p=p->next)
                       {
                       }
                       if(p->BookFreeNum-p->BookReservationNum>=tag_1)
                        {
                            break;
                        }
                       else
                       {
                           cout<<"此图书不能被借阅，因为没有足够的图书！\n";
                           cout<<"请重新输入书名：";
                       }
                   }
                   Reader *q;
                   q=Readerhead;
                   string ReaderID1;
                   char ans_1,ans_2;
                   cout<<"请输入借阅人的证件号码：";
                   while(cin>>ReaderID1)
                   {
                        if((Search_Reader(Readerhead,ReaderID1))==1)
                        {
                             cout<<"搜索到的借阅人是否为借阅本人？<Y/N>";
                             cin>>ans_1;
                             if(ans_1=='Y'||ans_1=='y')
                             {
                                  break;
                             }
                        }
                        else
                        {
                            cout<<"如果是最新借阅人是否添加新的借阅人并输入信息？<Y/N>";
                            cin>>ans_2;
                            if(ans_2=='Y'||ans_2=='y')
                            {
                                Insert_Reader(Readerhead,Readersum);
                                break;
                            }
                            else
                            cout<<"证件号码输入错误！请重新输入：";

                        }

                    }
                if(ans_1=='Y'||ans_1=='y')
                {
                    while(q->ReaderID!=ReaderID1)
                    {
                        q=q->next;
                    }
                }
                if(ans_2=='Y'||ans_2=='y')
                {
                    while(q->next!=NULL)
                    {
                        q=q->next;
                    }
                }
                if(q->Permission>=(tag_1+q->ReservationNumber+q->LoanNumber))
                {
                    cout<<"请输入借阅天数<天数少羽30>：";
                    int date_1;
                    cin>>date_1;
                    while(date_1<=0||date_1>30)
                    {
                        cout<<"输入错误！请重新输入：";
                        cin>>date_1;
                    }
                    q->LoanNumber+=tag_1;
                    p->BookLoanNum+=tag_1;
                    p->BookFreeNum-=tag_1;
                    Loansum+=tag_1;
                    Insert_LoanBook(Loanhead,p,q,date_1,2,Loansum);
                    cout<<"借阅成功，请将图书妥善保管！\n";
                }
                else
                {
                    cout<<"已经达到借书限制！无法借书！";
                }
                }
                if(ans==2)
                {
                    Books *s,*p,*h;
                    h=p=s=Bookhead;
                    int tag;
                    int tag_1=1;
                    int sum;
                    string base[100];
                    cout<<"请输入关键词：";
                    while(cin>>Name)
                    {
                        sum=Fuzzy_search(Bookhead,Name,base);
                        h=Bookhead;
                        while(h)
                        {
                            for(int i=0;i<sum;i++)
                            {
                                if(h->BookID==base[i])
                                {
                                    h->show();
                                }
                            }
                            h=h->next;
                        }
                        if(sum==0)
                            cout<<"没有搜索到任何信息！\n";
                        cout<<"是否重新搜索？<Y/N>";
                        char question;
                        cin>>question;
                        if(question=='N'||question=='n')
                        {
                            cout<<"已经搜索到自己想要的图书？是否借书？<Y/N>";
                            char answer;
                            cin>>answer;
                            if(answer=='Y'||answer=='y')
                            {
                                cout<<"请输入要借阅图书的序号：";
                                cin>>tag;
                                for(p=Bookhead;p->Bookid!=tag;p=p->next)
                                {
                                }
                                if(p->BookFreeNum-p->BookReservationNum>=tag_1)
                                {
                                    break;
                                }
                             }
                             else
                             {
                                 cout<<"此图书不能被借阅，因为没有足够的图书！\n";
                                 cout<<"请重新输入关键词：";
                             }
                             break;
                        }
                        cout<<"请输入关键词：";
                    }
                    Reader *q;
                    q=Readerhead;
                    string ReaderID1;
                    char ans_1,ans_2;
                    tag_1=1;
                    cout<<"请输入借阅人的证件号码：";
                    while(cin>>ReaderID1)
                    {
                        if((Search_Reader(Readerhead,ReaderID1))==1)
                        {
                             cout<<"搜索到的借阅人是否为借阅本人？<Y/N>";
                             cin>>ans_1;
                             if(ans_1=='Y'||ans_1=='y')
                             {
                                  break;
                             }
                        }
                        else
                        {
                            cout<<"如果是最新借阅人是否添加新的借阅人并输入信息？<Y/N>";
                            cin>>ans_2;
                            if(ans_2=='Y'||ans_2=='y')
                            {
                                Insert_Reader(Readerhead,Readersum);
                                break;
                            }
                            else
                            cout<<"证件号码输入错误！请重新输入：";

                        }

                    }
                    if(ans_1=='Y'||ans_1=='y')
                    {
                        while(q->ReaderID!=ReaderID1)
                        {
                             q=q->next;
                        }
                    }
                    if(ans_2=='Y'||ans_2=='y')
                    {
                         while(q->next!=NULL)
                         {
                              q=q->next;
                         }
                    }
                    if(q->Permission>=(tag_1+q->ReservationNumber+q->LoanNumber))
                    {
                        cout<<"请输入借阅天数<天数少羽30>：";
                        int date_1;
                        cin>>date_1;
                        while(date_1<=0||date_1>30)
                        {
                             cout<<"输入错误！请重新输入：";
                             cin>>date_1;
                        }
                        q->LoanNumber+=tag_1;
                        p->BookLoanNum+=tag_1;
                        p->BookFreeNum-=tag_1;
                        Loansum+=1;
                        Insert_LoanBook(Loanhead,p,q,date_1,2,Loansum);
                        cout<<"借阅成功，请将图书妥善保管！\n";
                    }
                    else
                    {
                        cout<<"已经达到借书限制！无法借书！";
                    }
                }
            }
            Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            Append_Book("e://BookManger//books.txt",Bookhead);
            Append_Reader("e://BookManger//reader.txt",Readerhead);
        }
        if(choice==4)
        {
            int ans;
            string Name;
            cout<<"︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿\n";
            cout<<"                     请选择动能表：\n";
            cout<<"                     1.按名预约\n";
            cout<<"                     2.按馆藏序号预约\n";
            cout<<"︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿\n";
            cin>>ans;
            if(ans==1)
            {
                Books *s,*p;
                p=s=Bookhead;
                int tag;
                int temp=0;
                cout<<"请输入书名：";
                while(cin>>Name)
                {
                    while((Search_Book(Bookhead,Name))!=1)
                    {
                        cout<<"没有搜索到相关的图书！\n";
                        cout<<"请在此输入书名：";
                        cin>>Name;
                    }
                    cout<<"搜索到的图书列表如下：";
                    for(s=Bookhead;s!=NULL;s=s->next)
                    {
                        if(s->BookName==Name)
                        {
                            s->show();
                        }
                    }
                    cout<<"请输入要预约图书的序号：";
                    cin>>tag;
                    for(p=Bookhead;p->Bookid!=tag;p=p->next)
                    {
                    }
                    if(p->BookFreeNum==0)
                    {
                        break;
                    }
                    else
                    {
                        cout<<"此图书有空闲，无需预约！\n";
                        temp=1;
                        break;
                    }
                }
                if(temp==0)
                {
                    Reader *q;
                    q=Readerhead;
                    string ReaderID1;
                    char ans_1,ans_2;
                    cout<<"请输入预约人的证件号码：";
                    while(cin>>ReaderID1)
                    {
                         if((Search_Reader(Readerhead,ReaderID1))==1)
                        {
                            cout<<"搜索到的预约人是否为借阅本人？<Y/N>";
                            cin>>ans_1;
                            if(ans_1=='Y'||ans_1=='y')
                            {
                                 break;
                            }
                        }
                        else
                       {
                           cout<<"如果是最新读者是否添加新的读者并输入信息？<Y/N>";
                           cin>>ans_2;
                           if(ans_2=='Y'||ans_2=='y')
                           {
                               Insert_Reader(Readerhead,Readersum);
                               break;
                           }
                           else
                           cout<<"证件号码输入错误！请重新输入：";

                       }

                    }
                    if(ans_1=='Y'||ans_1=='y')
                    {
                        q=Readerhead;
                        while(q->ReaderID!=ReaderID1)
                       {
                            q=q->next;
                       }
                    }
                    if(ans_2=='Y'||ans_2=='y')
                    {
                        q=Readerhead;
                        while(q->next!=NULL)
                        {
                            q=q->next;
                        }
                    }
                    if(q->Permission>=(1+q->ReservationNumber+q->LoanNumber))
                    {
                         cout<<"请输入取书天数<天数少于20>：";
                        int date_1;
                        cin>>date_1;
                        while(date_1<=0||date_1>20)
                        {
                            cout<<"输入错误！请重新输入：";
                            cin>>date_1;
                        }
                        q->ReservationNumber+=1;
                        p->BookReservationNum+=1;
                        Loansum+=1;
                        Insert_LoanBook(Loanhead,p,q,date_1,1,Loansum);
                        cout<<"预约成功，当有空闲图书时请及时取书！\n";
                        Append_Book("e://BookManger//books.txt",Bookhead);
                        Append_Reader("e://BookManger//reader.txt",Readerhead);
                        Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
                    }
                    else
                    {
                         cout<<"已经达到借书限制！无法预约！";
                    }
                }
            }
            if(ans==2)
            {
                cout<<"是否显示所有图书？<Y/N>";
                char ch;
                cin>>ch;
                if(ch=='Y'||ch=='y')
                {
                    int temp;
                    Reader *q;
                    q=Readerhead;
                    Books *p;
                    p=Bookhead;
                    Show_Book(Bookhead);
                    cout<<"请输入预约的序号：";
                    while(cin>>temp)
                    {
                        if(temp>=0&&temp<Booksum)
                            break;
                        else
                        {
                            cout<<"输入错误！请重新输入：";
                        }
                    }
                    Books *h;
                    h=Bookhead;
                    while(h->Bookid!=temp)
                    {
                        h=h->next;
                    }
                    h->show();
                    cout<<"以上信息是否为要预约的图书！？<Y/N>";
                    for(p=Bookhead;p->Bookid!=temp;p=p->next)
                    {
                    }
                    char ans_0;
                    cin>>ans_0;
                    if(ans_0=='Y'||ans_0=='y')
                    {
                        if(h->BookFreeNum!=0)
                        {
                            cout<<"此图书有空闲，无需预约！\n";
                        }
                        else
                        {
                            char ans_1,ans_2;
                            string ReaderID1;
                            cout<<"请输入预约人的证件号码：";
                            while(cin>>ReaderID1)
                            {
                                if((Search_Reader(Readerhead,ReaderID1))==1)
                                {
                                    cout<<"搜索到的预约人是否为借阅本人？<Y/N>";
                                    cin>>ans_1;
                                    if(ans_1=='Y'||ans_1=='y')
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    cout<<"如果是最新读者是否添加新的读者并输入信息？<Y/N>";
                                    cin>>ans_2;
                                    if(ans_2=='Y'||ans_2=='y')
                                    {
                                        Insert_Reader(Readerhead,Readersum);
                                        break;
                                    }
                                    else
                                    cout<<"证件号码输入错误！请重新输入：";

                                }
                            }
                            if(ans_1=='Y'||ans_1=='y')
                            {
                                while(q->ReaderID!=ReaderID1)
                                {
                                    q=q->next;
                                }
                            }
                            if(ans_2=='Y'||ans_2=='y')
                            {
                                while(q->next!=NULL)
                                {
                                    q=q->next;
                                }
                            }
                            if(q->Permission>=(1+q->ReservationNumber+q->LoanNumber))
                            {
                                cout<<"请输入取书天数<天数少于20>：";
                                int date_1;
                                cin>>date_1;
                                while(date_1<=0||date_1>20)
                                {
                                    cout<<"输入错误！请重新输入：";
                                    cin>>date_1;
                                }
                                q->ReservationNumber+=1;
                                p->BookReservationNum+=1;
                                Loansum+=1;
                                Insert_LoanBook(Loanhead,p,q,date_1,1,Loansum);
                                cout<<"预约成功，当有空闲图书时请及时取书！\n";
                            }
                        }
                    }
                }
            }
            Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            Append_Book("e://BookManger//books.txt",Bookhead);
            Append_Reader("e://BookManger//reader.txt",Readerhead);
        }
        if(choice==5)
        {
            int choice1;
            cout<<"====================================\n";
            cout<<"             请选择功能表：\n";
            cout<<"             1.还书\n";
            cout<<"             2.借阅延期\n";
            cout<<"             3.图书借约查看\n";
            cout<<"====================================\n";
            cin>>choice1;
            if(choice1==1)
            {
                LoanBook *s,*p,*h;
                s=p=Loanhead;
                cout<<"请输入借阅图书的证件号码：";
                string tag;
                int a=0;
                while(cin>>tag)
                {
                    for(h=Loanhead;h!=NULL;h=h->next)
                    {
                        if(h->person->ReaderID==tag)
                        {
                            h->show();
                            a++;
                        }
                    }
                    if(a>0)
                    {
                        cout<<"以上信息是否为借书信息？<Y/N>";
                        char ans_1;
                        cin>>ans_1;
                        if(ans_1=='y'||ans_1=='Y')
                        {
                            if(Loanhead->person->ReaderID==tag)
                            {
                                Loanhead->person->LoanNumber-=1;
                                Loanhead->book->BookLoanNum-=1;
                                Loanhead->book->BookFreeNum+=1;
                                Loanhead=Loanhead->next;
                                //delete p;
                                //p=NULL;
                                cout<<"还书成功！\n";
                                Loansum-=1;
                                break;
                            }
                            else
                            {
                                s=Loanhead;
                                while(s->person->ReaderID!=tag)
                                {
                                    p=s;
                                    s=s->next;
                                }
                                s->person->LoanNumber-=1;
                                s->book->BookLoanNum-=1;
                                s->book->BookFreeNum+=1;
                                p->next=s->next;
                                Loansum-=1;
                                cout<<"还书成功！\n";
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout<<"输入错误或者没有借书记录！是否继续输入证件号？<Y/N>";
                        char ans;
                        cin>>ans;
                        if(ans=='Y'||ans=='y')
                        {
                            cout<<"请重新输入证件号码：";
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
                Append_Book("e://BookManger//books.txt",Bookhead);
                Append_Reader("e://BookManger//reader.txt",Readerhead);
            }
            if(choice1==2)
            {
                LoanBook *s,*h;
                s=Loanhead;
                cout<<"延期要求用户所剩的借阅时间不得超过10天！\n";
                cout<<"请输入借阅图书的证件号码：";
                string tag;
                int a=0;
                while(cin>>tag)
                {
                    for(h=Loanhead;h!=NULL;h=h->next)
                    {
                        if(h->person->ReaderID==tag)
                        {
                            h->show();
                            a++;
                        }
                    }
                    if(a>0)
                    {
                        cout<<"以上信息是否为借书信息？<Y/N>";
                        char ans_1;
                        cin>>ans_1;
                        if(ans_1=='y'||ans_1=='Y')
                        {
                            if(Loanhead->person->ReaderID==tag)
                            {
                                if(Loanhead->Deadline>=11)
                                {
                                    cout<<"所剩借阅时间超过延期要求！\n";
                                    break;
                                }
                                cout<<"请输入延长的时间(最长不超过20天)：";
                                int a;
                                while(cin>>a)
                                {
                                    if(a>0&&a<=20)
                                        break;
                                    else
                                    {
                                        cout<<"请重新输入！(最长不超过20天)\n";
                                    }
                                }
                                Loanhead->Deadline+=a;
                                cout<<"延期成功！\n";
                                break;
                            }
                            else
                            {
                                while(s->person->ReaderID!=tag)
                                {
                                    s=s->next;
                                }
                                if(s->Deadline>=11)
                                {
                                    cout<<"所剩借阅时间超过延期要求！\n";
                                    break;
                                }
                                cout<<"请输入延长的时间(最长不超过20天)：";
                                int c;
                                while(cin>>c)
                                {
                                    if(c>0&&c<=20)
                                        break;
                                    else
                                    {
                                        cout<<"请重新输入！(最长不超过20天)\n";
                                    }
                                }
                                s->Deadline+=c;
                                cout<<"延期成功！\n";
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout<<"输入错误！是否继续输入证件号？<Y/N>";
                        char ans;
                        cin>>ans;
                        if(ans=='Y'||ans=='y')
                        {
                            cout<<"请重新输入证件号码：";
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                Append_Book("e://BookManger//books.txt",Bookhead);
                Append_Reader("e://BookManger//reader.txt",Readerhead);
                Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            }
            if(choice1==3)
            {
                Show_LoanBook(Loanhead);
                Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            }
        }
        if(choice==6)
        {
            cout<<"______________________________________________________\n";
            cout<<"                       请选择功能：\n";
            cout<<"                       1.查询书籍信息.\n";
            cout<<"                       2.查询人员信息.\n";
            cout<<"______________________________________________________\n";
            int choice1;
            cin>>choice1;
            if(choice1==1)
            {
                 Books *h;
                 LoanBook *p;
                 p=Loanhead;
                 string s;
                 int sum=0;
                 int num=0;
                 cout<<"请输入图书编号：";
                 while(cin>>s)
                 {
                    h=Bookhead;
                    while(h)
                    {
                        if(h->BookID==s)
                        {
                            cout<<"此图书信息如下：\n";
                            h->show();
                            if(h->BookLoanNum!=0||h->BookReservationNum!=0)
                            {
                                while(p)
                                {
                                    if(p->book->BookID==s)
                                    {
                                        num++;
                                        if(num==1)
                                        cout<<"本图书的借阅和预约信息如下：\n";
                                        p->show();
                                    }
                                    p=p->next;
                                }
                            }
                            sum++;
                            if(num==0)
                                cout<<"此图书没有借阅预约信息！\n";
                            break;
                        }
                        h=h->next;
                    }
                    if(sum==0)
                    {
                        cout<<"没有相关信息！是否重新输入编号？<Y/N>";
                        char ans;
                        cin>>ans;
                        if(ans=='N'||ans=='n')
                        {
                            break;
                        }
                    }
                    else
                        break;
                 }
            }
            if(choice1==2)
            {
                Reader *h;
                LoanBook *p;
                p=Loanhead;
                string s;
                int sum=0;
                int num=0;
                cout<<"请输入读者证件号码：";
                while(cin>>s)
                {
                    h=Readerhead;
                    while(h)
                    {
                        if(h->ReaderID==s)
                        {
                            cout<<"此读者信息如下：\n";
                            h->show();
                            if(h->LoanNumber!=0||h->ReservationNumber!=0)
                            {
                                while(p)
                                {
                                    if(p->person->ReaderID==s)
                                    {
                                        num++;
                                        if(num==1)
                                        cout<<"本读者的借阅和预约信息如下：\n";
                                        p->show();
                                    }
                                    p=p->next;
                                }
                            }
                            sum++;
                            if(num==0)
                                cout<<"此读者没有借阅预约信息！\n";
                            break;
                        }
                        h=h->next;
                    }
                    if(sum==0)
                    {
                        cout<<"没有相关信息！是否重新输入证号？<Y/N>";
                        char ans;
                        cin>>ans;
                        if(ans=='N'||ans=='n')
                        {
                            break;
                        }
                    }
                    else
                        break;
                 }
            }
        }
        if(choice==7)
        {
            int choice1;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"                   请选择功能表：\n";
            cout<<"                   0.返回上一层.\n";
            cout<<"                   1.图书信息统计.\n";
            cout<<"                   2.读者信息统计.\n";
            cout<<"                   3.借约信息统计.\n";
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            while(cin>>choice1)
            {
                if(choice1==0)
                    break;
                if(choice1==1)
                {
                    int choice2;
                    cout<<"_____________________________________________\n";
                    cout<<"               1.馆藏书籍显示\n";
                    cout<<"               2.按图书类别显示\n";
                    cout<<"               3.馆藏图书状态\n";
                    cout<<"_____________________________________________\n";
                    cin>>choice2;
                    if(choice2==1)
                    {
                        Show_Book(Bookhead);
                    }
                    if(choice2==2)
                    {
                        int a[100][100];
                        string b[100];
                        Books *h;
                        int i=0,k,j;
                        h=Bookhead;
                        while(h)
                        {
                            k=0;
                            if(h==Bookhead)
                            {
                                b[0]=h->BookChinaID;
                                a[0][h->Bookid]=h->Bookid;
                                i++;
                            }
                            else
                            {
                                for(j=0;j<i;j++)
                                {
                                    if(h->BookChinaID==b[j])
                                        {
                                            k=1;
                                            a[j][h->Bookid]=h->Bookid;
                                            break;
                                        }
                                }
                                if(k!=1)
                                {
                                    b[i]=h->BookChinaID;
                                    a[i][h->Bookid]=h->Bookid;
                                    i++;
                                }
                            }
                            h=h->next;
                        }
                        for(int m=0;m<i;m++)
                        {
                            cout<<"中图分类号为"<<b[m]<<"的：\n";
                            for(int n=0;n<100;n++)
                            {
                                for(Books *s=Bookhead;s!=NULL;s=s->next)
                                {
                                    if(s->Bookid==a[m][n]&&a[m][n]!=0)
                                    {
                                        s->show();
                                    }
                                }
                            }
                            cout<<endl<<endl;
                        }
                    }
                    if(choice2==3)
                    {
                        int sum1=0,sum2=0,sum3=0;
                        Books *h;
                        h=Bookhead;
                        while(h)
                        {
                            sum1+=h->BookLoanNum;
                            sum2+=h->BookReservationNum;
                            sum3+=h->BookFreeNum;
                            h=h->next;
                        }
                        cout<<"图书馆中一共有"<<Booksum<<"种图书，";
                        cout<<"在架上"<<sum3<<"本图书"<<endl;
                        cout<<"被借阅"<<sum1<<"本图书，";
                        cout<<"被预约"<<sum2<<"本图书"<<endl;
                    }
                }
                if(choice1==2)
                {
                    int choice2;
                    cout<<"_____________________________________________\n";
                    cout<<"               1.所有读者显示\n";
                    cout<<"               2.按学院显示\n";
                    cout<<"_____________________________________________\n";
                    cin>>choice2;
                    if(choice2==1)
                    {
                        Show_Reader(Readerhead,Readersum);
                    }
                    if(choice2==2)
                    {
                        int a[50][50];
                        string b[50];
                        Reader *h;
                        int i=0,k,j;
                        h=Readerhead;
                        while(h)
                        {
                            k=0;
                            if(h==Readerhead)
                            {
                                b[0]=h->ReaderUnit;
                                a[0][h->Readerid]=h->Readerid;
                                i++;
                            }
                            else
                            {
                                for(j=0;j<i;j++)
                                {
                                    if(h->ReaderUnit==b[j])
                                        {
                                            k=1;
                                            a[j][h->Readerid]=h->Readerid;
                                            break;
                                        }
                                }
                                if(k!=1)
                                {
                                    b[i]=h->ReaderUnit;
                                    a[i][h->Readerid]=h->Readerid;
                                    i++;
                                }
                            }
                            h=h->next;
                        }
                        for(int m=0;m<i;m++)
                        {
                            cout<<b[m]<<"的：\n";
                            for(int n=0;n<50;n++)
                            {
                                for(Reader *s=Readerhead;s!=NULL;s=s->next)
                                {
                                    if(s->Readerid==a[m][n]&&a[m][n]!=0)
                                    {
                                        s->show();
                                    }
                                }
                            }
                            cout<<endl<<endl;
                        }
                    }
                }
                if(choice1==3)
                {
                    Show_LoanBook(Loanhead);
                }
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                cout<<"                   请选择功能表：\n";
                cout<<"                   0.返回上一层.\n";
                cout<<"                   1.图书信息统计.\n";
                cout<<"                   2.读者信息统计.\n";
                cout<<"                   3.借约信息统计.\n";
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            }
        }
        if(choice==8)
        {
            if(h10->ReaderID=="0131122589")
            {cout<<"\n1.增加管理员\n";
             cout<<"2.删除管理员\n";
             int tag;
             cin>>tag;
             if(tag==1)
             {
                cout<<"请输入提升为管理员的证件号码：";
                string s;
                Reader *h,*p;
                p=h=Readerhead;
                int num=0;
                while(cin>>s)
                {
                  while(h)
                  {
                    if(h->ReaderID==s)
                    {
                        h->show();
                        num++;
                        break;
                    }
                    h=h->next;
                }
                if(num==0)
                {
                    cout<<"没有搜索到相关信息！\n";
                    break;
                }
                if(num>0)
                {
                    cout<<"是否将此人提升为管理员？<Y/N>";
                    char ans;
                    cin>>ans;
                    if(ans=='Y'||ans=='y')
                    {
                       while(p)
                       {
                           if(p->ReaderID==s)
                           {
                               p->ReaderManager='y';
                               break;
                           }
                           p=p->next;

                       }
                       break;
                    }
                    else
                        break;
                }
            }
             }
             if(tag==2)
             {
                 Reader *s,*h;
                 h=s=Readerhead;
                 while(s)
                 {
                     if(s->ReaderManager=='y')
                     {
                         s->show();
                     }
                     s=s->next;
                 }
                 cout<<"请输入选择删除的管理员序号：";
                 int ans;
                 cin>>ans;
                 while(h)
                 {
                     if(h->Readerid==ans)
                     {
                         if(h->ReaderID=="0131122589")
                         {
                             cout<<"无法修改此用户！\n";
                             break;
                         }
                         else
                         {
                             h->ReaderManager='n';
                             cout<<"修改成功！\n";
                             break;
                         }
                     }
                     h=h->next;
                 }
             }
            }
            else
            {
                cout<<"您没有权限！\n";
            }

        }
        cout<<"*******************************************************************************\n";
        cout<<"                        请选择功能：\n";
        cout<<"                        0.返回上一层.\n";
        cout<<"                        1.图书信息管理.\n";
        cout<<"                        2.借阅人员信息管理.\n";
        cout<<"                        3.图书借阅.\n";
        cout<<"                        4.图书预约.\n";
        cout<<"                        5.图书延期与还书.\n";
        cout<<"                        6.信息查询,\n";
        cout<<"                        7.信息统计.\n";
        cout<<"                        8.管理员管理.\n";
        cout<<"*******************************************************************************\n";
    }
    }
    }
    if(answer==2)  //非管理员系统
    {
        int wrong1=0;
        string a8,a9;
        Reader *s0,*h0;
        s0=h0=Readerhead;
        cout<<"请输入用户名：";
        while(cin>>a8)
        {
            int right=0;
            while(h0)
            {
                if(h0->ReaderID==a8)
                    right=1;
                h0=h0->next;
            }
            h0=Readerhead;
            if(right>0)
            {
                break;
            }
            else
            {
                cout<<"用户名输入错误！请重新输入：";
            }
        }
        while(s0)
        {
            if(s0->ReaderID==a8)
                break;
            s0=s0->next;
        }
        while(1)
        {
            int quee=Get_Key(s0->ReaderKey);
            if(quee==1)
                break;
            else
            {
                cout<<"密码错误！是否重新输入？<Y/N>";
                char bad;
                cin>>bad;
                if(bad=='N'||bad=='n')
                {
                    wrong1=1;
                    break;
                }
            }
        }
        if(wrong1==0)
        {cout<<endl;
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout<<"                           请选择功能：\n";
        cout<<"                           0.返回上一层\n";
        cout<<"                           1.图书预约\n";
        cout<<"                           2.图书延期\n";
        cout<<"                           3.个人信息修改\n";
        cout<<"                           4.查看个人信息\n";
        cout<<"                           5.借约信息查看\n";
        cout<<"                           6.图书馆藏书查看\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        int ans0;
        while(cin>>ans0)
        {
            if(ans0==0)
            {
                Append_Book("e://BookManger//books.txt",Bookhead);
                Append_Reader("e://BookManger//reader.txt",Readerhead);
                Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
                break;
            }
            if(ans0==1)
            {
                int ans;
                string Name;
                cout<<"︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿\n";
                cout<<"                     请选择动能表：\n";
                cout<<"                     1.按名预约\n";
                cout<<"                     2.按馆藏序号预约\n";
                cout<<"︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿︿\n";
                cin>>ans;
                if(ans==1)
                {
                    Books *s,*p;
                    p=s=Bookhead;
                    int tag;
                    cout<<"请输入书名：";
                    while(cin>>Name)
                    {
                        while((Search_Book(Bookhead,Name))!=1)
                        {
                            cout<<"没有搜索到相关的图书！\n";
                            cout<<"请在此输入书名：";
                            cin>>Name;
                        }
                        cout<<"搜索到的图书列表如下：";
                        for(s=Bookhead;s!=NULL;s=s->next)
                        {
                            if(s->BookName==Name)
                            {
                                s->show();
                            }
                        }
                        cout<<"请输入要预约图书的序号：";
                        cin>>tag;
                        for(p=Bookhead;p->Bookid!=tag;p=p->next)
                        {
                        }
                        if(p->BookFreeNum==0)
                        {
                            break;
                        }
                        else
                        {
                            cout<<"此图书还有在架！无需预约！\n";
                            cout<<"请重新输入书名：";
                        }
                    }
                    if(s0->Permission>=(1+s0->ReservationNumber+s0->LoanNumber))
                    {
                        cout<<"请输入可等待的天数<天数少于20>：";
                        int date_1;
                        cin>>date_1;
                        while(date_1<=0||date_1>20)
                        {
                            cout<<"输入错误！请重新输入：";
                            cin>>date_1;
                        }
                        s0->ReservationNumber+=1;
                        p->BookReservationNum+=1;
                        Loansum+=1;
                        Insert_LoanBook(Loanhead,p,s0,date_1,1,Loansum);
                        cout<<"预约成功，当有空闲的图书请您及时取书！\n";
                    }
                    else
                    {
                        cout<<"已经达到借书限制！无法预约！";
                    }
                }
                if(ans==2)
                {
                    cout<<"是否显示所有图书？<Y/N>";
                    char ch;
                    cin>>ch;
                    if(ch=='Y'||ch=='y')
                    {
                        int temp;
                        Books *p;
                        p=Bookhead;
                        Show_Book(Bookhead);
                        cout<<"请输入预约的序号：";
                        while(cin>>temp)
                        {
                            if(temp>=0&&temp<Booksum)
                                break;
                            else
                            {
                                cout<<"输入错误！请重新输入：";
                            }
                        }
                        Books *h;
                        h=Bookhead;
                        while(h->Bookid!=temp)
                        {
                            h=h->next;
                        }
                        h->show();
                        cout<<"以上信息是否为要预约的图书！？<Y/N>";
                        char ans_0;
                        cin>>ans_0;
                        if(ans_0=='Y'||ans_0=='y')
                        {
                            if(h->BookFreeNum!=0)
                            {
                                cout<<"此图书还有在架！无需预约！\n";
                            }
                            else
                            {
                                if(s0->Permission>=(1+s0->ReservationNumber+s0->LoanNumber))
                                {
                                    cout<<"请输入等待天数<天数少于20>：";
                                    int date_1;
                                    cin>>date_1;
                                    while(date_1<=0||date_1>20)
                                    {
                                        cout<<"输入错误！请重新输入：";
                                        cin>>date_1;
                                    }
                                    s0->ReservationNumber+=1;
                                    p->BookReservationNum+=1;
                                    Loansum+=1;
                                    Insert_LoanBook(Loanhead,p,s0,date_1,1,Loansum);
                                    cout<<"预约成功，当有空闲的图书请您及时取书！\n";
                                }
                            }
                        }
                    }
                }
                Append_Book("e://BookManger//books.txt",Bookhead);
                Append_Reader("e://BookManger//reader.txt",Readerhead);
                Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            }
            if(ans0==2)
            {
                LoanBook *s,*h;
                s=Loanhead;
                cout<<"延期要求用户所剩的借阅时间不得超过10天！\n";
                string tag;
                tag=s0->ReaderID;
                int a=0;
                for(h=Loanhead;h!=NULL;h=h->next)
                {
                    if(h->person->ReaderID==tag&&h->state=='2')
                    {
                        h->show();
                        a++;
                    }
                }
                if(a>0)
                {
                    if(Loanhead->person->ReaderID==tag)
                    {
                        if(Loanhead->Deadline>=11)
                        {
                            cout<<"所剩借阅时间超过延期要求！\n";
                            break;
                        }
                        cout<<"请输入延长的时间(最长不超过20天)：";
                        int a;
                        while(cin>>a)
                        {
                            if(a>0&&a<=20)
                                break;
                            else
                            {
                                cout<<"请重新输入！(最长不超过20天)\n";
                            }
                        }
                        Loanhead->Deadline+=a;
                        cout<<"延期成功！\n";
                    }
                    else
                    {
                        while(s->person->ReaderID!=tag)
                        {
                            s=s->next;
                        }
                        if(s->Deadline>=11)
                        {
                            cout<<"所剩借阅时间超过延期要求！\n";
                            break;
                        }
                        else
                        {
                            cout<<"请输入延长的时间(最长不超过20天)：";
                            int c;
                            while(cin>>c)
                            {
                                if(c>0&&c<=20)
                                    break;
                                else
                                {
                                    cout<<"请重新输入！(最长不超过20天)\n";
                                }
                            }
                            s->Deadline+=c;
                            cout<<"延期成功！\n";
                        }
                    }
                }
                else
                {
                    cout<<"你还没有借阅任何一本书！\n";
                }
                Append_Book("e://BookManger//books.txt",Bookhead);
                Append_Reader("e://BookManger//reader.txt",Readerhead);
                Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            }
            if(ans0==3)
            {
                cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
                cout<<"                     请选择修改信息：\n";
                cout<<"                     1.证件号码\n";
                cout<<"                     2.读者姓名\n";
                cout<<"                     3.读者单位\n";
                cout<<"                     4.修改密码\n";
                cout<<"┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n";
                int tag_1;
                cin>>tag_1;
                if(tag_1==1)
                {
                    if(s0->ReaderID!="0131122589")
                    {cout<<"请输入您的证件号码：";
                    cin>>s0->ReaderID;
                    cout<<"修改成功！\n";}
                    else
                    {
                        cout<<"无法修改！";
                    }
                }
                if(tag_1==2)
                {
                    cout<<"请输入您的姓名：";
                    cin>>s0->ReaderName;
                    cout<<"修改成功！\n";
                }
                if(tag_1==3)
                {
                    cout<<"请输入您的单位:";
                    cin>>s0->ReaderUnit;
                    cout<<"修改成功！\n";
                }
                if(tag_1==4)
                {
                    cout<<"请输入您的旧密码：";
                    string oldkey;
                    while(cin>>oldkey)
                    {
                        if(s0->ReaderKey==oldkey)
                            break;
                        else
                        {
                            cout<<"密码错误！请重新输入：";
                        }
                    }
                    cout<<"请输入您的新密码：";
                    cin>>s0->ReaderKey;
                    cout<<"修改成功！\n";
                }
                Append_Book("e://BookManger//books.txt",Bookhead);
                Append_Reader("e://BookManger//reader.txt",Readerhead);
                Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            }
            if(ans0==4)
            {
                s0->show();
            }
            if(ans0==5)
            {
                LoanBook *s;
                s=Loanhead;
                int wrong=0;
                while(s)
                {
                    if(s->person->ReaderID==s0->ReaderID)
                    {
                        s->show();
                        wrong++;
                    }
                    s=s->next;
                }
                if(wrong==0)
                {
                    cout<<"您还没有借阅和预约信息！\n";
                }
            }
            if(ans0==6)
            {
                int choice2;
                cout<<"_____________________________________________\n";
                cout<<"               1.馆藏书籍显示\n";
                cout<<"               2.按图书类别显示\n";
                cout<<"               3.馆藏图书状态\n";
                cout<<"_____________________________________________\n";
                cin>>choice2;
                if(choice2==1)
                {
                    Show_Book(Bookhead);
                }
                if(choice2==2)
                {
                    int a[100][100];
                    string b[100];
                    Books *h;
                    int i=0,k,j;
                    h=Bookhead;
                    while(h)
                    {
                        k=0;
                        if(h==Bookhead)
                        {
                            b[0]=h->BookChinaID;
                            a[0][h->Bookid]=h->Bookid;
                            i++;
                        }
                        else
                        {
                            for(j=0;j<i;j++)
                            {
                                if(h->BookChinaID==b[j])
                                    {
                                        k=1;
                                        a[j][h->Bookid]=h->Bookid;
                                        break;
                                    }
                            }
                            if(k!=1)
                            {
                                b[i]=h->BookChinaID;
                                a[i][h->Bookid]=h->Bookid;
                                i++;
                            }
                        }
                        h=h->next;
                    }
                    for(int m=0;m<i;m++)
                    {
                        cout<<"中图分类号为"<<b[m]<<"的：\n";
                        for(int n=0;n<100;n++)
                        {
                            for(Books *s=Bookhead;s!=NULL;s=s->next)
                            {
                                if(s->Bookid==a[m][n]&&a[m][n]!=0)
                                {
                                    s->show();
                                }
                            }
                        }
                        cout<<endl<<endl;
                    }
                }
                if(choice2==3)
                {
                    int sum1=0,sum2=0,sum3=0;
                    Books *h;
                    h=Bookhead;
                    while(h)
                    {
                        sum1+=h->BookLoanNum;
                        sum2+=h->BookReservationNum;
                        sum3+=h->BookFreeNum;
                        h=h->next;
                    }
                    cout<<"图书馆中一共有"<<Booksum<<"种图书，";
                    cout<<"在架上"<<sum3<<"本图书"<<endl;
                    cout<<"被借阅"<<sum1<<"本图书，";
                    cout<<"被预约"<<sum2<<"本图书"<<endl;
                }
            }
            cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"                           请选择功能：\n";
            cout<<"                           0.返回上一层\n";
            cout<<"                           1.图书预约\n";
            cout<<"                           2.图书延期\n";
            cout<<"                           3.个人信息修改\n";
            cout<<"                           4.查看个人信息\n";
            cout<<"                           5.借约信息查看\n";
            cout<<"                           6.图书馆藏书查看\n";
            cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }
    }
    }
    if(answer==0)
        break;
    cout<<endl;
    cout<<"              ******************************************\n";
    cout<<"              *            欢迎使用图书管理系统！      *\n";
    cout<<"              *               0.退出系统               *\n";
    cout<<"              *              1.管理员登陆              *\n";
    cout<<"              *             2.普通用户登陆             *\n";
    cout<<"              ******************************************\n";
    }

}
