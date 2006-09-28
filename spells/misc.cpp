#include "../spellbook.h"

class spUpdateArray : public Spell
{
public:
	QString name() const { return "Update"; }
	QString page() const { return "Array"; }
	
	bool isApplicable( const NifModel * nif, const QModelIndex & index )
	{
		return nif->isArray( index );
	}
	
	QModelIndex cast( NifModel * nif, const QModelIndex & index )
	{
		nif->updateArray( index );
		return index;
	}
};

REGISTER_SPELL( spUpdateArray )

class spUpdateHeader : public Spell
{
public:
	QString name() const { return "Update"; }
	QString page() const { return "Header"; }
	
	bool isApplicable( const NifModel * nif, const QModelIndex & index )
	{
		return ( nif->getHeader() == nif->getBlockOrHeader( index ) );
	}
	
	QModelIndex cast( NifModel * nif, const QModelIndex & index )
	{
		nif->updateHeader();
		return index;
	}
};

REGISTER_SPELL( spUpdateHeader )

class spUpdateFooter : public Spell
{
public:
	QString name() const { return "Update"; }
	QString page() const { return "Footer"; }
	
	bool isApplicable( const NifModel * nif, const QModelIndex & index )
	{
		return ( nif->getFooter() == nif->getBlockOrHeader( index ) );
	}
	
	QModelIndex cast( NifModel * nif, const QModelIndex & index )
	{
		nif->updateFooter();
		return index;
	}
};

REGISTER_SPELL( spUpdateFooter )

/* XPM */
static char * followlink_xpm[] = {
"48 48 2 1",
" 	c None",
".	c #000000",
"                                                ",
"                                                ",
"                                                ",
"                                                ",
"                    .....                       ",
"                  ........                      ",
"                 ..........                     ",
"                ............                    ",
"               .............                    ",
"              ..............                    ",
"             ...............                    ",
"            ................                    ",
"           .................                    ",
"          ..................                    ",
"         ...................                    ",
"        ....................                    ",
"       .....................                    ",
"      ......................                    ",
"    .......................................     ",
"   .........................................    ",
"   ..........................................   ",
"  ............................................  ",
"  ............................................  ",
"  ............................................  ",
"  ............................................  ",
"   ...........................................  ",
"   ..........................................   ",
"    .........................................   ",
"     ......................................     ",
"      .....................                     ",
"       ....................                     ",
"        ...................                     ",
"         ..................                     ",
"          .................                     ",
"           ................                     ",
"            ...............                     ",
"             ..............                     ",
"              .............                     ",
"               ............                     ",
"                ..........                      ",
"                 .........                      ",
"                  ......                        ",
"                                                ",
"                                                ",
"                                                ",
"                                                ",
"                                                ",
"                                                "};
QIcon * followlink_xpm_icon = 0;

class spFollowLink : public Spell
{
public:
	QString name() const { return "Follow Link"; }
	bool instant() const { return true; }
	QIcon icon() const
	{
		if ( ! followlink_xpm_icon )
			followlink_xpm_icon = new QIcon( followlink_xpm );
		return *followlink_xpm_icon;
	}
	
	bool isApplicable( const NifModel * nif, const QModelIndex & index )
	{
		return nif->isLink( index ) && nif->getLink( index ) >= 0;
	}
	
	QModelIndex cast( NifModel * nif, const QModelIndex & index )
	{
		QModelIndex idx = nif->getBlock( nif->getLink( index ) );
		if ( idx.isValid() )
			return idx;
		else
			return index;
	}
};

REGISTER_SPELL( spFollowLink )

class spFileOffset : public Spell
{
public:
	QString name() const { return "File Offset"; }
	
	bool isApplicable( const NifModel * nif, const QModelIndex & index )
	{
		return nif && index.isValid();
	}
	
	QModelIndex cast( NifModel * nif, const QModelIndex & index )
	{
		int ofs = nif->fileOffset( index );
		qWarning( QString( "estimated file offset is %1 (0x%2)" ).arg( ofs ).arg( ofs, 0, 16 ).toAscii() );
		return index;
	}
};

REGISTER_SPELL( spFileOffset )
