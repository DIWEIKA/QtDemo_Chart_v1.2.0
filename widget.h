#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QChartView>
#include <QValueAxis>
#include <QLineSeries>
#include <QSplineSeries>
#include <fstream>
#include <sstream>


#define READ_LENGTH 40960
#define CHDATA_ALL_LENGTH 10240
#define CHDATA_LENGTH 2560

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }

QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer;

    /* 图表对象 */
    QChart* m_chart;

    /* 横纵坐标轴对象 */
    QValueAxis *m_axisX, *m_axisY;

    /* 曲线图对象 */
    QSplineSeries* m_lineSeries;

    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 2560, AXIS_MAX_Y = 700;

    /* 用来记录数据点数 */
    int pointCount = 0;

    QVector<QPointF> pointsSeries;
    QString saveFolder;//存储目录（文件夹）
    QString saveFilenameAll;
    ifstream infileAll;
    char CHdata[READ_LENGTH];
    int CHdata_DEC_all[CHDATA_ALL_LENGTH] =  {0};
    int CHdata_DEC_1[CHDATA_LENGTH]= {0};
    int CHdata_DEC_2[CHDATA_LENGTH] =  {0};
    int CHdata_DEC_3[CHDATA_LENGTH] =  {0};
    int CHdata_DEC_4[CHDATA_LENGTH] =  {0};

    void slotTimeout();
    void ReadFromFiles();

private slots:

    void on_btnStartAndStop_clicked();

    void on_btnReset_clicked();

private:
    Ui::widget *ui;
};
#endif // WIDGET_H
