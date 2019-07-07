# Copyright (c) 2013-2016 The ReptiloidsCoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS) $(GPROF_LDFLAGS) $(SANITIZER_LDFLAGS)
AM_CXXFLAGS = $(DEBUG_CXXFLAGS) $(HARDENED_CXXFLAGS) $(WARN_CXXFLAGS) $(NOWARN_CXXFLAGS) $(ERROR_CXXFLAGS) $(GPROF_CXXFLAGS) $(SANITIZER_CXXFLAGS)
AM_CPPFLAGS = $(DEBUG_CPPFLAGS) $(HARDENED_CPPFLAGS)
AM_LIBTOOLFLAGS = --preserve-dup-deps
EXTRA_LIBRARIES =

if EMBEDDED_UNIVALUE
LIBUNIVALUE = univalue/libunivalue.la

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
else
LIBUNIVALUE = $(UNIVALUE_LIBS)
endif

REPTILOIDSCOIN_INCLUDES=-I$(builddir) $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

REPTILOIDSCOIN_INCLUDES += -I$(srcdir)/secp256k1/include
REPTILOIDSCOIN_INCLUDES += $(UNIVALUE_CFLAGS)

LIBREPTILOIDSCOIN_SERVER=libreptiloidscoin_server.a
LIBREPTILOIDSCOIN_COMMON=libreptiloidscoin_common.a
LIBREPTILOIDSCOIN_CONSENSUS=libreptiloidscoin_consensus.a
LIBREPTILOIDSCOIN_CLI=libreptiloidscoin_cli.a
LIBREPTILOIDSCOIN_UTIL=libreptiloidscoin_util.a
LIBREPTILOIDSCOIN_CRYPTO_BASE=crypto/libreptiloidscoin_crypto_base.a
LIBREPTILOIDSCOINQT=qt/libreptiloidscoinqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

if ENABLE_ZMQ
LIBREPTILOIDSCOIN_ZMQ=libreptiloidscoin_zmq.a
endif
if BUILD_REPTILOIDSCOIN_LIBS
LIBREPTILOIDSCOINCONSENSUS=libreptiloidscoinconsensus.la
endif
if ENABLE_WALLET
LIBREPTILOIDSCOIN_WALLET=libreptiloidscoin_wallet.a
LIBREPTILOIDSCOIN_WALLET_TOOL=libreptiloidscoin_wallet_tool.a
endif

