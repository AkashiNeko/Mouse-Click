#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    this->timer = new QTimer(this);
    ui->setupUi(this);
    ui->btnStop->setDisabled(true);
    ui->spnRandom->setDisabled(true);
    ui->labGithub->setOpenExternalLinks(true);
    ui->labGithub->setText("<a style='color:blue;' href=\"https://github.com/AkashiNeko/Mouse-Click\">GitHub");
    timer->setInterval(1000);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

Widget::~Widget() {
    delete timer;
    delete ui;
}


void Widget::on_chkRandom_stateChanged(int check) {
    ui->spnRandom->setDisabled(!check);
}
#include <iostream>
using namespace std;

void Widget::on_btnStart_clicked() {

    this->cnt = ui->spnInterval->value();
    cout << cnt << endl;
    timer->start();
    ui->btnStop->setDisabled(false);
    ui->btnStart->setDisabled(true);
}

void Widget::on_btnStop_clicked() {
    timer->stop();
    ui->btnStop->setDisabled(true);
    ui->btnStart->setDisabled(false);
}

void Widget::onTimeout() {
    if (cnt)
        cnt--;
    cout << "qwq" << cnt << endl;
}

int Widget::getTime() {
    return 0;
}

