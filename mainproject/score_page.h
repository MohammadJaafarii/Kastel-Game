#ifndef SCORE_PAGE_H
#define SCORE_PAGE_H

#include <QDialog>

namespace Ui {
class score_page;
}

class score_page : public QDialog
{
    Q_OBJECT

public:
    explicit score_page(QWidget *parent = nullptr);
    ~score_page();

private slots:
    void on_pushButton_clicked();

private:
    Ui::score_page *ui;
};

#endif // SCORE_PAGE_H
