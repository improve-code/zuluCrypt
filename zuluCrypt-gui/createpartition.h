/*
 * 
 *  Copyright (c) 2011
 *  name : mhogo mchungu
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CREATEPARTITION_H
#define CREATEPARTITION_H

#include <QWidget>
#include <QString>
#include <QCloseEvent>
#include <QThreadPool>

#include "runinthread.h"
#include "miscfunctions.h"
#include "erasedevice.h"

namespace Ui {
    class createpartition;
}

class createpartition : public QWidget
{
	Q_OBJECT
public:
	explicit createpartition(QWidget *parent = 0);
	~createpartition();
signals:
	void CreateVolume(QString fileSystem,QString containterType,QString volumePath,QString passphrase,bool passphraseFromFile) ;
	void HideUISignal(void);
public slots:
	void ShowPartition(QString volume) ;
	void ShowFile(QString volume) ;
	void HideUI(void);
private slots:
	void pbCreateClicked(void) ;
	void pbCancelClicked(void) ;
	void rbPassphraseClicked(void);
	void rbPasssphraseFromFileClicked(void);
	void pbOpenKeyFile(void);
	void threadfinished(int);
	void rng(int) ;
private:
	void eraseDataPartition(void);
	void findInstalledFs(void);
	void enableAll(void) ;
	void disableAll(void);
	void closeEvent(QCloseEvent *) ;		
	void ShowUI(QString,QString);
	bool m_created ;
	Ui::createpartition * m_ui;
	bool m_isWindowClosable ;
	/*
	  prototyped at miscfunctions.h
	  */
	UIMsg m_msg ;
};

#endif // CREATEPARTITION_H
