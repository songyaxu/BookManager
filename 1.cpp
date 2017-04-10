#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
class Reader  //���ߵĻ���
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

class Student:public Reader   //���������ı�������
{public:
    void setReader()
    {
        ReaderClassification='a';
        ReaderManager='n';
        Permission=4;
        cout<<"��������ߵ�֤�����룺";
        cin>>ReaderID;
        ReaderKey=ReaderID;
        cout<<"��������ߵ�������";
        cin>>ReaderName;
        cout<<"��������ߵĵ�λ��";
        cin>>ReaderUnit;
        LoanNumber=0;
        ReservationNumber=0;
        cout<<endl;
    }
    void show()    //��ʾ������Ϣ
    {
        cout<<"������Ϣ-��"<<Readerid<<".";
        cout<<"֤�����룺"<<ReaderID<<" ����������"<<ReaderName<<" ���ߵ�λ��";
        cout<<ReaderUnit<<" �������ͣ�"<<"������ "<<"����������"<<LoanNumber;
        cout<<" ԤԼ������"<<ReservationNumber<<" ������������"<<Permission<<endl;
    }
};

class GraduateStudent:public Reader  //�����������о�����
{public:
    void setReader()
    {
        ReaderClassification='b';
        Permission=6;
        ReaderManager='n';
        cout<<"��������ߵ�֤�����룺";
        cin>>ReaderID;
        ReaderKey=ReaderID;
        cout<<"��������ߵ�������";
        cin>>ReaderName;
        cout<<"��������ߵĵ�λ��";
        cin>>ReaderUnit;
        LoanNumber=0;
        ReservationNumber=0;
        cout<<endl;
    }
    void show()  //��ʾ������Ϣ
    {
        cout<<"������Ϣ-��"<<Readerid<<".";
        cout<<"֤�����룺"<<ReaderID<<" ����������"<<ReaderName<<" ���ߵ�λ��";
        cout<<ReaderUnit<<" �������ͣ�"<<"�о��� "<<"����������"<<LoanNumber;
        cout<<" ԤԼ������"<<ReservationNumber<<" ������������"<<Permission<<endl;
    }
};

class Teacher: public Reader  //���������Ľ�ʦ��
{public:
    void setReader()
    {
        ReaderClassification='c';
        Permission=10;
        ReaderManager='n';
        cout<<"��������ߵ�֤�����룺";
        cin>>ReaderID;
        ReaderKey=ReaderID;
        cout<<"��������ߵ�������";
        cin>>ReaderName;
        cout<<"��������ߵĵ�λ��";
        cin>>ReaderUnit;
        LoanNumber=0;
        ReservationNumber=0;
        cout<<endl;
    }
    void show()  //��ʾ������Ϣ
    {
        cout<<"������Ϣ-��"<<Readerid<<".";
        cout<<"֤�����룺"<<ReaderID<<" ����������"<<ReaderName<<" ���ߵ�λ��";
        cout<<ReaderUnit<<" �������ͣ�"<<"��ʦ "<<"����������"<<LoanNumber;
        cout<<" ԤԼ������"<<ReservationNumber<<" ������������"<<Permission<<endl;
    }
};

class Books  //ͼ����
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
        cout<<"������ͼ��ı�ţ�";
        cin>>BookID;
        cout<<"������ͼ���������";
        cin>>BookFreeNum;
        BookLoanNum=0;
        BookReservationNum=0;
        cout<<"������ͼ�����ͼ����ţ�";
        cin>>BookChinaID;
        cout<<"������ͼ�����ƣ�";
        cin>>BookName;
        cout<<"������ͼ������ߣ� ";
        cin>>BookAuthor;
        cout<<"������ͼ��ĳ����磺 ";
        cin>>BookPress;
        cout<<"������ͼ��ĳ������ڣ�";
        cin>>BookDate;
        cout<<"������ͼ���IBSN�� ";
        cin>>BookISBN;
        cout<<"������ͼ��İ�Σ� ";
        cin>>BookVersion;
        cout<<"������ͼ��Ķ��ۣ� ";
        cin>>BookPirce;
        cout<<endl;
    }
    void show()
    {
        cout<<Bookid<<".";
        cout<<"ͼ����: "<<BookID;
        cout<<" ��ͼ�����: "<<BookChinaID;
        cout<<" ����:"<<BookName;
        cout<<" ����:"<<BookAuthor;
        cout<<" ������:"<<BookPress;
        cout<<" ��������:"<<BookDate;
        cout<<" ISBN:"<<BookISBN;
        cout<<" ���:"<<BookVersion;
        cout<<" ����:"<<BookPirce;
        cout<<" ͼ���״̬:";
        cout<<" �ڼ��ϣ� "<<BookFreeNum;
        cout<<" �����У� "<<BookLoanNum;
        cout<<" ��ԤԼ�� "<<BookReservationNum;
        cout<<endl;
    }
};

void Show_Book(Books *Bookhead)   //��ʾͼ����Ϣ
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

void Insert_Book(Books *&Bookhead,int sum)  //�����߲�������
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

void Modify_Book(Books *&Bookhead,int sum)  //�޸�ͼ����Ϣ
{
    int temp;
    cout<<"�������޸�ͼ��ķ�ʽ��";
    cout<<"     1.���ݲ�����޸�";
    cout<<"     2.��ͼ�����޸�";
    cin>>temp;
    if(temp==1)
    {
        char tag_1;
        cout<<"�Ƿ���ʾ�ݲ�ͼ�飿<Y/N>";
        cin>>tag_1;
        if(tag_1=='Y'||tag_1=='y')
            Show_Book(Bookhead);
        int num,tag;
        Books *p;
        p=Bookhead;
        cout<<"��������Ҫ�޸ĵ���ţ�";
        cin>>num;
        while(num>sum||num<=0)
        {
            cout<<"�������������������ţ�";
            cin>>num;
        }
        cout<<"��������������������������������������������������������\n";
        cout<<"                     ��ѡ���޸���Ϣ��\n";
        cout<<"                     1.ͼ����\n";
        cout<<"                     2.��ͼ�����\n";
        cout<<"                     3.����\n";
        cout<<"                     4.����\n";
        cout<<"                     5.������\n";
        cout<<"                     6.��������\n";
        cout<<"                     7.ISBN\n";
        cout<<"                     8.���\n";
        cout<<"                     9.����\n";
        cout<<"                     10.ͼ������\n";
        cout<<"��������������������������������������������������������\n";
        while(p->Bookid!=num)
        {
            p=p->next;
        }
        cout<<"��ѡ���޸ĵ����ݣ�";
        cin>>tag;
        if(tag==1)
        {
            cout<<"�������µ�ͼ���ţ�";
            cin>>p->BookID;
        }
        if(tag==2)
        {
            cout<<"�������µ���ͼ����ţ�";
            cin>>p->BookChinaID;
        }
        if(tag==3)
        {
            cout<<"������ͼ��������";
            cin>>p->BookName;
        }
        if(tag==4)
        {
            cout<<"������ͼ������ߣ�";
            cin>>p->BookAuthor;
        }
        if(tag==5)
        {
            cout<<"������ͼ��ĳ����磺";
            cin>>p->BookPress;
        }
        if(tag==6)
        {
            cout<<"������ͼ��ĳ������ڣ�";
            cin>>p->BookDate;
        }
        if(tag==7)
        {
            cout<<"������ͼ���ISBN��";
            cin>>p->BookISBN;
        }
        if(tag==8)
        {
            cout<<"������ͼ��İ�Σ�";
            cin>>p->BookVersion;
        }
        if(tag==9)
        {
            cout<<"������ͼ��Ķ��ۣ�";
            cin>>p->BookPirce;
        }
        if(tag==10)
        {
            if(p->BookReservationNum==0&&p->BookLoanNum==0)
            {
                cout<<"������ͼ��������";
                cin>>p->BookFreeNum;
            }
            else
            {
                cout<<"�н��Ļ���ԤԼ��ͼ���޷��޸ģ�\n";
            }
        }
    }
    if(temp==2)
    {
        Books *h;
        h=Bookhead;
        int a=0;
        cout<<"������Ҫ�޸ĵ�ͼ���ţ�";
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
                cout<<"û�����ͼ�飬����������ͼ���ţ�";
            }
        }
        cout<<"��������ͼ���Ƿ�ΪҪ�޸ĵ�ͼ�飿<Y/N>";
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
            cout<<"��������������������������������������������������������\n";
            cout<<"                     ��ѡ���޸���Ϣ��\n";
            cout<<"                     1.ͼ����\n";
            cout<<"                     2.��ͼ�����\n";
            cout<<"                     3.����\n";
            cout<<"                     4.����\n";
            cout<<"                     5.������\n";
            cout<<"                     6.��������\n";
            cout<<"                     7.ISBN\n";
            cout<<"                     8.���\n";
            cout<<"                     9.����\n";
            cout<<"                     10.ͼ������\n";
            cout<<"��������������������������������������������������������\n";
            int tag;
            cout<<"��ѡ���޸ĵ����ݣ�";
            cin>>tag;
            if(tag==1)
            {
                cout<<"�������µ�ͼ���ţ�";
                cin>>p->BookID;
            }
            if(tag==2)
            {
                cout<<"�������µ���ͼ����ţ�";
                cin>>p->BookChinaID;
            }
            if(tag==3)
            {
                cout<<"������ͼ��������";
                cin>>p->BookName;
            }
            if(tag==4)
            {
                cout<<"������ͼ������ߣ�";
                cin>>p->BookAuthor;
            }
            if(tag==5)
            {
                cout<<"������ͼ��ĳ����磺";
                cin>>p->BookPress;
            }
            if(tag==6)
            {
                cout<<"������ͼ��ĳ������ڣ�";
                cin>>p->BookDate;
            }
            if(tag==7)
            {
                cout<<"������ͼ���ISBN��";
                cin>>p->BookISBN;
            }
            if(tag==8)
            {
                cout<<"������ͼ��İ�Σ�";
                cin>>p->BookVersion;
            }
            if(tag==9)
            {
                cout<<"������ͼ��Ķ���";
                cin>>p->BookPirce;
            }
            if(tag==10)
            {
                if(p->BookReservationNum==0&&p->BookLoanNum==0)
                {
                    cout<<"������ͼ��������";
                    cin>>p->BookFreeNum;
                }
                else
                {
                    cout<<"�н��Ļ���ԤԼ��ͼ���޷��޸ģ�\n";
                }
            }
        }
        else
            return;
    }

}

