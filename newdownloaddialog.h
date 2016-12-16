#ifndef NEWDOWNLOADDIALOG_H
#define NEWDOWNLOADDIALOG_H

#include <QDialog>

namespace Ui {
class NewDownloadDialog;
}

class NewDownloadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDownloadDialog(QWidget *parent = 0);
    ~NewDownloadDialog();

private:
    Ui::NewDownloadDialog *ui;
};

#endif // NEWDOWNLOADDIALOG_H
