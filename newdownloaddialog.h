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

private slots:
    void on_btnAddDownload_clicked();

    void on_btnCancelDownload_clicked();

private:
    Ui::NewDownloadDialog *ui;
};

#endif // NEWDOWNLOADDIALOG_H
