#ifndef POS_H
#define POS_H

#include <QDialog>

namespace Ui {
class Pos;
}

class Pos : public QDialog
{
    Q_OBJECT

public:
    Pos(QWidget *parent, int x, int y);
    void setPos(char p);
    void setX(int x);
    void setY(int y);
    char getPo();
    void setnyet(bool n);
    bool getnyet();
    bool pre;

    ~Pos();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Pos *ui;
    char p;
    int x;
    int y;
    bool nyet;

};

#endif // POS_H
