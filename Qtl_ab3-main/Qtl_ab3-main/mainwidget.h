#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QList>
#include "math.h"
#include <QPropertyAnimation>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

 private slots:

    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    private:
    Ui::MainWidget *ui;
    int xShift, yShift, scale, buttonSize;

    QList<QPushButton*>buttonList;

    void rearrangeButtons();
};
#endif // MAINWIDGET_H
