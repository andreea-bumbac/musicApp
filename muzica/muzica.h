#pragma once
#include <QtWidgets/QWidget>
#include "ui_muzica.h"

class muzica : public QWidget
{
    Q_OBJECT

public:
    muzica(QWidget* parent = nullptr);
    ~muzica();

private:
    Ui::muzicaClass ui;
};
