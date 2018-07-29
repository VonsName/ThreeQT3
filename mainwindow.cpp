#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QtDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("menu");
    this->resize(500,300);
    //获取菜单栏
    QMenuBar *mb=menuBar();
    //添加菜单
    QMenu *mu=mb->addMenu("文件");
    //添加菜单项
    QAction *ac= mu->addAction("新建");
    connect(ac,&QAction::triggered,
            [](){
        qDebug()<<"新建被按下";
    });

    mu->addSeparator();//添加分割线
    QAction *popen= mu->addAction("打开");
    //设置非模态对话框
    connect(popen,&QAction::triggered,
            [=](){
        QDialog *dig=new QDialog(this);
        dig->resize(100,100);
        dig->show();
        //手动释放内存 当关闭这个对话框的时候
        dig->setAttribute(Qt::WA_DeleteOnClose);
    });

    mu->addSeparator();
    QAction *pdia=mu->addAction("模态对话框");
    connect(pdia,&QAction::triggered,
            [](){
        QDialog dig;
        dig.resize(100,100);
        dig.exec();
    });

    //工具栏
    QToolBar *bar=addToolBar("toolBar");
    QPushButton *b=new QPushButton(this);
    b->setText("addNew");
    //工具栏添加快捷键
    bar->addWidget(b);
    connect(b,&QPushButton::pressed,
            [=](){
        b->setText("123");
        qDebug()<<"按钮工具栏";
    });

    //状态栏
    QStatusBar *sbar=statusBar();
    QLabel *label=new QLabel(this);
    label->setText("normal");
    //默认是从左向右
    sbar->addWidget(label);
    sbar->addWidget(new QLabel("2",this));
    //从右向左添加
    sbar->addPermanentWidget(new QLabel("3",this));

    //核心控件 设置文本编辑区
    QTextEdit *edit=new QTextEdit(this);
    this->setCentralWidget(edit);

    //浮动窗口
    QDockWidget *dw=new QDockWidget(this);

    QTextEdit *edit1=new QTextEdit(this);

    //给浮动窗口添加控件
    dw->setWidget(edit1);
    //第一个参数窗口拜访的位置
    this->addDockWidget(Qt::RightDockWidgetArea ,dw);




}

MainWindow::~MainWindow()
{

}
