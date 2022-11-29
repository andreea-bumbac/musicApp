#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qslider.h>
#include "Service.h"
#include <QtWidgets/QFormLayout.h>
#include <QtWidgets/QMessageBox.h>
#include <QPainter.h>

class Fereastra :public QAbstractTableModel {
    vector<Melodie> melodii;

    Service& service;

public:
    Fereastra(QObject* parent, Service& s) :service{ s }, QAbstractTableModel(parent){}

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override;

    void setare_elemente(vector<Melodie>vector);

    int rowCount(const QModelIndex& parent = QModelIndex())const override {
        return melodii.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override
    {
        return 5;
    }

    Fereastra() = default;
};



class GUI : public QWidget
{
    Service& service;
public:
    GUI(Service& service_asignare) :service{ service_asignare } {
        initializare();

    }

    void sterge();
    void paintEvent(QPaintEvent* ev)override;
    void initializare();
    void modifica();


private:
    Fereastra* model = new Fereastra(0, service);
    QLineEdit* titlu = new QLineEdit;
 
    QSlider* slider = new QSlider{ Qt::Vertical };
    QTableView* tablel = new QTableView;
};
