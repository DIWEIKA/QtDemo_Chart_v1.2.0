#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chart.h"
#include <QDebug>
#include <fstream>
#include <sstream>

using namespace std;

#define READ_LENGTH 4096
#define CHDATA_ALL_LENGTH 1024
#define CHDATA_LENGTH 256

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
     Chart *chart;
      QVector<QPointF> pointsSeries;
      QString saveFolder;//´æ´¢Ä¿Â¼£¨ÎÄ¼þ¼Ð£©
      QString saveFilenameAll;
      ifstream infileAll;

      char CHdata[READ_LENGTH];
      int CHdata_DEC_all[CHDATA_ALL_LENGTH];
      int CHdata_DEC_1[CHDATA_LENGTH];
      int CHdata_DEC_2[CHDATA_LENGTH];
      int CHdata_DEC_3[CHDATA_LENGTH];
      int CHdata_DEC_4[CHDATA_LENGTH];

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initChart();

    void ReadFromFiles();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
