//
// Created by Chriss on 2018/3/3.
//

#ifndef Library_h
#define Library_h

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

#define MAXB 5   //规定最大借书数目
#define MAXD 30 //规定借书期限

typedef struct BookInfo //图书文件结构体
{
    long bookNum;    //图书编号
    string bookName; //图书名称
    char bookIsbn[30];  //书号
    char bookAuth[30];  //作者
    char bookPub[100];  //出版社
    int book_yes;   //在馆情况（0-已经借出；1-未借出）
    struct BookInfo *next;  //链表后继指针
}Book,*BookList;
typedef struct SetTime   //时间结构体
{
    int year;   //年份
    int month;  //月份
    int day;    //日期
}Time;
typedef struct ReaderBorrow //借书信息结构体
{
    long bookNum;    //图书编号
    string bookName; //书名
    struct SetTime t;    //借书时间
}Borrow;
typedef struct ReaderInfo   //读者文件结构体
{
    long reaNum; //读者编号
    string reaName;   //读者姓名
    char reaSex;    //性别（m-男；f-女）
    int rea_yes;   //是否借书（0-没有借书；1-有借书）
    struct ReaderBorrow reaborrow[MAXB];
    int x = 0;//已借书数量
    struct ReaderInfo *next;    //链表后继指针
}Reader,*ReaderList;

//界面
void Face();//欢迎界面check
void Face_Reader();//读者管理界面check
void Face_Book();//图书管理界面check
void Face_ReaderSearch();//读者查询界面check
void Face_BookSearch();//图书查询界面check
void Face_BookBorrowReturn();//图书借还界面check
void Face_Exit();//退出系统check

int Maincourse(BookList &,BookList &,ReaderList &,ReaderList &);//主菜单选择check

Reader *Reader_Initial(ReaderList &);//读者文件初始化check
//读者管理
int ReaderManager(ReaderList &,ReaderList &);//读者管理菜单check
int Reader_View(ReaderList &);//读者一览check
int Reader_Add(ReaderList &);//添加读者check
int Reader_Correct(ReaderList &);//读者信息修改check
int Reader_Delet(ReaderList &);//删除读者check
//读者查询
int ReaderSearch(ReaderList &);//读者查询选择菜单check
int ReaderSearch_Name(ReaderList &);//按姓名查询读者check
int ReaderSearch_Num(ReaderList &);//按编号查询check

Book *Book_Initial(BookList &);//图书文件初始化check
// 图书管理
int BookManager(BookList &,BookList &,ReaderList &);//图书管理菜单check
int Book_View(BookList &);//图书一览check
int Book_Add(BookList &);//添加图书check
int Book_Correct(BookList &);//图书信息修改check
int Book_Delet(BookList &);//删除图书check
//图书查询
int BookSearch(BookList &);//图书查询选择菜单check
int BookSearch_Name(BookList &);//按书名查询check
int BookSearch_Num(BookList &);//按书编号查询check
int Book_BnR(BookList &,ReaderList &);//图书借还check
int Book_Borrow(BookList &,ReaderList &);//借书check
int Book_Return(BookList &,ReaderList &);//还书check
int Book_BorrowInfo(ReaderList &);//借书信息check

//全局变量声明
extern long bnum;
extern long rnum;

long bnum=10000;
long rnum=10000;

/***********************************************
 * 功能描述：欢迎界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：主界面
 ************************************************/
