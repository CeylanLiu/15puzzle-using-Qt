#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#include <QObject>
#include <QWidget>
#include<QLabel>

class settlement : public QWidget
{
    Q_OBJECT
public:
    explicit settlement(QWidget *parent = nullptr);
    QLabel *label_of_time;
    QFont Ft1;
    QLabel *label_of_step;
    QFont Ft2;
    QLabel *label_of_win;
    QFont Ft3;
signals:
};

#endif // PANOF9_H
