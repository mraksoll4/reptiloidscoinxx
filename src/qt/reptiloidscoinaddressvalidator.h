// Copyright (c) 2011-2014 The ReptiloidsCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef REPTILOIDSCOIN_QT_REPTILOIDSCOINADDRESSVALIDATOR_H
#define REPTILOIDSCOIN_QT_REPTILOIDSCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ReptiloidsCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ReptiloidsCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** ReptiloidsCoin address widget validator, checks for a valid reptiloidscoin address.
 */
class ReptiloidsCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ReptiloidsCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // REPTILOIDSCOIN_QT_REPTILOIDSCOINADDRESSVALIDATOR_H