void Face()
{
    cout<<endl<<"          ----------欢迎进入合肥工业大学图书管理系统----------           "<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |     *1.图书管理      |"<<endl;
    cout<<"                |     *2.读者管理      |"<<endl;
    cout<<"                |     *3.退出系统      |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：读者管理界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面2
 ************************************************/
void Face_Reader()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.读者一览     |"<<endl;
    cout<<"                |      *2.读者查询     |"<<endl;
    cout<<"                |      *3.添加读者     |"<<endl;
    cout<<"                |      *4.修改读者     |"<<endl;
    cout<<"                |      *5.删除读者     |"<<endl;
    cout<<"                |      *6.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：图书管理界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面3
 ************************************************/
void Face_Book()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.图书一览     |"<<endl;
    cout<<"                |      *2.图书查询     |"<<endl;
    cout<<"                |      *3.添加图书     |"<<endl;
    cout<<"                |      *4.删除图书     |"<<endl;
    cout<<"                |      *5.图书借还     |"<<endl;
    cout<<"                |      *6.图书修改     |"<<endl;
    cout<<"                |      *7.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：读者查询界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面4
 ************************************************/
void Face_ReaderSearch()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.按姓名查询   |"<<endl;
    cout<<"                |      *2.按编号查询   |"<<endl;
    cout<<"                |      *3.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：图书查询界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面5
 ************************************************/
void Face_BookSearch()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.按书名查询    |"<<endl;
    cout<<"                |      *2.按编号查询    |"<<endl;
    cout<<"                |      *3.返回上页      |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：图书借还界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面6
 ************************************************/
void Face_BookBorrowReturn()
{
    cout<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                |      *1.借书服务     |"<<endl;
    cout<<"                |      *2.还书服务     |"<<endl;
    cout<<"                |      *3.借书一览     |"<<endl;
    cout<<"                |      *4.返回上页     |"<<endl;
    cout<<"                |                     |"<<endl;
    cout<<"                ^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"                     *请输入您的选择： ";
}
/***********************************************
 * 功能描述：退出界面
 * 输入参数：无
 * 输出参数：无
 * 返回值：无
 * 其他说明：界面7
 ************************************************/
void Face_Exit()
{
    cout<<endl;
    cout<<endl;
    cout<<"          ----------欢迎再次登陆图书管理系统----------           "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                                     ---Developed by ChrissHwuang"<<endl;
}
/***********************************************
 * 功能描述：主菜单
 * 输入参数：1～3对应选择功能
 * 输出参数：对应功能
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Maincourse(BookList &bhead,BookList &btail,ReaderList &rhead,ReaderList &rtail)
{
    int m=1;
    while(m!=3)
    {
        Face();
        cin>>m;
        switch(m)
        {
            case 1:
                BookManager(bhead,btail,rhead);
                break;
            case 2:
                ReaderManager(rhead,rtail);
                break;
            case 3:
                Face_Exit();
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：读者文件初始化
 * 输入参数：rtail-读者链表尾指针
 * 输出参数：无
 * 返回值：读者链表
 * 其他说明：无
 ************************************************/
Reader *Reader_Initial(ReaderList &rtail)
{
    Reader *rhead;
    rhead=(Reader *)malloc(sizeof(Reader));
    if(!rhead)
        exit(1);
    rtail=rhead;
    rhead->next=NULL;
    return rhead;
}
/***********************************************
 * 功能描述：读者管理选择菜单
 * 输入参数：1～6（对应相应功能）
 * 输出参数：相应界面
 * 返回值：（1）
 * 其他说明：6为退出;需要尾指针
 ************************************************/
int ReaderManager(ReaderList &rhead,ReaderList &rtail)
{
    int m=7;
    while(m!=6)
    {
        Face_Reader();
        cin>>m;
        switch(m)
        {
            case 1:
                Reader_View(rhead);
                break;
            case 2:
                ReaderSearch(rhead);
                break;
            case 3:
                Reader_Add(rtail);
                break;
            case 4:
                Reader_Correct(rhead);
                break;
            case 5:
                Reader_Delet(rhead);
                break;
            case 6:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：读者一览
 * 输入参数：rhead-读者链表头指针
 * 输出参数：读者信息
 * 返回值：1
 * 其他说明：无
 ************************************************/
int Reader_View(ReaderList &rhead)
{
    Reader *t;
    cout<<"         ----------读者一览----------"<<endl;
    if(rhead->next == NULL)
        cout<<"             ----------暂无读者！----------"<<endl;
    else
    {
        t=rhead->next;
        cout<<setw(10)<<"姓名"<<setw(17)<<"编号"<<setw(8)<<"性别"<<setw(10)<<"读者类型"<<setw(10)<<"是否借书"<<endl;
        while(t)
        {
            cout<<setw(10)<<t->reaName;
            cout<<setw(17)<<t->reaNum;
            if(t->reaSex == 'm')
                cout<<setw(8)<<"男";
            else if(t->reaSex == 'f')
                cout<<setw(8)<<"女";
            if(t->rea_yes == 1)
                cout<<setw(10)<<"是"<<endl;
            else if(t->rea_yes == 0)
                cout<<setw(10)<<"否"<<endl;
            t=t->next;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：添加读者
 * 输入参数：rtail-读者链表尾指针
 * 输出参数：是否成功添加
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Reader_Add(ReaderList &rtail)
{
    Reader * t;
    int i,j;
    i = 0;
    cout<<"         ----------添加读者----------"<<endl;
    cout<<"         ----------系统已经就绪，是否开始添加读者？----------"<<endl;
    cout<<"                     (1->yes ; 0->no)"<<endl;
    cin>>j;
    if(j == 0)
        return 1;
    while(j==1)
    {
        t=(Reader *)malloc(sizeof(Reader));
        if(!t)
            exit(1);
        cout<<endl;
        cout<<"          ---------- ---------- ---------- ----------"<<endl;
        cout<<"                     *请输入读者姓名： ";
        cin>>t->reaName;
        cout<<"                     *请输入读者性别：(m->男 ; f->女) ";
        cin>>t->reaSex;
        t->reaNum = rnum++;
        t->rea_yes = 0;
        t->x = 0;
        rtail->next = t;
        rtail = rtail->next;
        rtail->next = NULL;
        i++;
        cout<<"         ----------是否继续添加读者？----------"<<endl;
        cout<<"                   (1->yes ; 0->no)"<<endl;
        cin>>j;
        if(j == 0)
            break;
    }
    cout<<"         ----------已成功添加"<<i<<"位读者！"<<endl;
    return 1;
}
/***********************************************
 * 功能描述：读者信息修改
 * 输入参数：读者的相关修改信息
 * 输出参数：新的读者文件
 * 返回值：1
 * 其他说明：无
 ************************************************/
int Reader_Correct(ReaderList &rhead)
{
    Reader *t;
    long m;
    t=NULL;
    cout<<"         ----------读者信息修改----------"<<endl;
    while(!t)
    {
        cout<<"   *请输入需要修改信息的读者编号： (输入0返回)";
        cin>>m;
        if(m == 0)
            return 1;
        else
        {
            for(t=rhead->next;t!=NULL;t=t->next)
            {
                if(t->reaNum == m)
                    break;
            }
            if(t == NULL)
            {
                cout << "     ----------对不起，读者编号输入错误！----------" << endl;
                continue;
            }
            else if(t != NULL)
            {
                cout<<"     *请输入修改后的读者姓名：";
                cin>>t->reaName;
                cout<<"     *请输入修改后的读者性别：(m->男 ； f->女)";
                cin>>t->reaSex;
                cout<<endl;
                cout<<"         ----------读者信息已成功修改！----------"<<endl;
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：删除读者
 * 输入参数：删除读者的编号
 * 输出参数：无
 * 返回值：1
 * 其他说明：无
 ************************************************/
int Reader_Delet(ReaderList &rhead)
{
    Reader *t,*p;
    long m;
    t=rhead;
    cout<<"         ----------读者删除----------"<<endl;
    while(t->next!=NULL)
    {
        cout<<"   *请输入需要删除的读者编号：(输入0返回) ";
        cin>>m;
        if(m == 0)
            return 1;
        else
        {
            for(;t->next!=NULL;t=t->next)
            {
                if(t->next->reaNum == m)
                    break;
            }
            if(t->next == NULL)
            {
                cout << "     ----------对不起，读者编号输入错误！----------" << endl;
                continue;
            }
            else if(t->next != NULL)
            {
                p=t->next;
                t->next=p->next;
                free(p);
                cout<<"         ----------读者删除成功！----------"<<endl;
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：按姓名查询读者
 * 输入参数：查询的读者姓名
 * 输出参数：读者信息
 * 返回值：1
 * 其他说明：无
 ************************************************/
int ReaderSearch_Name(ReaderList &rhead)
{
    Reader *t;
    char name[30];
    t=NULL;
    cout<<"         ----------读者信息查询----------"<<endl;
    while(!t)
    {
        cout<<"   *请输入需要查询的读者姓名：(输入0返回) ";
        cin>>name;
        if(name[0] == '0')
            return 1;
        else
        {
            for(t=rhead->next;t!=NULL;t=t->next)
            {
                if(t->reaName == name)
                    break;
            }
            if(t == NULL)
            {
                cout << "     ----------对不起，读者姓名输入错误！----------" << endl;
                continue;
            }
            else if(t != NULL)
            {
                cout<<setw(10)<<"姓名"<<setw(17)<<"编号"<<setw(8)<<"性别"<<setw(10)<<"读者类型"<<setw(10)<<"是否借书"<<endl;
                cout<<setw(10)<<t->reaName;
                cout<<setw(17)<<t->reaNum;
                if(t->reaSex == 'm')
                    cout<<setw(8)<<"男";
                else if(t->reaSex == 'f')
                    cout<<setw(8)<<"女";
                if(t->rea_yes == 1)
                    cout<<setw(10)<<"是"<<endl;
                else if(t->rea_yes == 0)
                    cout<<setw(10)<<"否"<<endl;
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：按编号查询读者
 * 输入参数：查询的读者编号
 * 输出参数：读者信息
 * 返回值：1
 * 其他说明：无
 ************************************************/
int ReaderSearch_Num(ReaderList &rhead)
{
    Reader *t;
    long m;
    t=NULL;
    cout<<"         ----------读者信息查询----------"<<endl;
    while(!t)
    {
        cout<<"   *请输入需要查询的读者编号：（输入0返回） ";
        cin>>m;
        if(m == 0)
            return 1;
        else
        {
            for(t=rhead->next;t!=NULL;t=t->next)
            {
                if(t->reaNum == m)
                    break;
            }
            if(t == NULL)
            {
                cout << "     ----------对不起，读者编号输入错误！----------" << endl;
                continue;
            }
            else if(t != NULL)
            {
                cout<<setw(10)<<"姓名"<<setw(17)<<"编号"<<setw(8)<<"性别"<<setw(10)<<"读者类型"<<setw(10)<<"是否借书"<<endl;
                cout<<setw(10)<<t->reaName;
                cout<<setw(17)<<t->reaNum;
                if(t->reaSex == 'm')
                    cout<<setw(8)<<"男";
                else if(t->reaSex == 'f')
                    cout<<setw(8)<<"女";
                if(t->rea_yes == 1)
                    cout<<setw(10)<<"是"<<endl;
                else if(t->rea_yes == 0)
                    cout<<setw(10)<<"否"<<endl;
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：读者查询选择菜单
 * 输入参数：1～3（对应相应功能）
 * 输出参数：相应界面
 * 返回值：（1）
 * 其他说明：3为退出
 ************************************************/
int ReaderSearch(ReaderList &rhead)
{
    int m=1;
    while(m!=3)
    {
        Face_ReaderSearch();
        cin>>m;
        switch(m)
        {
            case 1:
                ReaderSearch_Name(rhead);
                break;
            case 2:
                ReaderSearch_Num(rhead);
                break;
            case 3:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：图书文件初始化
 * 输入参数：无
 * 输出参数：无
 * 返回值：图书链表
 * 其他说明：无
 ************************************************/
Book *Book_Initial(BookList &btail)
{
    Book *bhead;
    bhead=(Book *)malloc(sizeof(Book));
    if(!bhead)
        exit(1);
    btail=bhead;
    bhead->next=NULL;
    return bhead;
}
/***********************************************
 * 功能描述：图书管理选择菜单
 * 输入参数：1～8（对应相应功能）
 * 输出参数：相应界面
 * 返回值：（1）
 * 其他说明：8为退出；需要尾指针；需要读者链表
 ************************************************/
int BookManager(BookList &bhead,BookList &btail,ReaderList &rhead)
{
    int m=1;
    while(m!=7)
    {
        Face_Book();
        cin>>m;
        switch(m)
        {
            case 1:
                Book_View(bhead);
                break;
            case 2:
                BookSearch(bhead);
                break;
            case 3:
                Book_Add(btail);
                break;
            case 4:
                Book_Delet(bhead);
                break;
            case 5:
                Book_BnR(bhead,rhead);
                break;
            case 6:
                Book_Correct(bhead);
                break;
            case 7:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：图书一览
 * 输入参数：bhead-读者链表头指针
 * 输出参数：图书信息
 * 返回值：1
 * 其他说明：无
 ************************************************/
int Book_View(BookList &bhead)
{
    Book *t;
    cout<<"         ----------图书信息一览----------"<<endl;
    cout<<"书名"<<setw(7)<<"编号"<<setw(7)<<"作者"<<setw(10)<<"出版社"<<setw(14)<<"书号ISBN"<<setw(14)<<"在馆情况"<<endl;
    if(bhead->next==NULL)
        cout<<"     ----------暂无图书在馆！----------"<<endl;
    else
    {
        t=bhead->next;
        while(t)
        {
            cout<<t->bookName;
            cout<<setw(7)<<t->bookNum;
            cout<<setw(7)<<t->bookAuth;
            cout<<setw(7)<<t->bookPub;
            cout<<setw(7)<<t->bookIsbn;
            if(t->book_yes == 1)
                cout<<setw(7)<<"是";
            else if(t->book_yes == 0)
                cout<<setw(7)<<"否"<<endl;
            cout<<endl;
            t=t->next;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：添加图书
 * 输入参数：图书链表尾指针
 * 输出参数：是否成功添加
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Book_Add(BookList &btail)
{
    Book *t;
    int i,j;
    i = 0;
    cout<<"         ----------添加图书----------"<<endl;
    cout<<"         ----------系统已经就绪，是否开始添加图书？----------"<<endl;
    cout<<"                        (1->yes ; 0->no)"<<endl;
    cin>>j;
    while(j==1)
    {
        t=(Book *)malloc(sizeof(Book));
        if(!t)
            exit(1);
        cout<<endl;
        cout<<"          ---------- ---------- ---------- ----------"<<endl;
        cout<<endl;
        cout<<"                     *请输入图书名称： ";
        cin>>t->bookName;
        cout<<"                     *请输入图书作者： ";
        cin>>t->bookAuth;
        cout<<"                     *请输入图书出版社： ";
        cin>>t->bookPub;
        cout<<"                     *请输入图书书号： ";
        cin>>t->bookIsbn;
        t->bookNum = bnum++;
        t->book_yes = 1;
        btail->next = t;
        btail = btail->next;
        btail->next = NULL;
        i++;
        cout<<"         ----------是否继续添加图书？----------"<<endl;
        cout<<"                 (1->yes ; 0->no)"<<endl;
        cin>>j;
    }
    cout<<"         ----------已将"<<i<<"本图书成功入库！----------"<<endl;
    return 1;
}
/***********************************************
 * 功能描述：图书信息修改
 * 输入参数：修改图书编号
 * 输出参数：是否成功修改
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Book_Correct(BookList &bhead)
{
    Book *t;
    long m;
    t=NULL;
    cout<<"         ----------图书信息修改----------"<<endl;
    while(!t)
    {
        cout<<"   *请输入需要修改信息的图书编号：(输入0返回) ";
        cin>>m;
        if(m == 0)
            return 1;
        else
        {
            for(t=bhead->next;t!=NULL;t=t->next)
            {
                if(t->bookNum == m)
                    break;
            }
            if(t == NULL)
            {
                cout << "     ----------对不起，图书编号输入错误！----------" << endl;
                continue;
            }
            else if(t != NULL)
            {
                cout<<"     *请输入修改后的图书名称：";
                cin>>t->bookName;
                cout<<"     *请输入修改后的图书作者：";
                cin>>t->bookAuth;
                cout<<"     *请输入修改后的图书出版社：";
                cin>>t->bookPub;
                cout<<"     *请输入修改后的图书书号：";
                cin>>t->bookIsbn;
                cout<<endl;
                cout<<"         ----------图书信息已成功修改！----------"<<endl;
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：删除图书
 * 输入参数：删除图书编号
 * 输出参数：无
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Book_Delet(BookList &bhead)
{
    Book *t,*p;
    long m;
    t=bhead;
    cout<<"         ----------图书删除----------"<<endl;
    while(t->next!=NULL)
    {
        cout<<"   *请输入需要删除的图书编号：(输入0返回) ";
        cin>>m;
        if(m == 0)
            return 1;
        else
        {
            for(;t->next!=NULL;t=t->next)
            {
                if(t->next->bookNum == m)
                    break;
            }
            if(t->next == NULL)
            {
                cout << "     ----------对不起，图书编号输入错误！----------" << endl;
                continue;
            }
            else if(t->next != NULL)
            {
                p=t->next;
                t->next=p->next;
                free(p);
                cout<<"         ----------图书删除成功！----------"<<endl;
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：图书查询选择菜单
 * 输入参数：1～4（对应相应功能）
 * 输出参数：相应界面
 * 返回值：（1）
 * 其他说明：4为退出
 ************************************************/
int BookSearch(BookList &bhead) //测试！！ 输入4时会出现什么结果？
{
    int m=1;
    while(m!=3)
    {
        Face_BookSearch();
        cin>>m;
        switch(m)
        {
            case 1:
                BookSearch_Name(bhead);
                break;
            case 2:
                BookSearch_Num(bhead);
                break;
            case 3:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：按书名查询
 * 输入参数：查询图书名称
 * 输出参数：图书信息
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int BookSearch_Name(BookList &bhead)
{
    Book *t;
    char name[100];
    t=NULL;
    cout<<"         ----------图书信息查询----------"<<endl;
    while(!t)
    {
        cout<<"   *请输入需要查询的图书名称：(输入0返回) ";
        cin>>name;
        if(name[0] == '0')
            return 1;
        else
        {
            for(t=bhead->next;t!=NULL;t=t->next)
            {
                if(t->bookName == name)
                    break;
            }
            if(t == NULL)
            {
                cout << "     ----------对不起，图书名称输入错误！----------" << endl;
                continue;
            }
            else if(t != NULL)
            {
                cout<<setw(20)<<"书名"<<setw(17)<<"编号"<<setw(9)<<"作者"<<setw(30)<<"出版社"<<setw(30)<<"书号ISBN"<<setw(7)<<"在馆情况"<<endl;
                cout<<setw(20)<<t->bookName;
                cout<<setw(17)<<t->bookNum;
                cout<<setw(9)<<t->bookAuth;
                cout<<setw(30)<<t->bookPub;
                cout<<setw(30)<<t->bookIsbn;
                if(t->book_yes == 1)
                    cout<<setw(7)<<"是";
                else if(t->book_yes == 0)
                    cout<<setw(7)<<"否"<<endl;
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：按图书编号查询
 * 输入参数：查询图书编号
 * 输出参数：图书信息
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int BookSearch_Num(BookList &bhead)
{
    Book *t;
    long num;
    t=NULL;
    cout<<"         ----------图书信息查询----------"<<endl;
    while(!t)
    {
        cout<<"   *请输入需要查询的图书编号： (输入0返回)";
        cin>>num;
        if(num == 0)
            return 1;
        else
        {
            for(t=bhead->next;t!=NULL;t=t->next)
            {
                if(t->bookNum == num)
                    break;
            }
            if(t == NULL)
            {
                cout << "     ----------对不起，图书编号输入错误！----------" << endl;
                continue;
            }
            else if(t != NULL)
            {
                cout<<setw(20)<<"书名"<<setw(17)<<"编号"<<setw(9)<<"作者"<<setw(30)<<"出版社"<<setw(30)<<"书号ISBN"<<setw(7)<<"在馆情况"<<endl;
                cout<<setw(20)<<t->bookName;
                cout<<setw(17)<<t->bookNum;
                cout<<setw(9)<<t->bookAuth;
                cout<<setw(30)<<t->bookPub;
                cout<<setw(30)<<t->bookIsbn;
                if(t->book_yes == 1)
                    cout<<setw(7)<<"是";
                else if(t->book_yes == 0)
                    cout<<setw(7)<<"否"<<endl;
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：借还选择菜单
 * 输入参数：1~4对应相应功能
 * 输出参数：相应功能
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Book_BnR(BookList &bhead,ReaderList &rhead)
{
    int m=1;
    while(m!=4)
    {
        Face_BookBorrowReturn();
        cin>>m;
        switch(m)
        {
            case 1:
                Book_Borrow(bhead,rhead);
                break;
            case 2:
                Book_Return(bhead,rhead);
                break;
            case 3:
                Book_BorrowInfo(rhead);
                break;
            case 4:
                break;
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：借书
 * 输入参数：读者编号，图书编号
 * 输出参数：是否成功
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Book_Borrow(BookList &bhead,ReaderList &rhead)
{
    Book *b;
    Reader *r;
    long mb,mr;
    b=NULL;
    r=NULL;
    cout<<"         ----------借书服务----------"<<endl;
    while(!r)
    {
        cout<<"     *请输入读者编号：(输入0返回) ";
        cin>>mr;
        if(mr == 0)
            return 1;
        else
        {
            for(r=rhead->next;r!=NULL;r=r->next)
            {
                if(r->reaNum == mr)
                    break;
            }
            if(r == NULL)
            {
                cout << "     ----------对不起，读者编号输入错误！----------" << endl;
                continue;
            }
            else if(r != NULL)
            {
                if(r->x==4)
                    cout<<"         ----------对不起！您的借书数量已达上限！----------";
                else
                {
                    while(!b)
                    {
                        cout<<"   *请输入需要借阅的图书编号： ";
                        cin>>mb;
                        for(b=bhead->next;b!=NULL;b=b->next)
                        {
                            if(b->bookNum == mb)
                                break;
                        }
                        if(b == NULL)
                        {
                            cout << "     ----------对不起，图书编号输入错误！----------" << endl;
                            continue;
                        }
                        else if(b != NULL)
                        {
                            if(b->book_yes == 0)
                                cout<<"         ----------对不起！该图书已经借出！----------";
                            else
                            {
                                r->rea_yes = 1;
                                r->reaborrow[r->x].bookNum = mb;
                                r->reaborrow[r->x].bookName = b->bookName;
                                b->book_yes = 0;
                                time_t timer=time(0);
                                struct tm *now=localtime(&timer);
                                r->reaborrow[r->x].t.year = 1900+now->tm_year;
                                r->reaborrow[r->x].t.month = 1+now->tm_mon;
                                r->reaborrow[r->x].t.day = now->tm_mday;
                                r->x++;
                                cout<<"         ----------借阅成功！----------";
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：还书
 * 输入参数：读者编号，图书编号
 * 输出参数：是否成功
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Book_Return(BookList &bhead,ReaderList &rhead)
{
    Book *b;
    Reader *r;
    int i,flag;
    long mb,mr;
    cout<<"         ----------还书服务----------"<<endl;
    b=NULL;
    r=NULL;
    while(!r)
    {
        cout<<"     *请输入读者编号：(输入0返回) ";
        cin>>mr;
        if(mr == 0)
            return 1;
        else
        {
            for(r=rhead->next;r!=NULL;r=r->next)
            {
                if(r->reaNum == mr)
                    break;
            }
            if(r == NULL)
            {
                cout << "     ----------对不起，读者编号输入错误！----------" << endl;
                continue;
            }
            else if(r != NULL)
            {
                while(!b)
                {
                    cout<<"   *请输入需要归还的图书编号： ";
                    cin>>mb;
                    for(b=bhead->next;b!=NULL;b=b->next)
                    {
                        if(b->bookNum == mb)
                            break;
                    }
                    if(b == NULL)
                    {
                        cout << "     ----------对不起，图书编号输入错误！----------" << endl;
                        continue;
                    }
                    else if(b != NULL)
                    {
                        i = 0;
                        flag = 0;
                        while(i<r->x)
                        {
                            if(mb == r->reaborrow[i].bookNum)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if(flag==1)
                        {
                            b->book_yes = 1;
                            r->x--;
                            if(r->x==0)
                                r->rea_yes=0;
                            cout<<"         ----------归还图书成功！----------";
                        }
                        else if(flag == 0)
                            cout<<"         *借书信息错误！"<<endl;
                    }
                }
            }
        }
    }
    return 1;
}
/***********************************************
 * 功能描述：借书信息
 * 输入参数：读者编号
 * 输出参数：读者借书信息
 * 返回值：（1）
 * 其他说明：无
 ************************************************/
int Book_BorrowInfo(ReaderList &rhead)
{
    Reader *t;
    long m;
    int i;
    cout<<"         ----------读者借书信息查询----------"<<endl;
    t=NULL;
    while(!t)
    {
        cout<<"   *请输入需要查询的读者编号：(输入0返回) ";
        cin>>m;
        if(m == 0)
            return 1;
        else
        {
            for(t=rhead->next;t!=NULL;t=t->next)
            {
                if(t->reaNum == m)
                    break;
            }
            if(t == NULL)
            {
                cout << "     ----------对不起，读者编号输入错误！----------" << endl;
                continue;
            }
            else if(t != NULL)
            {
                if(t->rea_yes == 0)
                    cout<<"         *该读者没有借书！";
                else
                {
                    for(i=0;i<t->x;i++)
                    {
                        printf("%d-%d-%d",t->reaborrow[i].t.year,t->reaborrow[i].t.month,t->reaborrow[i].t.day);
                        cout<<"         "<<t->reaborrow[i].bookName;
                        cout<<"         "<<t->reaborrow[i].bookNum;
                        cout<<endl;
                    }
                }
            }
        }
    }
    return 1;
}
#endif /* Library_h */
