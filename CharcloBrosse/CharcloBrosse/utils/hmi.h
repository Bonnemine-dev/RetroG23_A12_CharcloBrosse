
#ifndef HMI_H
#define HMI_H

#include <QWidget>



class HMI : public QWidget

{
    Q_OBJECT

public:
    HMI(QWidget *parent = nullptr);
    ~HMI();
};

#endif // HMI_H
