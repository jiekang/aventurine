/*
    Aventurine Alpha
    Copyright (C) 2014  Jie Kang

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <functional>

#include <QObject>


#include "methoddata.h"

class Storage : public QObject
{
        Q_OBJECT

    public:
        Storage();

    public slots:
        void addMethodData(MethodData* md);
    signals:
        void dataAdded(MethodData* md, int x, int y);

    private:
        int x = 0;
        int y = 0;

        std::vector<MethodData*> methodVector;
};

#endif // STORAGE_H
