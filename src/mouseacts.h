#ifndef MOUSEACTS_H
#define MOUSEACTS_H

#include <QWidget>
#include <windows.h>

enum ClickStyle {LS, LD, RS, RD};

class MouseActs : public QWidget {
    Q_OBJECT
public:
    explicit MouseActs(QWidget *parent = nullptr);
    POINT pos = {0, 0};
public slots:
    void clickCurPos(int style);
};

#endif // MOUSEACTS_H