LIBREPTILOIDSCOIN_CRYPTO= $(LIBREPTILOIDSCOIN_CRYPTO_BASE)
if ENABLE_SSE41
LIBREPTILOIDSCOIN_CRYPTO_SSE41 = crypto/libreptiloidscoin_crypto_sse41.a
LIBREPTILOIDSCOIN_CRYPTO += $(LIBREPTILOIDSCOIN_CRYPTO_SSE41)
endif
if ENABLE_AVX2
LIBREPTILOIDSCOIN_CRYPTO_AVX2 = crypto/libreptiloidscoin_crypto_avx2.a
LIBREPTILOIDSCOIN_CRYPTO += $(LIBREPTILOIDSCOIN_CRYPTO_AVX2)
endif
if ENABLE_SHANI
LIBREPTILOIDSCOIN_CRYPTO_SHANI = crypto/libreptiloidscoin_crypto_shani.a
LIBREPTILOIDSCOIN_CRYPTO += $(LIBREPTILOIDSCOIN_CRYPTO_SHANI)
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*.h) $(wildcard secp256k1/src/*.c) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBREPTILOIDSCOIN_CRYPTO) \
  $(LIBREPTILOIDSCOIN_UTIL) \
  $(LIBREPTILOIDSCOIN_COMMON) \
  $(LIBREPTILOIDSCOIN_CONSENSUS) \
  $(LIBREPTILOIDSCOIN_SERVER) \
  $(LIBREPTILOIDSCOIN_CLI) \
  $(LIBREPTILOIDSCOIN_WALLET) \
  $(LIBREPTILOIDSCOIN_WALLET_TOOL) \
  $(LIBREPTILOIDSCOIN_ZMQ)

lib_LTLIBRARIES = $(LIBREPTILOIDSCOINCONSENSUS)

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_REPTILOIDSCOIND
  bin_PROGRAMS += reptiloidscoind
endif

if BUILD_REPTILOIDSCOIN_CLI
  bin_PROGRAMS += reptiloidscoin-cli
endif
if BUILD_REPTILOIDSCOIN_TX
  bin_PROGRAMS += reptiloidscoin-tx
endif
if ENABLE_WALLET
if BUILD_REPTILOIDSCOIN_WALLET
  bin_PROGRAMS += reptiloidscoin-wallet
endif
endif

.PHONY: FORCE check-symbols check-security
# reptiloidscoin core #
REPTILOIDSCOIN_CORE_H = \
  addrdb.h \
  addrman.h \
  attributes.h \
  banman.h \
  base58.h \
  bech32.h \
  bloom.h \
  blockencodings.h \
  blockfilter.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coins.h \
  compat.h \
  compat/assumptions.h \
  compat/byteswap.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  consensus/consensus.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  cuckoocache.h \
  fs.h \
  httprpc.h \
  httpserver.h \
  index/base.h \
  index/txindex.h \
  indirectmap.h \
  init.h \
  interfaces/chain.h \
  interfaces/handler.h \
  interfaces/node.h \
  interfaces/wallet.h \
  key.h \
  key_io.h \
  keystore.h \
  dbwrapper.h \
  hashdb.h \
  limitedmap.h \
  logging.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  net_processing.h \
  netaddress.h \
  netbase.h \
  netmessagemaker.h \
  node/transaction.h \
  noui.h \
  optional.h \
  outputtype.h \
  policy/feerate.h \
  policy/fees.h \
  policy/policy.h \
  policy/rbf.h \
  pow.h \
  protocol.h \
  psbt.h \
  random.h \
  reverse_iterator.h \
  reverselock.h \
  rpc/blockchain.h \
  rpc/client.h \
  rpc/mining.h \
  rpc/protocol.h \
  rpc/server.h \
  rpc/rawtransaction.h \
  rpc/register.h \
  rpc/util.h \
  scheduler.h \
  script/descriptor.h \
  script/ismine.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  shutdown.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/events.h \
  support/lockedpool.h \
  sync.h \
  threadsafety.h \
  threadinterrupt.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  undo.h \
  util/bip32.h \
  util/bytevectorhash.h \
  util/system.h \
  util/memory.h \
  util/moneystr.h \
  util/time.h \
  validation.h \
  validationinterface.h \
  versionbits.h \
  versionbitsinfo.h \
  walletinitinterface.h \
  wallet/coincontrol.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/feebumper.h \
  wallet/fees.h \
  wallet/psbtwallet.h \
  wallet/rpcwallet.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  wallet/wallettool.h \
  wallet/walletutil.h \
  wallet/coinselection.h \
  warnings.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqconfig.h\
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h \
  zmq/zmqrpc.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh "$(abs_top_builddir)/src/obj/build.h" \
	  "$(abs_top_srcdir)"
libreptiloidscoin_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between reptiloidscoind and reptiloidscoin-qt
libreptiloidscoin_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
libreptiloidscoin_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libreptiloidscoin_server_a_SOURCES = \
  addrdb.cpp \
  addrman.cpp \
  banman.cpp \
  bloom.cpp \
  blockencodings.cpp \
  blockfilter.cpp \
  chain.cpp \
  checkpoints.cpp \
  consensus/tx_verify.cpp \
  httprpc.cpp \
  httpserver.cpp \
  index/base.cpp \
  index/txindex.cpp \
  interfaces/chain.cpp \
  interfaces/handler.cpp \
  interfaces/node.cpp \
  init.cpp \
  dbwrapper.cpp \
  hashdb.cpp \
  merkleblock.cpp \
  miner.cpp \
  net.cpp \
  net_processing.cpp \
  node/transaction.cpp \
  noui.cpp \
  outputtype.cpp \
  policy/fees.cpp \
  policy/policy.cpp \
  policy/rbf.cpp \
  pow.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  rpc/util.cpp \
  script/sigcache.cpp \
  shutdown.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  ui_interface.cpp \
  validation.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(REPTILOIDSCOIN_CORE_H)

if !ENABLE_WALLET
libreptiloidscoin_server_a_SOURCES += dummywallet.cpp
endif

if ENABLE_ZMQ
libreptiloidscoin_zmq_a_CPPFLAGS = $(REPTILOIDSCOIN_INCLUDES) $(ZMQ_CFLAGS)
libreptiloidscoin_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libreptiloidscoin_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp \
  zmq/zmqrpc.cpp
endif


# wallet: shared between reptiloidscoind and reptiloidscoin-qt, but only linked
# when wallet enabled
libreptiloidscoin_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
libreptiloidscoin_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libreptiloidscoin_wallet_a_SOURCES = \
  interfaces/wallet.cpp \
  wallet/coincontrol.cpp \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/feebumper.cpp \
  wallet/fees.cpp \
  wallet/init.cpp \
  wallet/psbtwallet.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  wallet/walletutil.cpp \
  wallet/coinselection.cpp \
  $(REPTILOIDSCOIN_CORE_H)

libreptiloidscoin_wallet_tool_a_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
libreptiloidscoin_wallet_tool_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libreptiloidscoin_wallet_tool_a_SOURCES = \
  wallet/wallettool.cpp \
  $(REPTILOIDSCOIN_CORE_H)

# crypto primitives library
crypto_libreptiloidscoin_crypto_base_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libreptiloidscoin_crypto_base_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libreptiloidscoin_crypto_base_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/chacha20.h \
  crypto/chacha20.cpp \
  crypto/common.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha512.cpp \
  crypto/sha512.h \
  crypto/siphash.cpp \
  crypto/siphash.h \
  crypto/yespower/yespower.h \
  crypto/yespower/yespower.c \
  crypto/yespower/sha256.h \
  crypto/yespower/sha256.c \
  crypto/yespower/sysendian.h \
  crypto/yespower/insecure_memzero.h \
  crypto/yespower/yespower-opt.c \
  crypto/yespower/yespower-platform.c
  
if USE_ASM
crypto_libreptiloidscoin_crypto_base_a_SOURCES += crypto/sha256_sse4.cpp
endif

crypto_libreptiloidscoin_crypto_sse41_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libreptiloidscoin_crypto_sse41_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libreptiloidscoin_crypto_sse41_a_CXXFLAGS += $(SSE41_CXXFLAGS)
crypto_libreptiloidscoin_crypto_sse41_a_CPPFLAGS += -DENABLE_SSE41
crypto_libreptiloidscoin_crypto_sse41_a_SOURCES = crypto/sha256_sse41.cpp

crypto_libreptiloidscoin_crypto_avx2_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libreptiloidscoin_crypto_avx2_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libreptiloidscoin_crypto_avx2_a_CXXFLAGS += $(AVX2_CXXFLAGS)
crypto_libreptiloidscoin_crypto_avx2_a_CPPFLAGS += -DENABLE_AVX2
crypto_libreptiloidscoin_crypto_avx2_a_SOURCES = crypto/sha256_avx2.cpp

crypto_libreptiloidscoin_crypto_shani_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libreptiloidscoin_crypto_shani_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libreptiloidscoin_crypto_shani_a_CXXFLAGS += $(SHANI_CXXFLAGS)
crypto_libreptiloidscoin_crypto_shani_a_CPPFLAGS += -DENABLE_SHANI
crypto_libreptiloidscoin_crypto_shani_a_SOURCES = crypto/sha256_shani.cpp

# consensus: shared between all executables that validate any consensus rules.
libreptiloidscoin_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
libreptiloidscoin_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libreptiloidscoin_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/reptiloidscoinconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  span.h \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  util/strencodings.cpp \
  util/strencodings.h \
  version.h

# common: shared between reptiloidscoind, and reptiloidscoin-qt and non-server tools
libreptiloidscoin_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
libreptiloidscoin_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libreptiloidscoin_common_a_SOURCES = \
  base58.cpp \
  bech32.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  core_read.cpp \
  core_write.cpp \
  key.cpp \
  key_io.cpp \
  keystore.cpp \
  netaddress.cpp \
  netbase.cpp \
  policy/feerate.cpp \
  psbt.cpp \
  protocol.cpp \
  scheduler.cpp \
  script/descriptor.cpp \
  script/ismine.cpp \
  script/sign.cpp \
  script/standard.cpp \
  versionbitsinfo.cpp \
  warnings.cpp \
  $(REPTILOIDSCOIN_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libreptiloidscoin_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
libreptiloidscoin_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libreptiloidscoin_util_a_SOURCES = \
  support/lockedpool.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  logging.cpp \
  random.cpp \
  rpc/protocol.cpp \
  support/cleanse.cpp \
  sync.cpp \
  threadinterrupt.cpp \
  util/bip32.cpp \
  util/bytevectorhash.cpp \
  util/system.cpp \
  util/moneystr.cpp \
  util/strencodings.cpp \
  util/time.cpp \
  $(REPTILOIDSCOIN_CORE_H)

if GLIBC_BACK_COMPAT
libreptiloidscoin_util_a_SOURCES += compat/glibc_compat.cpp
AM_LDFLAGS += $(COMPAT_LDFLAGS)
endif

# cli: shared between reptiloidscoin-cli and reptiloidscoin-qt
libreptiloidscoin_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
libreptiloidscoin_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libreptiloidscoin_cli_a_SOURCES = \
  rpc/client.cpp \
  $(REPTILOIDSCOIN_CORE_H)

nodist_libreptiloidscoin_util_a_SOURCES = $(srcdir)/obj/build.h
#

# reptiloidscoind binary #
reptiloidscoind_SOURCES = reptiloidscoind.cpp
reptiloidscoind_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
reptiloidscoind_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
reptiloidscoind_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
reptiloidscoind_SOURCES += reptiloidscoind-res.rc
endif

reptiloidscoind_LDADD = \
  $(LIBREPTILOIDSCOIN_SERVER) \
  $(LIBREPTILOIDSCOIN_WALLET) \
  $(LIBREPTILOIDSCOIN_SERVER) \
  $(LIBREPTILOIDSCOIN_COMMON) \
  $(LIBUNIVALUE) \
  $(LIBREPTILOIDSCOIN_UTIL) \
  $(LIBREPTILOIDSCOIN_ZMQ) \
  $(LIBREPTILOIDSCOIN_CONSENSUS) \
  $(LIBREPTILOIDSCOIN_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

reptiloidscoind_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS)

# reptiloidscoin-cli binary #
reptiloidscoin_cli_SOURCES = reptiloidscoin-cli.cpp
reptiloidscoin_cli_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES) $(EVENT_CFLAGS)
reptiloidscoin_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
reptiloidscoin_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
reptiloidscoin_cli_SOURCES += reptiloidscoin-cli-res.rc
endif

reptiloidscoin_cli_LDADD = \
  $(LIBREPTILOIDSCOIN_CLI) \
  $(LIBUNIVALUE) \
  $(LIBREPTILOIDSCOIN_UTIL) \
  $(LIBREPTILOIDSCOIN_CRYPTO)

reptiloidscoin_cli_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# reptiloidscoin-tx binary #
reptiloidscoin_tx_SOURCES = reptiloidscoin-tx.cpp
reptiloidscoin_tx_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
reptiloidscoin_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
reptiloidscoin_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
reptiloidscoin_tx_SOURCES += reptiloidscoin-tx-res.rc
endif

reptiloidscoin_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBREPTILOIDSCOIN_COMMON) \
  $(LIBREPTILOIDSCOIN_UTIL) \
  $(LIBREPTILOIDSCOIN_CONSENSUS) \
  $(LIBREPTILOIDSCOIN_CRYPTO) \
  $(LIBSECP256K1)

reptiloidscoin_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# reptiloidscoin-wallet binary #
reptiloidscoin_wallet_SOURCES = reptiloidscoin-wallet.cpp
reptiloidscoin_wallet_CPPFLAGS = $(AM_CPPFLAGS) $(REPTILOIDSCOIN_INCLUDES)
reptiloidscoin_wallet_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
reptiloidscoin_wallet_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
reptiloidscoin_wallet_SOURCES += reptiloidscoin-wallet-res.rc
endif

reptiloidscoin_wallet_LDADD = \
  $(LIBREPTILOIDSCOIN_WALLET_TOOL) \
  $(LIBREPTILOIDSCOIN_WALLET) \
  $(LIBREPTILOIDSCOIN_SERVER) \
  $(LIBREPTILOIDSCOIN_COMMON) \
  $(LIBREPTILOIDSCOIN_CONSENSUS) \
  $(LIBREPTILOIDSCOIN_UTIL) \
  $(LIBREPTILOIDSCOIN_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

reptiloidscoin_wallet_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS)
#

# reptiloidscoinconsensus library #
if BUILD_REPTILOIDSCOIN_LIBS
include_HEADERS = script/reptiloidscoinconsensus.h
libreptiloidscoinconsensus_la_SOURCES = $(crypto_libreptiloidscoin_crypto_base_a_SOURCES) $(libreptiloidscoin_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  libreptiloidscoinconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

libreptiloidscoinconsensus_la_LDFLAGS = $(AM_LDFLAGS) -no-undefined $(RELDFLAGS)
libreptiloidscoinconsensus_la_LIBADD = $(LIBSECP256K1)
libreptiloidscoinconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_REPTILOIDSCOIN_INTERNAL
libreptiloidscoinconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES = $(EXTRA_LIBRARIES)

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno
CLEANFILES += obj/build.h

EXTRA_DIST = $(CTAES_DIST)


config/reptiloidscoin-config.h: config/stamp-h1
	@$(MAKE) -C $(top_builddir) $(subdir)/$(@)
config/stamp-h1: $(top_srcdir)/$(subdir)/config/reptiloidscoin-config.h.in $(top_builddir)/config.status
	$(AM_V_at)$(MAKE) -C $(top_builddir) $(subdir)/$(@)
$(top_srcdir)/$(subdir)/config/reptiloidscoin-config.h.in:  $(am__configure_deps)
	$(AM_V_at)$(MAKE) -C $(top_srcdir) $(subdir)/config/reptiloidscoin-config.h.in

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config.h
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

check-symbols: $(bin_PROGRAMS)
if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) READELF=$(READELF) CPPFILT=$(CPPFILT) $(top_srcdir)/contrib/devtools/symbol-check.py < $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) READELF=$(READELF) OBJDUMP=$(OBJDUMP) $(top_srcdir)/contrib/devtools/security-check.py < $(bin_PROGRAMS)
endif

if ENABLE_BIP70
%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(<D) $<
endif

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
