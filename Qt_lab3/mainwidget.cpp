#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    buttonSize=50;
    scale=100;
    xShift=300;
    yShift=200;

    ui->btnAdd->setStyleSheet("background-color: rgb(50,100,150); ");
    ui->btnRemove->setStyleSheet("background-color: rgb(100,200,10); ");
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_btnAdd_clicked()
{
    QPushButton* btn=new QPushButton(this);
    btn->setText(QString::number(buttonList.size()));

    if (buttonList.size()%2==0) {
        btn->setStyleSheet("background-color: rgb(200,0,0); ");
    }
    else {
        btn->setStyleSheet("background-color: rgb(0,0,200); ");
    }
    btn->setGeometry(ui->btnAdd->geometry());
    btn->show();
    buttonList.append(btn);

    rearrangeButtons();
}

void MainWidget::rearrangeButtons()
{
    int buttonCount=buttonList.size();
    float angleUnit=6.28/buttonCount;

    for (int i = 0;i<buttonCount;i++) {
        QPushButton* btn=buttonList.at(i);
        QPropertyAnimation* animation = new QPropertyAnimation(btn, "geometry");
        animation->setDuration(100);
        animation->setEasingCurve(QEasingCurve::Linear);
        animation->setEndValue(QRectF(cos(angleUnit*i)*2*scale+xShift,sin(angleUnit*3*i)*scale+yShift,buttonSize,buttonSize));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void MainWidget::on_btnRemove_clicked()
{
    QPushButton* btn = buttonList.last();
    buttonList.removeLast();
    delete btn;

    rearrangeButtons();
}
