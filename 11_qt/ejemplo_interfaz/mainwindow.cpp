#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&temporizador,SIGNAL(timeout()),this,SLOT(onTemporizador()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnProcesar_clicked()
{
    QString texto;
    texto = ui->txtTexto->text();
    texto = texto.toUpper();
    if (texto.length()>0){
        if(ui->chkAddLista->isChecked())
            ui->lstTexto->addItem(texto);
        ui->txtResultado->setText(texto);
        QMessageBox::information(this, "Exito!", "Convertido con exito a mayuscula");
    } else {
        QMessageBox::critical(this, "No se puede convertir", "No se ingreso una cadena");
    }
}


void MainWindow::on_btnLimpiar_clicked()
{
    ui->lstTexto->clear();
}


void MainWindow::on_btnIniciar_clicked()
{
    if (temporizador.isActive()){
        temporizador.stop();
        ui->btnIniciar->setText("Iniciar!");
    }
    else {
        temporizador.start(1000);
        ui->btnIniciar->setText("Pausar!");
    }
}

void MainWindow::onTemporizador()
{
    ui->lcdNumber->display(ui->lcdNumber->value()+1);
}
