#ifndef MOUSEACTS_H
#define MOUSEACTS_H

#include <QWidget>
#include <windows.h>

class MouseActs : public QWidget {
    Q_OBJECT
public:
    explicit MouseActs(QWidget *parent = nullptr);
    POINT pos = {0, 0};
public slots:
    void clickCurPos();
};

#endif // MOUSEACTS_H
