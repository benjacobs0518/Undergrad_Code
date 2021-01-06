#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "cell.h"
#include "histogram.h"
using namespace std;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool livingCell(int x, int y) ; //returns if the cell at that location is alive
    void Turn(); // takes a turn for changing all values and display


private slots:
    void on_stepButton_clicked(); //step button slot

    void on_speedSlider_sliderMoved(int position); //slider slot

    void on_playButton_clicked(); //play button slot

    void on_pauseButton_clicked(); //pause button slot

    void on_thanosSnap_clicked(); //thanos snap button slot

    void on_ruleButton_clicked(); // rule button slot

private:

    Ui::MainWindow *ui; //set up ui to main window

    vector<Cell*> grid_; // grid for all cells
    vector<Histogram*> hists_; //vector for all historgrams

    int GetNeighbors(Cell* c); //find amount of living neighbors

    QGraphicsScene *main_scene; //main scene is for the grid and cells
    QGraphicsScene *histogram_scene; //histogram scene is for diaplaying the histogram

    //general values
    int turn_count = 0;
    int population_ = 100;
    int total_ = 450;
    int speed_ = 5;
    bool paused_ = false;
    bool play_ = false;

    //values for histogram location
    int y_offset_;
    double h_offset_;
    int maxSize_;

    //enable disable rule panel
    bool rulesEnabled = false;

};
#endif // MAINWINDOW_H
