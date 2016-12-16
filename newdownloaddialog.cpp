#include "newdownloaddialog.h"
#include "ui_newdownloaddialog.h"

NewDownloadDialog::NewDownloadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDownloadDialog)
{
    ui->setupUi(this);

    setModal(true);
    setFixedSize(width(), height());
}

NewDownloadDialog::~NewDownloadDialog()
{
    delete ui;
}

void NewDownloadDialog::on_btnAddDownload_clicked()
{
    hide();
}

void NewDownloadDialog::on_btnCancelDownload_clicked()
{
    hide();
}
