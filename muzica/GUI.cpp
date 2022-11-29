#include "GUI.h"

void GUI::initializare()
//functie ce initializeaza pagina principala
{
    auto layout_mare = new QVBoxLayout;
    auto layout_main = new QHBoxLayout;
    auto layout_spacing = new QHBoxLayout;
    auto layout_st = new QVBoxLayout;
    auto layout_dr = new QVBoxLayout;

    this->setLayout(layout_mare);
    layout_mare->addLayout(layout_main);
    layout_mare->addLayout(layout_spacing);
    layout_main->addLayout(layout_st);
    layout_main->addLayout(layout_dr);

    auto form = new QFormLayout;
    auto btn_update = new QPushButton{ "UPDATE" };
    auto btn_del = new QPushButton{ "DELETE" };

    tablel->setModel(model);
    model->setare_elemente(service.get_all());

    form->addRow("Rank:          10\n\n\n\n\n\n\n\n                    1", slider);
    form->addRow("Titlu: ", titlu);
    slider->setRange(0, 10);


    layout_st->addLayout(form);
    layout_dr->addWidget(tablel);
    layout_st->addWidget(btn_update);
    layout_st->addWidget(btn_del);

    QObject::connect(btn_update, &QPushButton::clicked, this, &GUI::modifica);
    QObject::connect(tablel->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
        auto sModel = tablel->selectionModel();
        if (sModel->selectedIndexes().isEmpty())
            return;

        auto index = sModel->selectedIndexes().at(0);

        if (sModel->selectedIndexes().size() != 1)
        {
            auto index2 = sModel->selectedIndexes().at(1);
            qDebug() << index2.data(Qt::DisplayRole).toString();
        }

        vector<Melodie>v = service.get_all();
        int id = index.data(Qt::DisplayRole).toInt();

        for (Melodie e : v)
        {
            if (e.get_ID() == id)
            {
                titlu->setText(QString::fromStdString(e.get_Titlu()));
                slider->setValue(e.get_Rank());
            }
        }
        });

    QObject::connect(btn_del, &QPushButton::clicked, this, &GUI::sterge);

    layout_mare->addSpacing(300);
}


void GUI::modifica()
//functie pentru modificare melodii in tabel
{
    auto sModel = tablel->selectionModel();
    if (sModel->selectedIndexes().isEmpty())
        return;

    auto index = sModel->selectedIndexes().at(0);
    int id = index.data(Qt::DisplayRole).toInt();

    service.modificare(id, titlu->text().toStdString(), slider->value());
    model->setare_elemente(service.get_all());

    repaint();
}

void GUI::sterge()
//functie de stergere melodii din tabel
{
    auto sModel = tablel->selectionModel();

    if (sModel->selectedIndexes().isEmpty())
        return;

    auto index = sModel->selectedIndexes().at(0);
    vector<Melodie>toate_melodiile = service.get_all();
    int id = index.data(Qt::DisplayRole).toInt();
    int numar = 0;

    for (Melodie melodie : toate_melodiile)
    {
        if (melodie.get_ID() == id)
        {
            numar = service.filtrare(melodie.get_Artist());
            break;
        }
    }

    if (numar == 1)
    {
        QMessageBox::warning(nullptr, "Error", "Ultima melodie a artistului!");
        return;
    }
    else {
        service.stergere(id);
        repaint();
        model->setare_elemente(service.get_all());
    }
}

void GUI::paintEvent(QPaintEvent* ev)
//functie pentru desen bare
{
    QPainter p{ this };
    vector<int>inaltime(11);

    for (auto& so : service.get_all()) {
        int nr = so.get_Rank();
        inaltime[nr]++;
    }

    p.drawRect(500, p.device()->height() - 30 * inaltime[0], 30, 500);
    p.drawRect(0, p.device()->height() - 30 * inaltime[1], 30, 500);
    p.drawRect(50, p.device()->height() - 30 * inaltime[2], 30, 500);
    p.drawRect(100, p.device()->height() - 30 * inaltime[3], 30, 500);
    p.drawRect(150, p.device()->height() - 30 * inaltime[4], 30, 500);
    p.drawRect(200, p.device()->height() - 30 * inaltime[5], 30, 500);
    p.drawRect(250, p.device()->height() - 30 * inaltime[6], 30, 500);
    p.drawRect(300, p.device()->height() - 30 * inaltime[7], 30, 500);
    p.drawRect(350, p.device()->height() - 30 * inaltime[8], 30, 500);
    p.drawRect(400, p.device()->height() - 30 * inaltime[9], 30, 500);
    p.drawRect(450, p.device()->height() - 30 * inaltime[10], 30, 500);
    
}

QVariant Fereastra::data(const QModelIndex& index, int role) const
//functie pentru asezarea datelor 
{
    if (role == Qt::DisplayRole)
    {
        Melodie melodie = melodii.at(index.row());
        if (index.column() == 0)
        {
            return QString::number(melodie.get_ID());
        }
        if (index.column() == 1)
        {
            return QString::fromStdString(melodie.get_Titlu());
        }
        if (index.column() == 2)
        {
            return QString::fromStdString(melodie.get_Artist());
        }
        if (index.column() == 3)
        {
            return QString::number(melodie.get_Rank());
        }
        if (index.column() == 4)
        {
            int nr = service.filtrare2(melodie.get_Rank());
            return QString::number(nr);
        }
    }
    return QVariant();
}

void Fereastra::setare_elemente(vector<Melodie> vector)
//functie pentru setarea elementelor
{
    melodii = vector;
    auto top = createIndex(0, 0);
    auto bottom = createIndex(vector.size(), 5);

    emit dataChanged(top, bottom);
    emit layoutChanged();
}
