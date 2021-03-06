#ifndef SPELL_STRINGPALETTE_H
#define SPELL_STRINGPALETTE_H

#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QListView>
#include <QListWidget>
#include <QPushButton>
#include <QStringListModel>

//! \file stringpalette.h StringPaletteRegexDialog

class NifModel;

//! String palette QRegExp dialog for spEditStringEntries
class StringPaletteRegexDialog : public QDialog
{
	Q_OBJECT
public:
	//! Constructor. Sets widgets and layout.
	StringPaletteRegexDialog( NifModel * nif, QPersistentModelIndex & index, QWidget * parent = 0 );

protected:
	//! Model used
	NifModel * nif;
	//! Index of the string palette
	QPersistentModelIndex iPalette;
	//! Lists the strings in the palette
	QListView * listview;
	//! Internal representation of the current state of the palette
	QStringListModel * listmodel;
	//! Original palette
	QStringList * originalList;
	//! Grid layout
	QGridLayout * grid;
	//! Regular expression to search for
	QLineEdit * search;
	//! String to replace with
	QLineEdit * replace;

public slots:
	//! Performs regex replacement of \link search \endlink to \link replace \endlink in \link listmodel \endlink
	void stringlistRegex();
	//! Set the string palette entries
	void setStringList( QStringList & list );
	//! Get the modified string palette
	QStringList getStringList();

};

#endif
