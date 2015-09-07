#ifndef QXMPPSIMPLEARCHIVEIQ_H
#define QXMPPSIMPLEARCHIVEIQ_H

#include "QXmppIq.h"
#include "QXmppResultSet.h"

#include <QDateTime>

class QXmlStreamWriter;
class QDomElement;

/// \brief Represents an archive message query as defined by
/// XEP-0313: Message Archive Management
///
/// It is used to get messages via a result set
///
/// \ingroup Stanzas

class QXMPP_EXPORT QXmppSimpleArchiveQueryIq : public QXmppIq
{
public:
    QXmppSimpleArchiveQueryIq();

    QXmppResultSetReply resultSetReply() const;
    void setResultSetReply(const QXmppResultSetReply &rsm);

    /// \cond
    static bool isSimpleArchiveQueryIq(const QDomElement &element);

    QString queryId() const;
    void setQueryId(const QString& queryId);

    QDateTime start() const;
    void setStart(const QDateTime &start);

    QDateTime end() const;
    void setEnd(const QDateTime &end );

    QString with() const;
    void setWith(const QString &with);

    QXmppResultSetQuery resultSetQuery() const;
    void setResultSetQuery(const QXmppResultSetQuery &rsm);
protected:
    void parseElementFromChild(const QDomElement &element);
    void toXmlElementFromChild(QXmlStreamWriter *writer) const;
    /// \endcond

private:
    QString m_with;
    QDateTime m_start;
    QDateTime m_end;
    QString m_queryId;
    QXmppResultSetQuery m_rsmQuery;
    QXmppResultSetReply m_rsmReply;
};

#endif // QXMPPSIMPLEARCHIVEIQ_H
