#include "widget.h"
#include "ui_widget.h"

#include <cstdlib>
#include <ctime>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :QWidget(parent), ui(new Ui::Widget) {
    this->timer = new QTimer(this);
    this->mouse = new MouseActs();
    ui->setupUi(this);
    ui->btnStop->setDisabled(true);
    ui->spnRandom->setDisabled(true);
    ui->cobUnit2->setDisabled(true);
    ui->labGithub->setOpenExternalLinks(true);
    ui->labGithub->setText("<a style='color:blue;' href=\"https://github.com/AkashiNeko/Mouse-Click\">GitHub");
    ui->labNextTime->setStyleSheet("QLabel{color:red;}");
    ui->labCountNumber->setStyleSheet("QLabel{color:red;}");
    timer->setInterval(1000);
    srand(time(NULL));
    connect(this->timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

Widget::~Widget() {
    delete timer;
    delete mouse;
    delete ui;
}


void Widget::on_chkRandom_stateChanged(int check) {
    ui->spnRandom->setDisabled(!check);
    ui->cobUnit2->setDisabled(!check);
}

void Widget::on_btnStart_clicked() {
    this->cnt = ui->spnInterval->value();
    this->total = 0;
    ui->labCountNumber->setText("0 次");
    ui->labNextTime->setText("开始点击");
    cnt = getTime();
    timer->start();
    ui->btnStop->setDisabled(false);
    ui->btnStart->setDisabled(true);
}

void Widget::on_btnStop_clicked() {
    timer->stop();
    ui->btnStop->setDisabled(true);
    ui->btnStart->setDisabled(false);
    ui->labNextTime->setText("已停止");
}

void Widget::onTimeout() {
    if (cnt) {
        if (cnt > 59) {
            int min = cnt / 60;
            int sec = cnt - min * 60;
            ui->labNextTime->setText(QString::number(min) + " 分 " + QString::number(sec) + " 秒");
        }
        else {
            ui->labNextTime->setText(QString::number(cnt) + " 秒");
        }
        --cnt;
    }
    else {
        cnt = getTime();
        mouse->clickCurPos(ui->cobClickStyle->currentIndex());
        ui->labNextTime->setText("已点击屏幕 (" + QString::number(mouse->pos.x) + ", " + QString::number(mouse->pos.y) + ")");
        ui->labCountNumber->setText(QString::number(++total) + " 次");
    }
}

int Widget::getTime() {
    int randTime = 0;
    int interVal = ui->spnInterval->value();
    int random = ui->spnRandom->value();
    if (ui->cobUnit1->currentIndex() == CobIndex::MINUTE)
        interVal *= 60;
    if (ui->cobUnit2->currentIndex() == CobIndex::MINUTE)
        random *= 60;
    if (ui->chkRandom->isChecked() && random) {
        randTime = rand() % (random + 1);
    }
    return interVal + randTime - 1;
}

void Widget::on_btnRandoHelp_clicked() {
    QMessageBox::about(this, tr("提示：点击时间间隔随机化"), tr(
        "实际点击间隔时间 = 点击间隔 + [0, 随机时间]\n\n" \
        "若关闭随机选项，则不启用随机时间\n" \
        "例：若点击间隔设为20秒，随机时间设为5秒，\n" \
        "则实际点击间隔为20~25秒之间。"
    ));
}

void Widget::on_cobUnit1_currentIndexChanged(int index) {
    int cur = ui->spnInterval->value();
    if (index == CobIndex::MINUTE) {
        if (cur < 60)
            ui->spnInterval->setValue(1);
        else
            ui->spnInterval->setValue(cur / 60);
    }
    else {
        ui->spnInterval->setValue(cur * 60);
    }
}

void Widget::on_cobUnit2_currentIndexChanged(int index) {
    int cur = ui->spnRandom->value();
    if (index == CobIndex::MINUTE) {
        if (cur < 60)
            ui->spnRandom->setValue(1);
        else
            ui->spnRandom->setValue(cur / 60);
    }
    else {
        ui->spnRandom->setValue(cur * 60);
    }
}

