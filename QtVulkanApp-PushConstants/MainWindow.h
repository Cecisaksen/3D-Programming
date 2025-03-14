#ifndef HELLOVULKANWIDGET_H
#define HELLOVULKANWIDGET_H

#include <QWidget>
class QMenu;
class QMenuBar;
class QAction;
class QDialogButtonBox;


QT_FORWARD_DECLARE_CLASS(QTabWidget)
QT_FORWARD_DECLARE_CLASS(QPlainTextEdit)

//Forward declaration
class VulkanWindow;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(VulkanWindow *vw, QPlainTextEdit *logWidget);

public slots:
    void onScreenGrabRequested();

private:
    VulkanWindow *mVulkanWindow{ nullptr };
    QTabWidget *mInfoTab{ nullptr };
    QPlainTextEdit *mLogWidget{ nullptr };
    QMenuBar* menuBar;
    QMenu* fileMenu;
    QAction* openFileAction;
    QAction* exitAction;
    QMenuBar* createMenu();
private slots:
    void openFile();

};

#endif // HELLOVULKANWIDGET_H
