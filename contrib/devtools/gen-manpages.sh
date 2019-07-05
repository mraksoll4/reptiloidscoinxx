#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

REPTILOIDSCOIND=${REPTILOIDSCOIND:-$BINDIR/reptiloidscoind}
REPTILOIDSCOINCLI=${REPTILOIDSCOINCLI:-$BINDIR/reptiloidscoin-cli}
REPTILOIDSCOINTX=${REPTILOIDSCOINTX:-$BINDIR/reptiloidscoin-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/reptiloidscoin-wallet}
REPTILOIDSCOINQT=${REPTILOIDSCOINQT:-$BINDIR/qt/reptiloidscoin-qt}

[ ! -x $REPTILOIDSCOIND ] && echo "$REPTILOIDSCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
RTDVER=($($REPTILOIDSCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for reptiloidscoind if --version-string is not set,
# but has different outcomes for reptiloidscoin-qt and reptiloidscoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$REPTILOIDSCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $REPTILOIDSCOIND $REPTILOIDSCOINCLI $REPTILOIDSCOINTX $WALLET_TOOL $REPTILOIDSCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${RTDVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${RTDVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
