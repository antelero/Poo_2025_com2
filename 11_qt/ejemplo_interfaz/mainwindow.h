#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnProcesar_clicked();
    void on_btnLimpiar_clicked();
    void onTemporizador();
    void on_btnIniciar_clicked();

private:
    Ui::MainWindow *ui;
    QTimer temporizador;
};
#endif // MAINWINDOW_H