int Del_Book(Books *&Bookhead,int sum)  //ɾ��ͼ��
{
    Books *p,*h,*q;
    q=h=p=Bookhead;
    cout<<"����������������������������������������������������������������������������������������\n";
    cout<<"               ��ѡ���ܱ�\n";
    cout<<"               1.���ݲ����ɾ��\n";
    cout<<"               2.��ͼ����ɾ��\n";
    cout<<"����������������������������������������������������������������������������������������\n";
    int ans;
    cin>>ans;
    if(ans==1)
    {
        char tag;
        cout<<"�Ƿ���ʾ�ݲ�ͼ��<Y/N>:";
        cin>>tag;
        if(tag=='Y'||tag=='y')
        {
            Show_Book(Bookhead);
        }
        cout<<"������ɾ��ͼ������:";
        int num;
        cin>>num;
        while(num<=0||num>sum)
        {
            cout<<"����������������룺";
            cin>>num;
        }
        if(Bookhead->Bookid==num)
        {
            char ans_1;
            Bookhead->show();
            cout<<"�Ƿ�ɾ����ͼ�飿<Y/N>:";
            cin>>ans_1;
            if(ans_1=='Y'||ans_1=='y')
            {
                if(Bookhead->BookLoanNum==0&&Bookhead->BookReservationNum==0)
                {
                    Bookhead=Bookhead->next;
                    cout<<"ɾ���ɹ���\n";
                    return 1;
                }
                else
                {
                    cout<<"ͼ�鱻�����л���ԤԼ���޷�ɾ����\n";
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
        cout<<"�Ƿ�ɾ����ͼ�飿<Y/N>:";
        char ans_1;
        cin>>ans_1;
        if(ans_1=='Y'||ans_1=='y')
        {
            if(p->BookLoanNum==0&&p->BookReservationNum==0)
            {
                q->next=p->next;
                cout<<"ɾ���ɹ���\n";
                return 1;
            }
            else
            {
                cout<<"ͼ�鱻�����л���ԤԼ���޷�ɾ����\n";
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
        cout<<"������ͼ���ţ�";
        cin>>info;
        while(p)
        {
            if(p->BookID==info)
                a1=1;
            p=p->next;
        }
        if(a1==0)
            {
                cout<<"û�����������ͼ�飡\n";
                return 0;
            }
        if(a1==1)
        {
            cout<<"����������Ϣ���£�\n";
            h=Bookhead;
            while(h)
            {
                if(h->BookID==info)
                    h->show();
                h=h->next;
            }
        }
        cout<<"��ѡ��ɾ����ͼ����ţ�";
        int a;
        cin>>a;
        char ans_1;
        if(a==1)
        {
            Bookhead->show();
            cout<<"�Ƿ�ɾ����ͼ�飿<Y/N>:";
            cin>>ans_1;
            if(ans_1=='Y'||ans_1=='y')
            {
                if(Bookhead->BookLoanNum==0&&Bookhead->BookReservationNum==0)
                {
                    Bookhead=Bookhead->next;
                    cout<<"ɾ���ɹ���\n";
                    return 1;
                }
                else
                {
                    cout<<"ͼ�鱻�����л���ԤԼ���޷�ɾ����\n";
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
        cout<<"�Ƿ�ɾ����ͼ�飿<Y/N>:";
        char ans_2;
        cin>>ans_2;
        if(ans_2=='Y'||ans_2=='y')
        {
            if(p->BookLoanNum==0&&p->BookReservationNum==0)
            {
                q->next=p->next;
                cout<<"ɾ���ɹ���\n";
                return 1;
            }
            else
            {
                cout<<"ͼ�鱻�����л���ԤԼ���޷�ɾ����\n";
                return 0;
            }
        }
        else
            return 0;
    }
    return 0;
}

void Show_Reader(Reader *Readerhead,int sum) //��ʾ������Ϣ
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

void Insert_Reader(Reader *&Readerhead,int sum)  //�����߲���������
{
    Reader *p,*s;
    char ch;
    cout<<"��������Ҫ����Ķ�������(a:������,b:�о���,c:��ʦ)��";
    cin>>ch;
    while(ch!='a'&&ch!='b'&&ch!='c')
        {
            cout<<"����������������룡";
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

int Search_Reader(Reader *Readerhead,string ID)  //Ѱ����Ӧ֤������Ķ���
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

int Search_Ma_Reader(Reader *Readerhead,string ID) //Ѱ����Ӧ֤������Ĺ���Աר�ú���
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

void Modify_Reader(Reader *&Readerhead,int sum) //�޸Ķ�����Ϣ����
{
    int temp1;
    cout<<"�������޸Ķ��ߵķ�ʽ��\n";
    cout<<"         1.����������޸�\n";
    cout<<"         2.��֤�������޸�\n";
    cin>>temp1;
    if(temp1==1)
    {
        char ch;
        int tag,tag_1;
        Reader *s;
        s=Readerhead;
        cout<<"�Ƿ���ʾ�����б�<Y/N>";
        cin>>ch;
        if(ch=='Y'||ch=='y')
            Show_Reader(Readerhead,sum);
        cout<<"�������޸ĵ���ţ�";
        cin>>tag;
        while(tag<=0||tag>sum)
        {
            cout<<"����������������룡";
            cin>>tag;
        }
        cout<<"��������������������������������������������������������\n";
        cout<<"                     ��ѡ���޸���Ϣ��\n";
        cout<<"                     1.֤������\n";
        cout<<"                     2.��������\n";
        cout<<"                     3.���ߵ�λ\n";
        cout<<"��������������������������������������������������������\n";
        while(s->Readerid!=tag)
        {
            s=s->next;
        }
        cin>>tag_1;
        if(tag_1==1)
        {
            if(s->ReaderID!="0131122589")
            {cout<<"��������ߵ�֤�����룺";
            cin>>s->ReaderID;
            cout<<"�޸ĳɹ���\n";}
            else
            {
                cout<<"�޷��޸Ĵ��û���\n";
            }
        }
        if(tag_1==2)
        {
            cout<<"��������ߵ�������";
            cin>>s->ReaderName;
            cout<<"�޸ĳɹ���\n";
        }
        if(tag_1==3)
        {
            cout<<"��������ߵĵ�λ:";
            cin>>s->ReaderUnit;
            cout<<"�޸ĳɹ���\n";
        }
    }
    if(temp1==2)
    {
        Reader *h,*q,*s;
        s=q=h=Readerhead;
        cout<<"�������޸Ķ��ߵ�֤�����룺";
        string data;
        cin>>data;
        while((Search_Reader(Readerhead,data))!=1)
        {
                cout<<"�Բ����Ѷ಻�������Ϣ��\n";
                cout<<"��ȷ������֤��������ȷ������������֤�����룺";
                cin>>data;
        }
        cout<<"������Ϣ�Ƿ�ΪҪ�޸ĵĶ�����Ϣ��<Y/N>";
        char tag;
        cin>>tag;
        if(tag=='Y'||tag=='y')
        {
            while(s->ReaderID!=data)
            {
                s=s->next;
            }
            cout<<"��������������������������������������������������������\n";
            cout<<"                     ��ѡ���޸���Ϣ��\n";
            cout<<"                     1.֤������\n";
            cout<<"                     2.��������\n";
            cout<<"                     3.���ߵ�λ\n";
            cout<<"��������������������������������������������������������\n";
            int tag_1;
            cin>>tag_1;
            if(tag_1==1)
            {
                if(s->ReaderID=="0131122589")
                {cout<<"��������ߵ�֤�����룺";
                cin>>s->ReaderID;
                cout<<"�޸ĳɹ���\n";
                }
                cout<<"�޷��޸Ĵ��û���\n";
            }
            if(tag_1==2)
            {
                cout<<"��������ߵ�������";
                cin>>s->ReaderName;
                cout<<"�޸ĳɹ���\n";
            }
            if(tag_1==3)
            {
                cout<<"��������ߵĵ�λ:";
                cin>>s->ReaderUnit;
                cout<<"�޸ĳɹ���\n";
            }
        }
        else
            return;

    }
}

int Search_Book(Books *Bookhead,string Name)  //Ѱ����Ӧ���ֵ�ͼ�麯��
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

struct LoanBook  //����ԤԼ����
{
    int id;
    Books *book;
    Reader *person;
    char state;
    int Deadline;
    LoanBook *next;
    void show()
    {
        cout<<id<<"."<<"  ������"<<book->BookName<<" ����ʣ��ʱ�䣺 "<<Deadline<<"�� ͼ���ţ�"<<book->BookID<<" ��ͼ����ţ�"<<book->BookChinaID;
        cout<<" ͼ��״̬��";
        if(state=='2')
        {
            cout<<" ������ ";
            cout<<"�����ˣ� "<<person->ReaderName<<" ������֤���ţ� "<<person->ReaderID;
            cout<<" ��������� ";
        }
        if(state=='1')
        {
            cout<<" ��ԤԼ ";
            cout<<"ԤԼ�ˣ� "<<person->ReaderName<<" ԤԼ��֤���ţ� "<<person->ReaderID;
            cout<<" ԤԼ����� ";
        }
        if(person->ReaderClassification=='a')
        {
            cout<<"������ ";
        }
        if(person->ReaderClassification=='b')
        {
            cout<<"�о��� ";
        }
        if(person->ReaderClassification=='c')
        {
            cout<<"��ʦ ";
        }
        cout<<" ���ߵ�λ��"<<person->ReaderUnit<<endl;

    }
};

void Insert_LoanBook(LoanBook *&Loanhead,Books *p,Reader *q,int date,int x,int y) //�������ԤԼ����
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
    if(Loanhead==NULL)   //ͷΪ��ʱ
    {
        Loanhead=s;
        Loanhead->next=NULL;
    }
    else      //ͷ��Ϊ��ʱ
    {
        while(w->next!=NULL)
        {
            w=w->next;
        }
        w->next=s;
        s->next=NULL;
    }
}

void Show_LoanBook(LoanBook *&Loanhead)  //��ʾ����ԤԼ��Ϣ
{
    int num=1;
    LoanBook *h;
    h=Loanhead;
    if(!h)
        cout<<"û�н���ԤԼ��Ϣ��\n";
    while(h)
    {
        h->id=num;
        h->show();
        h=h->next;
        num++;
    }
}

int Search_LoanBook(LoanBook *Loanhead,string ad)  //���ҽ�����Ա����
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

int Distinguish(string s)  //ʶ����������
{
   if(s=="������")
     return 1;
   else
    if(s=="�о���")
     return 2;
   else
   if(s=="��ʦ")
     return 3;
   else
   return 4;
}

void Append_Reader(const char *fileName,Reader *&Readerhead)  //�����߱������ݵ��ļ�
{
    ofstream outstuf(fileName,ios::out);
    if(!outstuf)
    {
        cout<<"��ʧ�ܣ�\n";
        return;
    }
    Reader *s;
    s=Readerhead;
    while(s)
    {outstuf<<s->Readerid<<'.';
    outstuf<<"֤�����룺 "<<s->ReaderID<<" ���������� "<<s->ReaderName;
    outstuf<<" ����Ȩ��: ";
    if(s->ReaderManager=='y')
        outstuf<<"����Ա ";
    if(s->ReaderManager=='n')
        outstuf<<"�ǹ���Ա ";
    outstuf<<" ���룺 "<<s->ReaderKey;
    outstuf<<" ���ߵ�λ�� ";
    outstuf<<s->ReaderUnit<<" �������ͣ� ";
    if(s->ReaderClassification=='a')
        outstuf<<"������ ";
    else
    if(s->ReaderClassification=='b')
        outstuf<<"�о��� ";
    else
        outstuf<<"��ʦ ";
    outstuf<<"���������� "<<s->LoanNumber;
    outstuf<<" ԤԼ������ "<<s->ReservationNumber<<" ������������ "<<s->Permission<<'\n';
    s=s->next;
    }
    outstuf.close();
    return;
}

void Append_Book(const char *fileName,Books *&Bookhead)  //��ͼ�鱣�����ݵ��ļ�
{
    ofstream outstuf(fileName,ios::out);
    if(!outstuf)
    {
        cout<<"��ʧ�ܣ�\n";
        return;
    }
    Books *s;
    s=Bookhead;
    while(s)
    {outstuf<<s->Bookid<<".";
    outstuf<<"ͼ����: "<<s->BookID;
    outstuf<<" ��ͼ�����: "<<s->BookChinaID;
    outstuf<<" ����: "<<s->BookName;
    outstuf<<" ����: "<<s->BookAuthor;
    outstuf<<" ������: "<<s->BookPress;
    outstuf<<" ��������: "<<s->BookDate;
    outstuf<<" ISBN: "<<s->BookISBN;
    outstuf<<" ���: "<<s->BookVersion;
    outstuf<<" ����: "<<s->BookPirce;
    outstuf<<" ͼ���״̬:";
    outstuf<<"�ڼ��ϣ� "<<s->BookFreeNum;
    outstuf<<" �����У� "<<s->BookLoanNum;
    outstuf<<" ��ԤԼ�� "<<s->BookReservationNum;
    outstuf<<'\n';
    s=s->next;
    }
    outstuf.close();
    return;
}

void Append_LoanBook(const char *fileName,LoanBook *&Loanhead)  //��ͼ�����ԤԼ�������ݵ��ļ�
{
    ofstream outstuf(fileName,ios::out);
    if(!outstuf)
    {
        cout<<"��ʧ�ܣ�\n";
        return;
    }
    LoanBook *s;
    s=Loanhead;
    while(s)
    {outstuf<<s->id<<".";
    outstuf<<"����:"<<s->book->BookName;
    outstuf<<"ʣ������: "<<s->Deadline;
    outstuf<<" ͼ����: "<<s->book->BookID;
    outstuf<<" ��ͼ�����:"<<s->book->BookChinaID;
    outstuf<<"ͼ��״̬: ";
    if(s->state=='1')
    {
        outstuf<<" ��ԤԼ ";
        outstuf<<"ԤԼ�ˣ�";
        outstuf<<s->person->ReaderName;
        outstuf<<"ԤԼ��֤���ţ� ";
        outstuf<<s->person->ReaderID;
        outstuf<<" ԤԼ�����:";
        if(s->person->ReaderClassification=='a')
            outstuf<<"������";
        if(s->person->ReaderClassification=='b')
            outstuf<<"�о���";
        if(s->person->ReaderClassification=='c')
            outstuf<<"��ʦ";
    }
    if(s->state=='2')
    {
        outstuf<<"������ ";
        outstuf<<"�����ˣ�";
        outstuf<<s->person->ReaderName;
        outstuf<<"������֤���ţ� ";
        outstuf<<s->person->ReaderID;
        outstuf<<" �����������";
        if(s->person->ReaderClassification=='a')
            outstuf<<"������";
        if(s->person->ReaderClassification=='b')
            outstuf<<"�о���";
        if(s->person->ReaderClassification=='c')
            outstuf<<"��ʦ";
    }
    outstuf<<"���ߵ�λ��"<<s->person->ReaderUnit;
    outstuf<<'\n';
    s=s->next;
    }
    outstuf.close();
    return;
}

void Insert_Re_Reader(Reader *&Readerhead,Reader *t) //���ݻָ�ʹ�õĶ��߲���������
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

int Recovery_Reader(const char *fileName,Reader *& Readerhead)  //���ߵ����ݻָ�
{
    ifstream instuf(fileName,ios::in);
    instuf.seekg(0,ios::beg);
    if(!instuf)
    {
        cout<<"��ʧ�ܣ�\n";
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
            if(x5=="�ǹ���Ա")
            t->ReaderManager='n';
            if(x5=="����Ա")
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
            if(x5=="�ǹ���Ա")
            t->ReaderManager='n';
            if(x5=="����Ա")
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
            if(x5=="�ǹ���Ա")
            t->ReaderManager='n';
            if(x5=="����Ա")
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

void Insert_Re_Book(Books *&Bookhead,Books *t)  //���ݻָ�ʹ�õ�ͼ����뺯��
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

int Recovery_Book(const char *fileName,Books *& Bookhead)  //ͼ������ݻָ�
{
    ifstream instuf(fileName,ios::in);
    instuf.seekg(0,ios::beg);
    if(!instuf)
    {
        cout<<"��ʧ�ܣ�\n";
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

int Del_Reader(Reader *&Readerhead,int sum)   //ɾ������
{
    Reader *q,*p,*h;
    q=p=h=Readerhead;
    cout<<"����������������������������������������������������������������������������������������\n";
    cout<<"               ��ѡ���ܱ�\n";
    cout<<"               1.�����ɾ��\n";
    cout<<"               2.������֤������ɾ��\n";
    cout<<"����������������������������������������������������������������������������������������\n";
    int ans;
    cin>>ans;
    if(ans==1)
    {
        cout<<"�Ƿ���ʾ���ж��ߣ�<Y/N>";
        char ans_1;
        cin>>ans_1;
        if(ans_1=='y'||ans_1=='Y')
        {
            Show_Reader(Readerhead,sum);
        }
        cout<<"�����������ţ�";
        int tag;
        while(cin>>tag)
        {
            for(q=Readerhead;q->Readerid!=tag;q=q->next)
            {
            }
            q->show();
            cout<<"��ʾ�Ķ����Ƿ�ΪҪɾ���Ķ��ߣ�<Y/N>";
            char tag_1;
            cin>>tag_1;
            if(tag_1=='Y'||tag_1=='y')
            {
                if(tag==1)
                {
                      cout<<"�޷�ɾ����\n";
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
                        cout<<"ɾ���ɹ���\n";
                        return 1;
                    }
                    else
                    {
                        cout<<"�˶����н��ĵ������ԤԼ���飬�޷�ɾ����\n";
                        return 0;
                    }
              }
           }
           else
           {
               cout<<"������������ţ�";
           }
        }
    }
    if(ans==2)
    {
        q=p=h=Readerhead;
        cout<<"���������֤�����룺";
        string temp;
        cin>>temp;
        while((Search_Reader(Readerhead,temp))!=1)
        {
                cout<<"�Բ����Ѷ಻�������Ϣ��\n";
                cout<<"��ȷ������֤��������ȷ������������֤�����룺";
                cin>>temp;
        }
        cout<<"���϶�����Ϣ�Ƿ�ΪҪɾ���Ķ�����Ϣ<Y/N>";
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

                cout<<"�޷�ɾ����\n";
                return 0;
            }
            if(q->LoanNumber==0&&q->ReservationNumber==0)
            {
                p->next=q->next;
                q=NULL;
                cout<<"ɾ���ɹ���\n";
                return 1;
            }
            else
            {
                cout<<"�˶����н��ĵ������ԤԼ���飬�޷�ɾ����\n";
                return 0;
            }
        }
        else
            return 0;
    }
    return 0;
}

int Recovery_LoanBook(const char* fileName,LoanBook*& Loanhead,Books *Bookhead,Reader *Readerhead) //ͼ��������ݻָ�
{
    ifstream instuf(fileName,ios::in);
    instuf.seekg(0,ios::beg);
    if(!instuf)
    {
        cout<<"��ʧ�ܣ�\n";
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
        if(x2=="������")
        b=2;
        if(x2=="��ԤԼ")
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

int Get_Key(string key)  //�������β���
{
    int i;
    char ch;
    char str[20];//�ñ������������
    i=0;
    system("cls");
    cout<<"���������룺";
    ch=getch() ;
    while(ch!=13)
    {
        if(ch==8&&i>0)//�˸��ASII��
        {
            i--;
            str[i]='\0';
            system("cls"); //������������
            cout<<"���������룺";
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

int Fuzzy_search(Books *Bookhead,string s,string a[])  //ģ������ͼ��
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
    Booksum+=Recovery_Book("e://BookManger//books.txt",Bookhead);  //ͼ�����ݻָ�
    Readersum+=Recovery_Reader("e://BookManger//reader.txt",Readerhead);  //�������ݻָ�
    Loansum+=Recovery_LoanBook("e://BookManger//loanbook.txt",Loanhead,Bookhead,Readerhead);//�������ݻָ�
    cout<<"\n";
    cout<<"              ******************************************\n";
    cout<<"              *            ��ӭʹ��ͼ�����ϵͳ��      *\n";
    cout<<"              *               0.�˳�ϵͳ               *\n";
    cout<<"              *              1.����Ա��½              *\n";
    cout<<"              *             2.��ͨ�û���½             *\n";
    cout<<"              ******************************************\n";
    int answer;
    string chl,chl1;
    while(cin>>answer)
    {
            if(answer==1)  //����Աϵͳ
            {
            int wrong1=0;
            Reader *h10;
            h10=Readerhead;
            cout<<"�������û�����";
            cin>>chl;
            while((Search_Ma_Reader(Readerhead,chl))!=1)
            {
                cout<<"��������û�����Ч��\n";
                cout<<"���������룺";
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
                     cout<<"��������Ƿ��������룿<Y/N>";
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
    cout<<"                        ��ѡ���ܣ�\n";
    cout<<"                        0.������һ��.\n";
    cout<<"                        1.ͼ����Ϣ����.\n";
    cout<<"                        2.������Ա��Ϣ����.\n";
    cout<<"                        3.ͼ�����.\n";
    cout<<"                        4.ͼ��ԤԼ.\n";
    cout<<"                        5.ͼ�������뻹��.\n";
    cout<<"                        6.��Ϣ��ѯ.\n";
    cout<<"                        7.��Ϣͳ��.\n";
    cout<<"                        8.�������Ա.\n";
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
            cout<<"������������������������������������������������������������������������������\n";
            cout<<"���������������������� ��ѡ���ܣ�\n";
            cout<<"                       0.������һ��.\n";
            cout<<"                       1.¼��ͼ��.\n";
            cout<<"                       2.�޸�ͼ����Ϣ.\n";
            cout<<"                       3.ɾ��ͼ��.\n";
            cout<<"                       4.�鿴����ͼ��.\n";
            cout<<"������������������������������������������������������������������������������\n";
            while(cin>>choice1)
            {
                if(choice1==0)
                break;
                if(choice1==1)
                {
                    int choice2;
                    cout<<"�ߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣ�\n";
                    cout<<"                    ��ѡ���ܣ�\n";
                    cout<<"                    1.������¼��\n";
                    cout<<"                    2.����¼��\n";
                    cout<<"�ߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣ�\n";
                    cin>>choice2;
                    if(choice2==1)
                    {
                        int num;
                        cout<<"������ͼ���������\n";
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
                cout<<"������������������������������������������������������������������������������\n";
                cout<<"���������������������� ��ѡ���ܣ�\n";
                cout<<"                       0.������һ��.\n";
                cout<<"                       1.¼��ͼ��.\n";
                cout<<"                       2.�޸�ͼ����Ϣ.\n";
                cout<<"                       3.ɾ��ͼ��.\n";
                cout<<"                       4.�鿴����ͼ��.\n";
                cout<<"������������������������������������������������������������������������������\n";
            }
        }
        if(choice==2)
        {
            int choice1;
            cout<<"������������������������������������������������������������������������������\n";
            cout<<"���������������������� ��ѡ���ܣ�\n";
            cout<<"                       0.������һ��.\n";
            cout<<"                       1.¼�����.\n";
            cout<<"                       2.�޸Ķ�����Ϣ.\n";
            cout<<"                       3.ɾ��������Ϣ.\n";
            cout<<"                       4.�鿴���ж���.\n";
            cout<<"������������������������������������������������������������������������������\n";
            while(cin>>choice1)
            {
                if(choice1==0)
                break;
                if(choice1==1)
                {
                    int choice2;
                    cout<<"�ߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣ�\n";
                    cout<<"                    ��ѡ���ܣ�\n";
                    cout<<"                    1.������¼��\n";
                    cout<<"                    2.����¼��\n";
                    cout<<"�ߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣ�\n";
                    cin>>choice2;
                    if(choice2==1)
                    {
                        int num;
                        cout<<"��������ߵ�������\n";
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
                cout<<"������������������������������������������������������������������������������\n";
                cout<<"���������������������� ��ѡ���ܣ�\n";
                cout<<"                       0.������һ��.\n";
                cout<<"                       1.¼�����.\n";
                cout<<"                       2.�޸Ķ�����Ϣ.\n";
                cout<<"                       3.ɾ��������Ϣ.\n";
                cout<<"                       4.�鿴���ж���.\n";
                cout<<"������������������������������������������������������������������������������\n";
            }
        }
        if(choice==3)
        {
            int ans;
            char a1;
            string Name;
            cout<<"�Ƿ����ԤԼ��ͼ�飿<Y/N>";
            cin>>a1;
            if(a1=='Y'||a1=='y')
            {
                string a0;
                LoanBook *b1,*b2,*b4;
                int b=0,f=0,e=0;
                b4=b1=b2=Loanhead;
                cout<<"����������֤�����룺";
                cin>>a0;
                while((Search_LoanBook(Loanhead,a0))!=1)
                {
                    cout<<"�Բ����Ѳ��������Ϣ��\n";
                    cout<<"��ȷ������֤��������ȷ����������֤�����룺";
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
                    cout<<"��������Ҫѡ����ĵ�ͼ����ţ�";
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
                    {cout<<"��������ĵ�������<��������30>";
                    int date;
                    cin>>date;
                    while(date<=0||date>30)
                    {
                        cout<<"���������룡";
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
                    cout<<"����ɹ���\n";
                }
                else
                {
                    cout<<"��ͼ�黹û�п��еģ��������ĵȴ���\n";
                }
                 }
                else
                if(b>0)
                {
                    cout<<"1��ͼ�黹û�п��еģ��������ĵȴ���\n";
                }
                else
                {
                    cout<<"��û��ԤԼ!\n";
                }
            }
            else
            {
                cout<<"��������������������������\n";
                cout<<"                     ��ѡ���ܱ�\n";
                cout<<"                     1.��������\n";
                cout<<"                     2.��������\n";
                cout<<"��������������������������\n";
                cin>>ans;
                if(ans==1)
                {
                    Books *s,*p;
                    p=s=Bookhead;
                    int tag;
                    int tag_1=1;
                    cout<<"���������ȫ����";
                    while(cin>>Name)
                    {
                         while((Search_Book(Bookhead,Name))!=1)
                        {
                            cout<<"û����������ص�ͼ�飡\n";
                            cout<<"���ڴ�����������";
                            cin>>Name;
                        }
                        cout<<"��������ͼ���б����£�\n";
                        for(s=Bookhead;s!=NULL;s=s->next)
                        {
                            if(s->BookName==Name)
                            {
                                 s->show();
                            }
                        }
                        cout<<"������Ҫ����ͼ�����ţ�";
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
                           cout<<"��ͼ�鲻�ܱ����ģ���Ϊû���㹻��ͼ�飡\n";
                           cout<<"����������������";
                       }
                   }
                   Reader *q;
                   q=Readerhead;
                   string ReaderID1;
                   char ans_1,ans_2;
                   cout<<"����������˵�֤�����룺";
                   while(cin>>ReaderID1)
                   {
                        if((Search_Reader(Readerhead,ReaderID1))==1)
                        {
                             cout<<"�������Ľ������Ƿ�Ϊ���ı��ˣ�<Y/N>";
                             cin>>ans_1;
                             if(ans_1=='Y'||ans_1=='y')
                             {
                                  break;
                             }
                        }
                        else
                        {
                            cout<<"��������½������Ƿ�����µĽ����˲�������Ϣ��<Y/N>";
                            cin>>ans_2;
                            if(ans_2=='Y'||ans_2=='y')
                            {
                                Insert_Reader(Readerhead,Readersum);
                                break;
                            }
                            else
                            cout<<"֤����������������������룺";

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
                    cout<<"�������������<��������30>��";
                    int date_1;
                    cin>>date_1;
                    while(date_1<=0||date_1>30)
                    {
                        cout<<"����������������룺";
                        cin>>date_1;
                    }
                    q->LoanNumber+=tag_1;
                    p->BookLoanNum+=tag_1;
                    p->BookFreeNum-=tag_1;
                    Loansum+=tag_1;
                    Insert_LoanBook(Loanhead,p,q,date_1,2,Loansum);
                    cout<<"���ĳɹ����뽫ͼ�����Ʊ��ܣ�\n";
                }
                else
                {
                    cout<<"�Ѿ��ﵽ�������ƣ��޷����飡";
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
                    cout<<"������ؼ��ʣ�";
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
                            cout<<"û���������κ���Ϣ��\n";
                        cout<<"�Ƿ�����������<Y/N>";
                        char question;
                        cin>>question;
                        if(question=='N'||question=='n')
                        {
                            cout<<"�Ѿ��������Լ���Ҫ��ͼ�飿�Ƿ���飿<Y/N>";
                            char answer;
                            cin>>answer;
                            if(answer=='Y'||answer=='y')
                            {
                                cout<<"������Ҫ����ͼ�����ţ�";
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
                                 cout<<"��ͼ�鲻�ܱ����ģ���Ϊû���㹻��ͼ�飡\n";
                                 cout<<"����������ؼ��ʣ�";
                             }
                             break;
                        }
                        cout<<"������ؼ��ʣ�";
                    }
                    Reader *q;
                    q=Readerhead;
                    string ReaderID1;
                    char ans_1,ans_2;
                    tag_1=1;
                    cout<<"����������˵�֤�����룺";
                    while(cin>>ReaderID1)
                    {
                        if((Search_Reader(Readerhead,ReaderID1))==1)
                        {
                             cout<<"�������Ľ������Ƿ�Ϊ���ı��ˣ�<Y/N>";
                             cin>>ans_1;
                             if(ans_1=='Y'||ans_1=='y')
                             {
                                  break;
                             }
                        }
                        else
                        {
                            cout<<"��������½������Ƿ�����µĽ����˲�������Ϣ��<Y/N>";
                            cin>>ans_2;
                            if(ans_2=='Y'||ans_2=='y')
                            {
                                Insert_Reader(Readerhead,Readersum);
                                break;
                            }
                            else
                            cout<<"֤����������������������룺";

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
                        cout<<"�������������<��������30>��";
                        int date_1;
                        cin>>date_1;
                        while(date_1<=0||date_1>30)
                        {
                             cout<<"����������������룺";
                             cin>>date_1;
                        }
                        q->LoanNumber+=tag_1;
                        p->BookLoanNum+=tag_1;
                        p->BookFreeNum-=tag_1;
                        Loansum+=1;
                        Insert_LoanBook(Loanhead,p,q,date_1,2,Loansum);
                        cout<<"���ĳɹ����뽫ͼ�����Ʊ��ܣ�\n";
                    }
                    else
                    {
                        cout<<"�Ѿ��ﵽ�������ƣ��޷����飡";
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
            cout<<"��������������������������\n";
            cout<<"                     ��ѡ���ܱ�\n";
            cout<<"                     1.����ԤԼ\n";
            cout<<"                     2.���ݲ����ԤԼ\n";
            cout<<"��������������������������\n";
            cin>>ans;
            if(ans==1)
            {
                Books *s,*p;
                p=s=Bookhead;
                int tag;
                int temp=0;
                cout<<"������������";
                while(cin>>Name)
                {
                    while((Search_Book(Bookhead,Name))!=1)
                    {
                        cout<<"û����������ص�ͼ�飡\n";
                        cout<<"���ڴ�����������";
                        cin>>Name;
                    }
                    cout<<"��������ͼ���б����£�";
                    for(s=Bookhead;s!=NULL;s=s->next)
                    {
                        if(s->BookName==Name)
                        {
                            s->show();
                        }
                    }
                    cout<<"������ҪԤԼͼ�����ţ�";
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
                        cout<<"��ͼ���п��У�����ԤԼ��\n";
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
                    cout<<"������ԤԼ�˵�֤�����룺";
                    while(cin>>ReaderID1)
                    {
                         if((Search_Reader(Readerhead,ReaderID1))==1)
                        {
                            cout<<"��������ԤԼ���Ƿ�Ϊ���ı��ˣ�<Y/N>";
                            cin>>ans_1;
                            if(ans_1=='Y'||ans_1=='y')
                            {
                                 break;
                            }
                        }
                        else
                       {
                           cout<<"��������¶����Ƿ�����µĶ��߲�������Ϣ��<Y/N>";
                           cin>>ans_2;
                           if(ans_2=='Y'||ans_2=='y')
                           {
                               Insert_Reader(Readerhead,Readersum);
                               break;
                           }
                           else
                           cout<<"֤����������������������룺";

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
                         cout<<"������ȡ������<��������20>��";
                        int date_1;
                        cin>>date_1;
                        while(date_1<=0||date_1>20)
                        {
                            cout<<"����������������룺";
                            cin>>date_1;
                        }
                        q->ReservationNumber+=1;
                        p->BookReservationNum+=1;
                        Loansum+=1;
                        Insert_LoanBook(Loanhead,p,q,date_1,1,Loansum);
                        cout<<"ԤԼ�ɹ������п���ͼ��ʱ�뼰ʱȡ�飡\n";
                        Append_Book("e://BookManger//books.txt",Bookhead);
                        Append_Reader("e://BookManger//reader.txt",Readerhead);
                        Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
                    }
                    else
                    {
                         cout<<"�Ѿ��ﵽ�������ƣ��޷�ԤԼ��";
                    }
                }
            }
            if(ans==2)
            {
                cout<<"�Ƿ���ʾ����ͼ�飿<Y/N>";
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
                    cout<<"������ԤԼ����ţ�";
                    while(cin>>temp)
                    {
                        if(temp>=0&&temp<Booksum)
                            break;
                        else
                        {
                            cout<<"����������������룺";
                        }
                    }
                    Books *h;
                    h=Bookhead;
                    while(h->Bookid!=temp)
                    {
                        h=h->next;
                    }
                    h->show();
                    cout<<"������Ϣ�Ƿ�ΪҪԤԼ��ͼ�飡��<Y/N>";
                    for(p=Bookhead;p->Bookid!=temp;p=p->next)
                    {
                    }
                    char ans_0;
                    cin>>ans_0;
                    if(ans_0=='Y'||ans_0=='y')
                    {
                        if(h->BookFreeNum!=0)
                        {
                            cout<<"��ͼ���п��У�����ԤԼ��\n";
                        }
                        else
                        {
                            char ans_1,ans_2;
                            string ReaderID1;
                            cout<<"������ԤԼ�˵�֤�����룺";
                            while(cin>>ReaderID1)
                            {
                                if((Search_Reader(Readerhead,ReaderID1))==1)
                                {
                                    cout<<"��������ԤԼ���Ƿ�Ϊ���ı��ˣ�<Y/N>";
                                    cin>>ans_1;
                                    if(ans_1=='Y'||ans_1=='y')
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    cout<<"��������¶����Ƿ�����µĶ��߲�������Ϣ��<Y/N>";
                                    cin>>ans_2;
                                    if(ans_2=='Y'||ans_2=='y')
                                    {
                                        Insert_Reader(Readerhead,Readersum);
                                        break;
                                    }
                                    else
                                    cout<<"֤����������������������룺";

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
                                cout<<"������ȡ������<��������20>��";
                                int date_1;
                                cin>>date_1;
                                while(date_1<=0||date_1>20)
                                {
                                    cout<<"����������������룺";
                                    cin>>date_1;
                                }
                                q->ReservationNumber+=1;
                                p->BookReservationNum+=1;
                                Loansum+=1;
                                Insert_LoanBook(Loanhead,p,q,date_1,1,Loansum);
                                cout<<"ԤԼ�ɹ������п���ͼ��ʱ�뼰ʱȡ�飡\n";
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
            cout<<"             ��ѡ���ܱ�\n";
            cout<<"             1.����\n";
            cout<<"             2.��������\n";
            cout<<"             3.ͼ���Լ�鿴\n";
            cout<<"====================================\n";
            cin>>choice1;
            if(choice1==1)
            {
                LoanBook *s,*p,*h;
                s=p=Loanhead;
                cout<<"���������ͼ���֤�����룺";
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
                        cout<<"������Ϣ�Ƿ�Ϊ������Ϣ��<Y/N>";
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
                                cout<<"����ɹ���\n";
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
                                cout<<"����ɹ���\n";
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
                        cout<<"����������û�н����¼���Ƿ��������֤���ţ�<Y/N>";
                        char ans;
                        cin>>ans;
                        if(ans=='Y'||ans=='y')
                        {
                            cout<<"����������֤�����룺";
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
                cout<<"����Ҫ���û���ʣ�Ľ���ʱ�䲻�ó���10�죡\n";
                cout<<"���������ͼ���֤�����룺";
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
                        cout<<"������Ϣ�Ƿ�Ϊ������Ϣ��<Y/N>";
                        char ans_1;
                        cin>>ans_1;
                        if(ans_1=='y'||ans_1=='Y')
                        {
                            if(Loanhead->person->ReaderID==tag)
                            {
                                if(Loanhead->Deadline>=11)
                                {
                                    cout<<"��ʣ����ʱ�䳬������Ҫ��\n";
                                    break;
                                }
                                cout<<"�������ӳ���ʱ��(�������20��)��";
                                int a;
                                while(cin>>a)
                                {
                                    if(a>0&&a<=20)
                                        break;
                                    else
                                    {
                                        cout<<"���������룡(�������20��)\n";
                                    }
                                }
                                Loanhead->Deadline+=a;
                                cout<<"���ڳɹ���\n";
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
                                    cout<<"��ʣ����ʱ�䳬������Ҫ��\n";
                                    break;
                                }
                                cout<<"�������ӳ���ʱ��(�������20��)��";
                                int c;
                                while(cin>>c)
                                {
                                    if(c>0&&c<=20)
                                        break;
                                    else
                                    {
                                        cout<<"���������룡(�������20��)\n";
                                    }
                                }
                                s->Deadline+=c;
                                cout<<"���ڳɹ���\n";
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
                        cout<<"��������Ƿ��������֤���ţ�<Y/N>";
                        char ans;
                        cin>>ans;
                        if(ans=='Y'||ans=='y')
                        {
                            cout<<"����������֤�����룺";
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
            cout<<"                       ��ѡ���ܣ�\n";
            cout<<"                       1.��ѯ�鼮��Ϣ.\n";
            cout<<"                       2.��ѯ��Ա��Ϣ.\n";
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
                 cout<<"������ͼ���ţ�";
                 while(cin>>s)
                 {
                    h=Bookhead;
                    while(h)
                    {
                        if(h->BookID==s)
                        {
                            cout<<"��ͼ����Ϣ���£�\n";
                            h->show();
                            if(h->BookLoanNum!=0||h->BookReservationNum!=0)
                            {
                                while(p)
                                {
                                    if(p->book->BookID==s)
                                    {
                                        num++;
                                        if(num==1)
                                        cout<<"��ͼ��Ľ��ĺ�ԤԼ��Ϣ���£�\n";
                                        p->show();
                                    }
                                    p=p->next;
                                }
                            }
                            sum++;
                            if(num==0)
                                cout<<"��ͼ��û�н���ԤԼ��Ϣ��\n";
                            break;
                        }
                        h=h->next;
                    }
                    if(sum==0)
                    {
                        cout<<"û�������Ϣ���Ƿ����������ţ�<Y/N>";
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
                cout<<"���������֤�����룺";
                while(cin>>s)
                {
                    h=Readerhead;
                    while(h)
                    {
                        if(h->ReaderID==s)
                        {
                            cout<<"�˶�����Ϣ���£�\n";
                            h->show();
                            if(h->LoanNumber!=0||h->ReservationNumber!=0)
                            {
                                while(p)
                                {
                                    if(p->person->ReaderID==s)
                                    {
                                        num++;
                                        if(num==1)
                                        cout<<"�����ߵĽ��ĺ�ԤԼ��Ϣ���£�\n";
                                        p->show();
                                    }
                                    p=p->next;
                                }
                            }
                            sum++;
                            if(num==0)
                                cout<<"�˶���û�н���ԤԼ��Ϣ��\n";
                            break;
                        }
                        h=h->next;
                    }
                    if(sum==0)
                    {
                        cout<<"û�������Ϣ���Ƿ���������֤�ţ�<Y/N>";
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
            cout<<"                   ��ѡ���ܱ�\n";
            cout<<"                   0.������һ��.\n";
            cout<<"                   1.ͼ����Ϣͳ��.\n";
            cout<<"                   2.������Ϣͳ��.\n";
            cout<<"                   3.��Լ��Ϣͳ��.\n";
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            while(cin>>choice1)
            {
                if(choice1==0)
                    break;
                if(choice1==1)
                {
                    int choice2;
                    cout<<"_____________________________________________\n";
                    cout<<"               1.�ݲ��鼮��ʾ\n";
                    cout<<"               2.��ͼ�������ʾ\n";
                    cout<<"               3.�ݲ�ͼ��״̬\n";
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
                            cout<<"��ͼ�����Ϊ"<<b[m]<<"�ģ�\n";
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
                        cout<<"ͼ�����һ����"<<Booksum<<"��ͼ�飬";
                        cout<<"�ڼ���"<<sum3<<"��ͼ��"<<endl;
                        cout<<"������"<<sum1<<"��ͼ�飬";
                        cout<<"��ԤԼ"<<sum2<<"��ͼ��"<<endl;
                    }
                }
                if(choice1==2)
                {
                    int choice2;
                    cout<<"_____________________________________________\n";
                    cout<<"               1.���ж�����ʾ\n";
                    cout<<"               2.��ѧԺ��ʾ\n";
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
                            cout<<b[m]<<"�ģ�\n";
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
                cout<<"                   ��ѡ���ܱ�\n";
                cout<<"                   0.������һ��.\n";
                cout<<"                   1.ͼ����Ϣͳ��.\n";
                cout<<"                   2.������Ϣͳ��.\n";
                cout<<"                   3.��Լ��Ϣͳ��.\n";
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            }
        }
        if(choice==8)
        {
            if(h10->ReaderID=="0131122589")
            {cout<<"\n1.���ӹ���Ա\n";
             cout<<"2.ɾ������Ա\n";
             int tag;
             cin>>tag;
             if(tag==1)
             {
                cout<<"����������Ϊ����Ա��֤�����룺";
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
                    cout<<"û�������������Ϣ��\n";
                    break;
                }
                if(num>0)
                {
                    cout<<"�Ƿ񽫴�������Ϊ����Ա��<Y/N>";
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
                 cout<<"������ѡ��ɾ���Ĺ���Ա��ţ�";
                 int ans;
                 cin>>ans;
                 while(h)
                 {
                     if(h->Readerid==ans)
                     {
                         if(h->ReaderID=="0131122589")
                         {
                             cout<<"�޷��޸Ĵ��û���\n";
                             break;
                         }
                         else
                         {
                             h->ReaderManager='n';
                             cout<<"�޸ĳɹ���\n";
                             break;
                         }
                     }
                     h=h->next;
                 }
             }
            }
            else
            {
                cout<<"��û��Ȩ�ޣ�\n";
            }

        }
        cout<<"*******************************************************************************\n";
        cout<<"                        ��ѡ���ܣ�\n";
        cout<<"                        0.������һ��.\n";
        cout<<"                        1.ͼ����Ϣ����.\n";
        cout<<"                        2.������Ա��Ϣ����.\n";
        cout<<"                        3.ͼ�����.\n";
        cout<<"                        4.ͼ��ԤԼ.\n";
        cout<<"                        5.ͼ�������뻹��.\n";
        cout<<"                        6.��Ϣ��ѯ,\n";
        cout<<"                        7.��Ϣͳ��.\n";
        cout<<"                        8.����Ա����.\n";
        cout<<"*******************************************************************************\n";
    }
    }
    }
    if(answer==2)  //�ǹ���Աϵͳ
    {
        int wrong1=0;
        string a8,a9;
        Reader *s0,*h0;
        s0=h0=Readerhead;
        cout<<"�������û�����";
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
                cout<<"�û�������������������룺";
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
                cout<<"��������Ƿ��������룿<Y/N>";
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
        cout<<"                           ��ѡ���ܣ�\n";
        cout<<"                           0.������һ��\n";
        cout<<"                           1.ͼ��ԤԼ\n";
        cout<<"                           2.ͼ������\n";
        cout<<"                           3.������Ϣ�޸�\n";
        cout<<"                           4.�鿴������Ϣ\n";
        cout<<"                           5.��Լ��Ϣ�鿴\n";
        cout<<"                           6.ͼ��ݲ���鿴\n";
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
                cout<<"��������������������������\n";
                cout<<"                     ��ѡ���ܱ�\n";
                cout<<"                     1.����ԤԼ\n";
                cout<<"                     2.���ݲ����ԤԼ\n";
                cout<<"��������������������������\n";
                cin>>ans;
                if(ans==1)
                {
                    Books *s,*p;
                    p=s=Bookhead;
                    int tag;
                    cout<<"������������";
                    while(cin>>Name)
                    {
                        while((Search_Book(Bookhead,Name))!=1)
                        {
                            cout<<"û����������ص�ͼ�飡\n";
                            cout<<"���ڴ�����������";
                            cin>>Name;
                        }
                        cout<<"��������ͼ���б����£�";
                        for(s=Bookhead;s!=NULL;s=s->next)
                        {
                            if(s->BookName==Name)
                            {
                                s->show();
                            }
                        }
                        cout<<"������ҪԤԼͼ�����ţ�";
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
                            cout<<"��ͼ�黹���ڼܣ�����ԤԼ��\n";
                            cout<<"����������������";
                        }
                    }
                    if(s0->Permission>=(1+s0->ReservationNumber+s0->LoanNumber))
                    {
                        cout<<"������ɵȴ�������<��������20>��";
                        int date_1;
                        cin>>date_1;
                        while(date_1<=0||date_1>20)
                        {
                            cout<<"����������������룺";
                            cin>>date_1;
                        }
                        s0->ReservationNumber+=1;
                        p->BookReservationNum+=1;
                        Loansum+=1;
                        Insert_LoanBook(Loanhead,p,s0,date_1,1,Loansum);
                        cout<<"ԤԼ�ɹ������п��е�ͼ��������ʱȡ�飡\n";
                    }
                    else
                    {
                        cout<<"�Ѿ��ﵽ�������ƣ��޷�ԤԼ��";
                    }
                }
                if(ans==2)
                {
                    cout<<"�Ƿ���ʾ����ͼ�飿<Y/N>";
                    char ch;
                    cin>>ch;
                    if(ch=='Y'||ch=='y')
                    {
                        int temp;
                        Books *p;
                        p=Bookhead;
                        Show_Book(Bookhead);
                        cout<<"������ԤԼ����ţ�";
                        while(cin>>temp)
                        {
                            if(temp>=0&&temp<Booksum)
                                break;
                            else
                            {
                                cout<<"����������������룺";
                            }
                        }
                        Books *h;
                        h=Bookhead;
                        while(h->Bookid!=temp)
                        {
                            h=h->next;
                        }
                        h->show();
                        cout<<"������Ϣ�Ƿ�ΪҪԤԼ��ͼ�飡��<Y/N>";
                        char ans_0;
                        cin>>ans_0;
                        if(ans_0=='Y'||ans_0=='y')
                        {
                            if(h->BookFreeNum!=0)
                            {
                                cout<<"��ͼ�黹���ڼܣ�����ԤԼ��\n";
                            }
                            else
                            {
                                if(s0->Permission>=(1+s0->ReservationNumber+s0->LoanNumber))
                                {
                                    cout<<"������ȴ�����<��������20>��";
                                    int date_1;
                                    cin>>date_1;
                                    while(date_1<=0||date_1>20)
                                    {
                                        cout<<"����������������룺";
                                        cin>>date_1;
                                    }
                                    s0->ReservationNumber+=1;
                                    p->BookReservationNum+=1;
                                    Loansum+=1;
                                    Insert_LoanBook(Loanhead,p,s0,date_1,1,Loansum);
                                    cout<<"ԤԼ�ɹ������п��е�ͼ��������ʱȡ�飡\n";
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
                cout<<"����Ҫ���û���ʣ�Ľ���ʱ�䲻�ó���10�죡\n";
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
                            cout<<"��ʣ����ʱ�䳬������Ҫ��\n";
                            break;
                        }
                        cout<<"�������ӳ���ʱ��(�������20��)��";
                        int a;
                        while(cin>>a)
                        {
                            if(a>0&&a<=20)
                                break;
                            else
                            {
                                cout<<"���������룡(�������20��)\n";
                            }
                        }
                        Loanhead->Deadline+=a;
                        cout<<"���ڳɹ���\n";
                    }
                    else
                    {
                        while(s->person->ReaderID!=tag)
                        {
                            s=s->next;
                        }
                        if(s->Deadline>=11)
                        {
                            cout<<"��ʣ����ʱ�䳬������Ҫ��\n";
                            break;
                        }
                        else
                        {
                            cout<<"�������ӳ���ʱ��(�������20��)��";
                            int c;
                            while(cin>>c)
                            {
                                if(c>0&&c<=20)
                                    break;
                                else
                                {
                                    cout<<"���������룡(�������20��)\n";
                                }
                            }
                            s->Deadline+=c;
                            cout<<"���ڳɹ���\n";
                        }
                    }
                }
                else
                {
                    cout<<"�㻹û�н����κ�һ���飡\n";
                }
                Append_Book("e://BookManger//books.txt",Bookhead);
                Append_Reader("e://BookManger//reader.txt",Readerhead);
                Append_LoanBook("e://BookManger//loanbook.txt",Loanhead);
            }
            if(ans0==3)
            {
                cout<<"��������������������������������������������������������\n";
                cout<<"                     ��ѡ���޸���Ϣ��\n";
                cout<<"                     1.֤������\n";
                cout<<"                     2.��������\n";
                cout<<"                     3.���ߵ�λ\n";
                cout<<"                     4.�޸�����\n";
                cout<<"��������������������������������������������������������\n";
                int tag_1;
                cin>>tag_1;
                if(tag_1==1)
                {
                    if(s0->ReaderID!="0131122589")
                    {cout<<"����������֤�����룺";
                    cin>>s0->ReaderID;
                    cout<<"�޸ĳɹ���\n";}
                    else
                    {
                        cout<<"�޷��޸ģ�";
                    }
                }
                if(tag_1==2)
                {
                    cout<<"����������������";
                    cin>>s0->ReaderName;
                    cout<<"�޸ĳɹ���\n";
                }
                if(tag_1==3)
                {
                    cout<<"���������ĵ�λ:";
                    cin>>s0->ReaderUnit;
                    cout<<"�޸ĳɹ���\n";
                }
                if(tag_1==4)
                {
                    cout<<"���������ľ����룺";
                    string oldkey;
                    while(cin>>oldkey)
                    {
                        if(s0->ReaderKey==oldkey)
                            break;
                        else
                        {
                            cout<<"����������������룺";
                        }
                    }
                    cout<<"���������������룺";
                    cin>>s0->ReaderKey;
                    cout<<"�޸ĳɹ���\n";
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
                    cout<<"����û�н��ĺ�ԤԼ��Ϣ��\n";
                }
            }
            if(ans0==6)
            {
                int choice2;
                cout<<"_____________________________________________\n";
                cout<<"               1.�ݲ��鼮��ʾ\n";
                cout<<"               2.��ͼ�������ʾ\n";
                cout<<"               3.�ݲ�ͼ��״̬\n";
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
                        cout<<"��ͼ�����Ϊ"<<b[m]<<"�ģ�\n";
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
                    cout<<"ͼ�����һ����"<<Booksum<<"��ͼ�飬";
                    cout<<"�ڼ���"<<sum3<<"��ͼ��"<<endl;
                    cout<<"������"<<sum1<<"��ͼ�飬";
                    cout<<"��ԤԼ"<<sum2<<"��ͼ��"<<endl;
                }
            }
            cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"                           ��ѡ���ܣ�\n";
            cout<<"                           0.������һ��\n";
            cout<<"                           1.ͼ��ԤԼ\n";
            cout<<"                           2.ͼ������\n";
            cout<<"                           3.������Ϣ�޸�\n";
            cout<<"                           4.�鿴������Ϣ\n";
            cout<<"                           5.��Լ��Ϣ�鿴\n";
            cout<<"                           6.ͼ��ݲ���鿴\n";
            cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }
    }
    }
    if(answer==0)
        break;
    cout<<endl;
    cout<<"              ******************************************\n";
    cout<<"              *            ��ӭʹ��ͼ�����ϵͳ��      *\n";
    cout<<"              *               0.�˳�ϵͳ               *\n";
    cout<<"              *              1.����Ա��½              *\n";
    cout<<"              *             2.��ͨ�û���½             *\n";
    cout<<"              ******************************************\n";
    }

}
