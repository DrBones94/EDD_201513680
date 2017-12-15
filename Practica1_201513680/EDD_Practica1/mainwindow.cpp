#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QMessageBox>
#include <iostream>
#include "estructuras2.h"
#include <QLineEdit>
#include <QString>
#include <stdlib.h>

static int cant_a, cant_e, cant_t, cant_em;
static int contador_a, contador_t, contador_t1;
static QString consola = "";
static QString tipos[] = {"Pequeño", "Mediano", "Grande"};
static ColaD *coladoble = (struct ColaD *)malloc(sizeof(struct ColaD));
static ColaS *colasimple = new ColaS();


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nombre_a = "A" + QString::number(contador_a);
    QString nombre_p = "P" + QString::number(contador_t);

    if((contador_a < cant_a) && (contador_t < cant_t)){

        int random = rand() % 2;

        insertarCD(coladoble, tipos[random], nombre_a, cantidadPA(random), turnosA(random), turnosAM(random));
        contador_a++;
    }

    if(coladoble->primero->turn_d == 0 && coladoble->primero != NULL){
        insertarCS(colasimple, nombre_p, coladoble->primero->cant_pasajeros);

    }
    else{
        coladoble->primero->turn_d--;
    }


    contador_t++;

    //std::cout<<coladoble->primero->id.toStdString();

    consola += "**********TURNO" + QString::number(contador_t )+ "********** \n";
    consola += "Arribo avion: " + nombre_a + "\n";
    consola += "Avion Desabordando: " + coladoble->primero->id + "\n";
    consola += "----ESCRITORIOS---- \n";

    ui->textEdit->setText(consola);

    std::cout<<mostrarCD(coladoble).toStdString();
    std::cout<<mostrarCS(colasimple).toStdString();
    generarArchivo("digraph g { \n"+mostrarCD(coladoble)+mostrarCS(colasimple) +"}");
}

void MainWindow::on_pushButton_2_clicked()
{
    coladoble->primero = NULL;
    coladoble->ultimo = NULL;
    colasimple->primero = NULL;
    colasimple->ultimo = NULL;
    contador_a = 0;
    contador_t = 0;
    cant_t = ui->lineEdit->text().toInt();
    cant_a = ui->lineEdit_2->text().toInt();
    cant_e = ui->lineEdit_3->text().toInt();
    cant_em = ui->lineEdit_4->text().toInt();
}

