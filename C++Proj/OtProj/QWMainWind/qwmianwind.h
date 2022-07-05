#ifndef QWMIANWIND_H
#define QWMIANWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class QWMianWind; }
QT_END_NAMESPACE

class QWMianWind : public QMainWindow
{
    Q_OBJECT

public:
    QWMianWind(QWidget *parent = nullptr);
    ~QWMianWind();

private slots:
    void on_actBold_triggered(bool checked);

    void on_actItalic_triggered(bool checked);

    void on_actUnderline_triggered(bool checked);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    //自定义槽函数
    void on_spinBoxFontSize_valueChanged(int aFontSize); // 改变字体大小
    void on_comboFont_currentIndexChanged(const QString &arg1); //选择字体

private:
    Ui::QWMianWind *ui;
    QLabel *fLabCurFile; // 当前打开文件的label
    QProgressBar *progressBar1; // 进度条
    QSpinBox *spinFontSize; // 字体大小spibBox
    QFontComboBox *comboFont; // 字体名称comboFont
    void initUI(); // 代码实现的UI
    void initSignalSlots(); // 信号与槽的关联

};
#endif // QWMIANWIND_H
