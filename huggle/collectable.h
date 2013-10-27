//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.


#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include <QMutex>
#include <QString>
#include <QStringList>
#include "gc.h"
#include "exception.h"

namespace Huggle
{
     //! Base for all items that are supposed to be
     //! collected by garbage collector
    class Collectable
    {
    public:
        Collectable();
        virtual ~Collectable();
        /*!
         * \brief IsManaged
         *  Managed class is deleted by GC and must not be deleted by hand
         * \return whether the class is managed
         */
        bool IsManaged();
        //! Use this if you are not sure if you can delete this object in this moment
        virtual bool SafeDelete();
        bool IsLocked();
        void Lock();
        void Unlock();
        /*!
         * \brief Registers a consumer
         *
         * This function will store a string which prevent the object from being removed
         * by QueryGC, by calling this function you change the query type to managed
         * \param consumer String that lock the object
         */
        void RegisterConsumer(QString consumer);
        /*!
         * \brief This function will remove a string which prevent the object from being removed
         * \param consumer Unique string that unlock the object
         */
        void UnregisterConsumer(QString consumer);
        /*!
         * \brief DebugHgc
         * \return debug info
         */
        QString DebugHgc();
        /*!
         * \brief CollectableID
         * \return
         */
        unsigned long CollectableID();
    private:
        static unsigned long LastCID;
        unsigned long CID;
        //! Internal variable that contains a cache whether object is managed
        bool Managed;
        void SetManaged();
        //! Some queries are needed for dependency setup, so we need to delete them
        //! later once the dependency is processed
        QStringList Consumers;
        QMutex *QL;
        bool Locked;
    };
}
#endif // COLLECTABLE_H
