#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "mouseacts.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

namespace CobIndex {
    enum TimeStyle { MINUTE, SECOND };
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_chkRandom_stateChanged(int arg1);

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void onTimeout();

    void on_btnRandoHelp_clicked();

    void on_cobUnit1_currentIndexChanged(int index);

    void on_cobUnit2_currentIndexChanged(int index);

private:
    int getTime();
    size_t cnt = 0;
    size_t total = 0;
    MouseActs* mouse;
    QTimer* timer;
    Ui::Widget *ui;
};
#endif // WIDGET_H
