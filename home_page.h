#ifndef HOMO_PAGE_H
#define HOMO_PAGE_H

#include <QWidget>
#include <mainwindow.h>
#include<forward_or_back.h>

class home_page : public QWidget
{
    Q_OBJECT
public:
    explicit home_page(QWidget *parent = nullptr);
    ~home_page();
    FB *start16;
    FB *start9;
};

#endif // HOMO_PAGE_H
