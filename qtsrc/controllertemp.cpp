#include "controllertemp.h"

ControllerTemp::ControllerTemp()
{

}

void ControllerTemp::connect(MainWindow *w, Storage *s) {
    QObject::connect(s, SIGNAL(dataAdded(MethodData*,int,int)),
                     w, SLOT(addIconToScene(MethodData*,int,int)));
}
